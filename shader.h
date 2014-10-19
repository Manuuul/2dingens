#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL_image.h>

GLuint build_shader(GLenum, char *);
//Kompiliert einen GLSL Shader
//Gibt die Shader ID zurück
//TODO: Quelltext wird nicht wieder Freigegeben

GLuint link_program(GLuint, GLuint, char *);
//Verlinkt Vertex Shader und Fragment Shader zu GLSL Programm
//Gibt Programm ID zurück

GLuint create_rect(int, int);
//Erstellt Buffer mit einem Rechteck von (0,0) bis (w,h)
//Gibt Buffer ID zurück

GLuint create_texture(char *);
//Lädt Bild und Speichert es GraKa
//Macht es zur Aktuellen Textur
//Gibt Textur ID zurück
//TODO: Textur wird nicht wieder Freigegeben

#endif // SHADER_H_INCLUDED
