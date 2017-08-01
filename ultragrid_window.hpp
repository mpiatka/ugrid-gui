#ifndef ULTRAGRID_WINDOW_HPP
#define ULTRAGRID_WINDOW_HPP

#include <QProcess>
#include <vector>
#include <memory>

#include "ui_ultragrid_window.h"
#include "ultragrid_option.hpp"

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

	std::vector<std::unique_ptr<UltragridOption>> opts;

public slots:
	void about();
	void outputAvailable();
	void start();

	void editArgs(const QString &text);
	void setArgs();
};


#endif
