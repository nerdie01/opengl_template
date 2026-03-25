#ifndef UTIL_DRAW
#define UTIL_DRAW

#include <glad/gl.h>
#include <GLFW/glfw3.h>

typedef void (*Func)(GladGLContext*);
void draw_to(GLFWwindow *window, GladGLContext *context, const Func f);

void draw_main(GladGLContext *gl);

#endif