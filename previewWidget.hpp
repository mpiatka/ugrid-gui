#ifndef PREVIEWWIDGET_HPP
#define PREVIEWWIDGET_HPP

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class PreviewWidget : public QOpenGLWidget{
public:
	PreviewWidget(QWidget *parent) : QOpenGLWidget(parent) {  }

protected:
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();

private:
	GLuint vertexBuffer;
	GLuint vertexShader;
	GLuint fragShader;
	GLuint program;

	GLfloat scaleVec[2];
	int vidW, vidH;
	int width, height;
};

#endif
