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
	ui.terminal->append(process.readAll());
}

void UltragridWindow::start(){
	QString command(ultragridExecutable);
	process.setProcessChannelMode(QProcess::MergedChannels);
	process.start(command);
}
