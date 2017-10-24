#include <QOpenGLFunctions>
#include "previewWidget.hpp"

void PreviewWidget::initializeGL(){
	QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
	f->glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
}

void PreviewWidget::resizeGL(int w, int h){

}

void PreviewWidget::paintGL(){
	QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
	f->glClear(GL_COLOR_BUFFER_BIT);
}
