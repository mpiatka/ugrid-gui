#include <stdio.h>
#include "previewWidget.hpp"

static const GLfloat rectangle[] = {
	 1.0f,  1.0f,  1.0f,  1.0f,
	-1.0f,  1.0f,  0.0f,  1.0f,
	-1.0f, -1.0f,  0.0f,  0.0f,

	 1.0f,  1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f,  0.0f,  0.0f,
	 1.0f, -1.0f,  1.0f,  0.0f
};

static const char *vert_src = R"END(
#version 330 core
layout(location = 0) in vec2 vert_pos;

uniform vec2 scale_vec;

void main(){
	gl_Position = vec4(vert_pos * scale_vec, 0.0f, 1.0f);
}
)END";

static const char *frag_src = R"END(
#version 330 core
out vec3 color;
void main(){
	color = vec3(0, 1, 0);
}
)END";

static void compileShader(GLuint shaderId, QOpenGLFunctions *f){
	f->glCompileShader(shaderId);

	GLint ret = GL_FALSE;
	int len;

	f->glGetShaderiv(shaderId, GL_COMPILE_STATUS, &ret);
	f->glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &len);
	if (len > 0){
		std::vector<char> errorMsg(len+1);
		f->glGetShaderInfoLog(shaderId, len, NULL, &errorMsg[0]);
		printf("%s\n", &errorMsg[0]);
	}
}

void PreviewWidget::initializeGL(){
	QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
	f->glClearColor(1.0f, 1.0f, 0.0f, 1.0f);

	f->glGenBuffers(1, &vertexBuffer);
	f->glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	f->glBufferData(GL_ARRAY_BUFFER, sizeof(rectangle), rectangle, GL_STATIC_DRAW);

	vertexShader = f->glCreateShader(GL_VERTEX_SHADER);
	fragShader = f->glCreateShader(GL_FRAGMENT_SHADER);

	f->glShaderSource(vertexShader, 1, &vert_src, NULL);
	compileShader(vertexShader, f);
	f->glShaderSource(fragShader, 1, &frag_src, NULL);
	compileShader(fragShader, f);

	program = f->glCreateProgram();
	f->glAttachShader(program, vertexShader);
	f->glAttachShader(program, fragShader);
	f->glLinkProgram(program);

	f->glDetachShader(program, vertexShader);
	f->glDetachShader(program, fragShader);
	f->glDeleteShader(vertexShader);
	f->glDeleteShader(fragShader);

	scaleVec[0] = 0.75f;
	scaleVec[1] = 0.5;
}

void PreviewWidget::resizeGL(int w, int h){

}

void PreviewWidget::paintGL(){
	QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
	f->glClear(GL_COLOR_BUFFER_BIT);

	f->glUseProgram(program);

	f->glEnableVertexAttribArray(0);
	f->glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	f->glVertexAttribPointer(
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			4 * sizeof(float),
			(void*)0
			);

	GLuint loc;
	loc = f->glGetUniformLocation(program, "scale_vec");
	f->glUniform2fv(loc, 1, scaleVec);

	f->glDrawArrays(GL_TRIANGLES, 0, 6);
}
