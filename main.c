#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include "shader.h"
#include "window.h"
#include "util.h"
#include <SDL2/SDL_image.h>
//
//TODO: //Koordinaten auf uint umstellen
//      Attribute in Funktion packen
//      Transparenz
//      Mehr als eine Textur hinkriegen
int main(){
    int win_width = 600;
    int win_height = 400;
    SDL_Window *window = create_window("Integerkoordinatentestanwendungsprogramm", win_width, win_height);

    create_texture("gl.png");
    create_rect(300, 200);


    //Shader
    char *vshsource = read_file("vertex.glsl");
    GLuint vshader = build_shader(GL_VERTEX_SHADER, vshsource);
    char *fshsource = read_file("fragment.glsl");
    GLuint fshader = build_shader(GL_FRAGMENT_SHADER, fshsource);
    GLuint sprog = link_program(vshader, fshader);

    GLint posAttrib = glGetAttribLocation(sprog, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 4*sizeof(int), 0);

    GLint texAttrib = glGetAttribLocation(sprog, "texcoord");
    glEnableVertexAttribArray(texAttrib);
    glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 4*sizeof(int),(void *) (2*sizeof(int)));

    glUniform2i(glGetUniformLocation(sprog, "resolution"), win_width, win_height);

    int quit = 0;
    while (!quit){

        SDL_Event ev;
        while(SDL_PollEvent(&ev)){
            switch(ev.type){
                case SDL_KEYDOWN:
                    switch(ev.key.keysym.sym){
                        case SDLK_RETURN:
                        quit = 1;
                        break;
                    }
                    break;
                case SDL_QUIT:
                    quit = 1;
                    break;
            }
        }

        //Rendern
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        SDL_GL_SwapWindow(window);
    }

    return 0;
}
