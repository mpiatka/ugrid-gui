#ifndef PREVIEWWIDGET_HPP
#define PREVIEWWIDGET_HPP

#include <QOpenGLWidget>

class PreviewWidget : public QOpenGLWidget{
public:
	PreviewWidget(QWidget *parent) : QOpenGLWidget(parent) {  }

protected:
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();
};

#endif
