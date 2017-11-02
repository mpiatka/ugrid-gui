######################################################################
# Automatically generated by qmake (3.0) Wed Jun 21 13:05:24 2017
######################################################################

TEMPLATE = app
TARGET = ugrid-gui
INCLUDEPATH += .

QT += widgets

CONFIG += c++11

# Input
HEADERS += ultragrid_window.hpp \
ultragrid_option.hpp \
v4l2.hpp \
previewWidget.hpp \
log_window.hpp \

FORMS += ultragrid_window.ui \
log_window.ui

SOURCES += ultragrid_window.cpp \
	ultragrid_option.cpp \
	v4l2.cpp \
	previewWidget.cpp \
	log_window.cpp \
	main.cpp
