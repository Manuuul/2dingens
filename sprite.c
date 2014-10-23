#include "main.h"
void e_SpriteDraw(e_Sprite *sprite){
    glUniform4i(glGetUniformLocation(e_GLInfo.shaderID, "RectDimension"), sprite->x, sprite->y, sprite->w, sprite->h);
    glBindTexture(GL_TEXTURE_2D, sprite->texture);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

e_Sprite e_SpriteCreate(int x, int y, int w, int h, int texture){
    e_Sprite Sprite;
    Sprite.x = x;
    Sprite.y = y;
    Sprite.w = w;
    Sprite.h = h;
    Sprite.texture = texture;
    return Sprite;
}

