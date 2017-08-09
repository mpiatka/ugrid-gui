#ifndef ULTRAGRID_OPTION_HPP
#define ULTRAGRID_OPTION_HPP

#include <QString>
#include <QObject>
#include "ui_ultragrid_window.h"

class QComboBox;
class QLineEdit;
class QLabel;

class UltragridWindow;

class UltragridOption : public QObject{
	Q_OBJECT
public:
	virtual QString getLaunchParam() = 0;
	virtual void queryAvailOpts() = 0;

	void setExecutable(const QString &executable) { ultragridExecutable = executable; }
	virtual void setAdvanced(bool advanced) { this->advanced = advanced; }

signals:
	void changed();

protected:
	UltragridOption(const QString& ultragridExecutable,
			const QString& opt) :
		ultragridExecutable(ultragridExecutable),
		opt(opt),
		advanced(false) {  }

	QStringList getAvailOpts(const QString& executable,
			const QString& helpCommand);

	void resetComboBox(QComboBox *box);

	QString ultragridExecutable;
	QString opt;
	bool advanced;

private:

};

class SourceOption : public UltragridOption{
	Q_OBJECT
public:

	SourceOption(QComboBox *src,
			QComboBox *mode,
			const QString& ultragridExecutable);

	void setSrcBox(QComboBox *src) { this->src = src; }
	void setModeBox(QComboBox *mode) { this->mode = mode; }

	QString getLaunchParam() override;
	void queryAvailOpts() override;
private:
	QComboBox *src;
	QComboBox *mode;

	const static QStringList whiteList;

private slots:
	void srcChanged();
};

class DisplayOption : public UltragridOption{
public:
	DisplayOption(QComboBox *disp,
			const QString& ultragridExecutable);

	QString getLaunchParam() override;
	void queryAvailOpts() override;
private:
	QComboBox *disp;

	const static QStringList whiteList;
};

class CompressOption : public UltragridOption{
	Q_OBJECT
public:
	CompressOption(QComboBox *compress,
			QLineEdit *bitrate,
			QLabel *label,
			const QString& ultragridExecutable);

	QString getLaunchParam() override;
	void queryAvailOpts() override;
private:
	QComboBox *comp;
	QLineEdit *bitrate;
	QLabel *label;

private slots:
	void compChanged();
};

class GenericOption : public UltragridOption{
public:
	GenericOption(QComboBox *box,
			const QString& ultragridExecutable,
			QString opt);

	QString getLaunchParam() override;
	void queryAvailOpts() override;
private:
	QComboBox *box;
};

class FecOption : public UltragridOption{
	Q_OBJECT
public:
	FecOption(Ui::UltragridWindow *ui);

	QString getLaunchParam() override;
	void queryAvailOpts() override {  }

	void setAdvanced(bool advanced) override {
		this->advanced = advanced;
		update();
	}

private:
	Ui::UltragridWindow *ui;

private slots:
	void update();
};

#endif
