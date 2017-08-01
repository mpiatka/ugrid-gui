#include <QStringList>
#include <QProcess>
#include <QComboBox>

#include "ultragrid_option.hpp"

QStringList UltragridOption::getAvailOpts(const QString &executable,
			const QString &helpCommand)
{
	QStringList out;

	QProcess process;

	QString command = executable;

	command += " ";
	command += helpCommand;

	process.start(command);

	process.waitForFinished();
	QByteArray output = process.readAllStandardOutput();
	QList<QByteArray> lines = output.split('\n');

	foreach ( const QByteArray &line, lines ) {
		if(line.size() > 0 && QChar(line[0]).isSpace()) {
			QString opt = QString(line).trimmed();
			bool append = opt != "none";
			if(opt.startsWith("--")) append = false;
			if(opt.contains("unavailable")) append = false;
			if(append)
				out.append(QString(line).trimmed());
		}
	}

	return out;
}

SourceOption::SourceOption(QComboBox *src,
		QComboBox *mode,
		QString ultragridExecutable) : src(src),
	mode(mode),
	ultragridExecutable(ultragridExecutable)
{

}

QString SourceOption::getLaunchParam(){
	QString param;

	if(src->currentText() != "none"){
		param += "-t ";
		param += src->currentText();
		param += " ";
	}

	return param;
}

void SourceOption::queryAvailOpts(){
	QStringList opts = getAvailOpts(ultragridExecutable, QString("-t help"));
	src->addItems(opts);
}

GenericOption::GenericOption(QComboBox *box,
		QString ultragridExecutable,
		QString opt): box(box),
	ultragridExecutable(ultragridExecutable),
	opt(opt)
{

}

QString GenericOption::getLaunchParam(){
	QString param;

	if(box->currentText() != "none"){
		param += opt;
		param += " ";
		param += box->currentText();
		param += " ";
	}

	return param;
}

void GenericOption::queryAvailOpts(){
	QString helpCommand = opt + " help";
	QStringList opts = getAvailOpts(ultragridExecutable, helpCommand);
	box->addItems(opts);
}
