#ifndef ULTRAGRID_OPTION_HPP
#define ULTRAGRID_OPTION_HPP

#include <QString>
#include <QObject>

class QComboBox;
class QLineEdit;
class QLabel;

class UltragridOption : public QObject{
public:
	virtual QString getLaunchParam() = 0;
	virtual void queryAvailOpts() = 0;

	void setExecutable(const QString &executable) { ultragridExecutable = executable; }
	void setAdvanced(bool advanced) { this->advanced = advanced; }

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

#endif
