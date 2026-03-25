#include <draw.h>

typedef void (*Func)(GladGLContext*);
void draw_to(GLFWwindow *window, GladGLContext *context, const Func f) {
    f(context);
    glfwSwapBuffers(window);
}

void draw_main(GladGLContext *gl) {
    gl->ClearColor(0.5f, 0.1f, 0.2f, 1.0f);
    gl->Clear(GL_COLOR_BUFFER_BIT);
}