#ifndef ULTRAGRID_OPTION_HPP
#define ULTRAGRID_OPTION_HPP

#include <QString>
#include <QObject>

class QComboBox;

class UltragridOption : public QObject{
public:
	virtual QString getLaunchParam() = 0;
	virtual void queryAvailOpts() = 0;

protected:
	QStringList getAvailOpts(const QString &executable,
			const QString &helpCommand);

	void resetComboBox(QComboBox *box);

private:

};

class SourceOption : public UltragridOption{
	Q_OBJECT
public:
	SourceOption() = default;

	SourceOption(QComboBox *src,
			QComboBox *mode,
			QString ultragridExecutable);

	void setSrcBox(QComboBox *src) { this->src = src; }
	void setModeBox(QComboBox *mode) { this->mode = mode; }
	void setExecutable(const QString &executable) { ultragridExecutable = executable; }


	QString getLaunchParam() override;
	void queryAvailOpts() override;
private:
	QComboBox *src;
	QComboBox *mode;
	QString ultragridExecutable;

private slots:
	void srcChanged();
};

class DisplayOption : public UltragridOption{
public:
	DisplayOption() = default;

	DisplayOption(QComboBox *disp,
			QString ultragridExecutable);

	void setExecutable(const QString &executable) { ultragridExecutable = executable; }

	QString getLaunchParam() override;
	void queryAvailOpts() override;
private:
	QComboBox *disp;
	QString ultragridExecutable;
};

class GenericOption : public UltragridOption{
public:
	GenericOption() = default;

	GenericOption(QComboBox *box,
			QString ultragridExecutable,
			QString opt);

	void setExecutable(const QString &executable) { ultragridExecutable = executable; }

	QString getLaunchParam() override;
	void queryAvailOpts() override;
private:
	QComboBox *box;
	QString ultragridExecutable;
	QString opt;
};

#endif
