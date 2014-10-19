
#include "window.h"

SDL_Window *create_window(char *title, int width, int height){
    SDL_Window *window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    SDL_GLContext cont = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, cont);
    SDL_GL_SetSwapInterval(0);
    glewInit();

    //Element Buffer
    GLuint elements[] = {
        0, 1, 2,
        0, 2, 3
    };
    GLuint ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

    return window;
}
