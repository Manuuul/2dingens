#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

typedef struct{
    unsigned int texture; //Provisorisch, wird zu spritesheet
    int x,
        y,
        w,
        h;
} e_Sprite;

void e_SpriteDraw(e_Sprite *);
e_Sprite e_SpriteCreate(int, int, int, int, int);


#endif // SPRITE_H_INCLUDED
