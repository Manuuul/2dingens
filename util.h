#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/gl.h>

char *read_file(char *);

void check_error(char *);
//Liest letzten OpenGL Error aus
//Beschreibt Stelle und Fehlertyp

#endif // UTIL_H_INCLUDED
