#include <QApplication>

#include "ultragrid_window.hpp"

int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	UltragridWindow uw;
	uw.show();
	return app.exec();
}
