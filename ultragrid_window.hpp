#ifndef ULTRAGRID_WINDOW_HPP
#define ULTRAGRID_WINDOW_HPP

#include <QProcess>

#include "ui_ultragrid_window.h"

class UltragridWindow : public QMainWindow{
	Q_OBJECT

public:
	UltragridWindow(QWidget *parent = 0);

private:
	Ui::UltragridWindow ui;

	QString ultragridExecutable;
	QProcess process;

	QString launchArgs;
	QStringList getOptionsForParam(QString param);

public slots:
	void about();
	void outputAvailable();
	void start();

	void editArgs(const QString &text);
	void setArgs();
};


#endif
