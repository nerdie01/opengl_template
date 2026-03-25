#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

// function prototypes
GLFWwindow *create_window(const char *name, int x_size, int y_size, bool resizable);
GladGLContext *create_context(GLFWwindow *window);
void free_context(GladGLContext *context);

void framebuffer_size_callback(GLFWwindow *window, int width, int height);  

// window dimensions
const GLuint X_SIZE = 640, Y_SIZE = 480;

int main() {
    glfwInit();
    
    // create a window
    GLFWwindow *window = create_window("OpenGL Template", X_SIZE, Y_SIZE, true);
    if (window == NULL) {
        std::cout << "Failed to initialize GLFW window\n";
        glfwTerminate();
        return -1;
    }

    // handle input
    // glfwSetKeyCallback(window, key_callback);
    
    // create a glad context
    GladGLContext *context = create_context(window);

    if (context == NULL) {
        std::cout << "Failed to initialize GL context\n";
        free_context(context);
        return -1;
    }

    glfwMakeContextCurrent(window);
    context->Viewport(0, 0, X_SIZE, Y_SIZE);

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    free_context(context);
    glfwTerminate();

    return 0;
}

GLFWwindow *create_window(const char *name, int x_size, int y_size, bool resizable) {
    std::cout << "Creating Window, OpenGL 4.6: " << name << std::endl;

    // set opengl version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, resizable);

    GLFWwindow* window = glfwCreateWindow(x_size, y_size, name, NULL, NULL);
    return window;
}

GladGLContext *create_context(GLFWwindow *window) {
    glfwMakeContextCurrent(window);

    GladGLContext* context = (GladGLContext*) calloc(1, sizeof(GladGLContext));
    if (!context) return NULL;

    int version = gladLoadGLContext(context, glfwGetProcAddress);
    if (version == 0) { free(context); return NULL; }

    return context;
}

void free_context(GladGLContext *context) {
    free(context);
}