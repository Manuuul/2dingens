
#include "shader.h"
GLuint build_shader(GLenum type, char *source){
    const GLchar *GLsource = (const GLchar*) source;
    GLuint shader = glCreateShader(type);
    GLint shader_success = GL_TRUE;

    glShaderSource(shader, 1, &GLsource, NULL);
    glCompileShader(shader);
    check_error("build_shader");
    glGetShaderiv(shader, GL_COMPILE_STATUS, &shader_success);
    if(shader_success == GL_FALSE){
        printf("Fehler in Shader ID %d (%s)\n", shader, type==GL_VERTEX_SHADER?"Vertex Shader":
                                                        type==GL_FRAGMENT_SHADER?"Fragment Shader":
                                                        "Unbekannter Shader Typ");
    }
    return shader;
}

GLuint link_program(GLuint vertex_shader, GLuint fragment_shader){
    GLuint program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    glUseProgram(program);
    check_error("link_program");
    return program;
}

GLuint create_texture(char *path){
    SDL_Surface *img = IMG_Load(path);
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, img->pixels);
    check_error("create_texture");
    return tex;
}

GLuint create_rect(int w, int h){
    //Vertexdaten
    int vertices[] = {
        0, 0, 0, 0,
        w, 0, 1, 0,
        w, h, 1, 1,
        0, h, 0, 1
    };
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    check_error("create_rect");
    return vbo;
}
