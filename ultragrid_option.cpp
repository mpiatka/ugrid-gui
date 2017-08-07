#include <QStringList>
#include <QProcess>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>

#include <iostream>

#include "ultragrid_option.hpp"
#include "v4l2.hpp"

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

const QStringList SourceOption::whiteList = {"testcard", "screen"};

SourceOption::SourceOption(QComboBox *src,
		QComboBox *mode,
		const QString& ultragridExecutable) :
	UltragridOption(ultragridExecutable, QString("-t")),
	src(src),
	mode(mode)
{
	connect(src, SIGNAL(currentIndexChanged(int)), this, SLOT(srcChanged()));
}

QString SourceOption::getLaunchParam(){
	QString param;

	if(src->currentText() != "none"){
		param += "-t ";
		param += src->currentData().toString();
		param += mode->currentData().toString();
		param += " ";
	}

	return param;
}

void SourceOption::queryAvailOpts(){
	resetComboBox(src);
	QStringList opts = getAvailOpts(ultragridExecutable, QString("-t help"));

	for(const auto& i : opts){
		if(whiteList.contains(i) || advanced){
			src->addItem(i, QVariant(i));
		}
	}

	if(opts.contains(QString("v4l2"))){
		std::vector<Camera> cams = getCameras();
		for(const auto& cam : cams){
			std::cout << cam.name << ": " << cam.path << std::endl;
			QString name = QString::fromStdString(cam.name);
			QString opt = QString::fromStdString("v4l2:device=" + cam.path);
			src->addItem(name, QVariant(opt));
		}
	}
}

void SourceOption::srcChanged(){
	mode->clear();
	mode->addItem(QString("Default"), QVariant(QString("")));

	if(src->currentText() == "testcard"){
		mode->addItem(QString("1280x720, 30 fps"), QVariant(QString(":1280:720:30:UYVY")));
		mode->addItem(QString("1280x720, 24 fps"), QVariant(QString(":1280:720:24:UYVY")));
		mode->addItem(QString("1280x720, 60 fps"), QVariant(QString(":1280:720:60:UYVY")));
		mode->addItem(QString("1920x1080, 30 fps"), QVariant(QString(":1920:1080:30:UYVY")));
		mode->addItem(QString("1920x1080, 24 fps"), QVariant(QString(":1920:1080:24:UYVY")));
		mode->addItem(QString("1920x1080, 60 fps"), QVariant(QString(":1920:1080:60:UYVY")));
		mode->addItem(QString("3840x2160, 30 fps"), QVariant(QString(":3840:2160:30:UYVY")));
		mode->addItem(QString("3840x2160, 24 fps"), QVariant(QString(":3840:2160:24:UYVY")));
		mode->addItem(QString("3840x2160, 60 fps"), QVariant(QString(":3840:2160:60:UYVY")));
	} else if(src->currentText() == "screen"){
		mode->addItem(QString("60 fps"), QVariant(QString(":fps=60")));
		mode->addItem(QString("30 fps"), QVariant(QString(":fps=30")));
		mode->addItem(QString("24 fps"), QVariant(QString(":fps=24")));
	}
}

const QStringList DisplayOption::whiteList = {"gl", "sdl"};

DisplayOption::DisplayOption(QComboBox *disp,
		const QString& ultragridExecutable):
	UltragridOption(ultragridExecutable, QString("-d")),
	disp(disp)
{

}

QString DisplayOption::getLaunchParam(){
	QString param;

	if(disp->currentText() != "none"){
		param += "-d ";
		param += disp->currentText();
		param += " ";
	}

	return param;
}

void DisplayOption::queryAvailOpts(){
	resetComboBox(disp);
	QStringList opts = getAvailOpts(ultragridExecutable, QString("-d help"));

	for(const auto& i : opts){
		if(whiteList.contains(i) || advanced){
			disp->addItem(i);
		}
	}
}

CompressOption::CompressOption(QComboBox *compress,
		QLineEdit *bitrate,
		QLabel *label,
		const QString& ultragridExecutable) :
	UltragridOption(ultragridExecutable, QString("-c")),
	comp(compress),
	bitrate(bitrate),
	label(label)
{
	connect(comp, SIGNAL(currentIndexChanged(int)), this, SLOT(compChanged()));
}

QString CompressOption::getLaunchParam(){
	QString param;

	if(comp->currentText() != "none"){
		param += "-c ";
		param += comp->currentData().toString();
		if(!bitrate->text().isEmpty()){
			if(comp->currentText() == "JPEG"){
				param += ":" + bitrate->text();
			} else {
				param += ":bitrate=" + bitrate->text();
			}
		}
		param += " ";
	}

	return param;
}

void CompressOption::queryAvailOpts(){
	resetComboBox(comp);

	comp->addItem(QString("H.264"), QVariant(QString("libavcodec:codec=H.264")));
	comp->addItem(QString("H.265"), QVariant(QString("libavcodec:codec=H.265")));
	comp->addItem(QString("MJPEG"), QVariant(QString("libavcodec:codec=MJPEG")));
	comp->addItem(QString("VP8"), QVariant(QString("libavcodec:codec=VP8")));
	comp->addItem(QString("JPEG"), QVariant(QString("jpeg")));
}

void CompressOption::compChanged(){
	if(comp->currentText() == "JPEG"){
		label->setText(QString("Jpeg quality"));
	} else {
		label->setText(QString("Bitrate"));
	}
}

GenericOption::GenericOption(QComboBox *box,
		const QString& ultragridExecutable,
		QString opt):
	UltragridOption(ultragridExecutable, opt),
	box(box)
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
	resetComboBox(box);
	QString helpCommand = opt + " help";
	QStringList opts = getAvailOpts(ultragridExecutable, helpCommand);
	box->addItems(opts);
}

void UltragridOption::resetComboBox(QComboBox *box){
	box->clear();
	box->addItem(QString("none"));
}
