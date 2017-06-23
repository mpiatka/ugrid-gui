#include <QMessageBox>

#include "ultragrid_window.hpp"

UltragridWindow::UltragridWindow(QWidget *parent): QMainWindow(parent){
	ui.setupUi(this);

	QStringList args = QCoreApplication::arguments();
	int index = args.indexOf("--with-uv");
	if(index != -1 && args.size() >= index + 1) {
		//found
		ultragridExecutable = args.at(index + 1);
	} else {
		ultragridExecutable = "uv";
	}

	connect(ui.actionAbout_UltraGrid, SIGNAL(triggered()), this, SLOT(about()));
	connect(ui.startButton, SIGNAL(clicked()), this, SLOT(start()));
	connect(&process, SIGNAL(readyReadStandardOutput()), this, SLOT(outputAvailable()));
	connect(&process, SIGNAL(readyReadStandardError()), this, SLOT(outputAvailable()));

	connect(ui.videoSourceComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setArgs()));
	connect(ui.videoDisplayComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setArgs()));
	connect(ui.networkDestinationEdit, SIGNAL(textEdited(const QString &)), this, SLOT(setArgs()));

	connect(ui.arguments, SIGNAL(textChanged(const QString &)), this, SLOT(editArgs(const QString &)));
	connect(ui.editCheckBox, SIGNAL(toggled(bool)), this, SLOT(setArgs()));
	setArgs();
}

void UltragridWindow::about(){
	QMessageBox::about(this,"About UltraGrid",
		"UltraGrid from CESNET is a software "
		"implementation of high-quality low-latency video and audio transmissions using commodity PC and Mac hardware.\n\n"
		"More information can be found at http://www.ultragrid.cz\n\n"
		"Please read documents distributed with the product to find out current and former developers."
		);
}

void UltragridWindow::outputAvailable(){
	//ui.terminal->append(process.readAll());
#if 1
	ui.terminal->moveCursor(QTextCursor::End);
	ui.terminal->insertPlainText(process.readAll());
	ui.terminal->moveCursor(QTextCursor::End);
#endif
}

void UltragridWindow::start(){
	if(process.pid() > 0){
		process.terminate();
		return;
	}

	QString command(ultragridExecutable);

	command += " ";
	command += launchArgs;
	process.setProcessChannelMode(QProcess::MergedChannels);
	process.start(command);
}

void UltragridWindow::editArgs(const QString &text){
	launchArgs = text;
}

void UltragridWindow::setArgs(){
	launchArgs = "";

	if(ui.videoSourceComboBox->currentText() != "none"){
		launchArgs += "-t ";
		launchArgs += ui.videoSourceComboBox->currentText();
		launchArgs += " ";
	}

	if(ui.videoDisplayComboBox->currentText() != "none"){
		launchArgs += "-d ";
		launchArgs += ui.videoDisplayComboBox->currentText();
		launchArgs += " ";
	}

	launchArgs += ui.networkDestinationEdit->text();

	ui.arguments->setText(launchArgs);
}
