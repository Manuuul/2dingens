#version 120
attribute ivec2 position;
attribute ivec2 texcoord;
uniform   ivec2 resolution;
varying    vec2 texc;

void main(){
    //Wandle Integer Koordinaten in Float
    vec2 fpos = vec2(position);
    vec2 fres = vec2(resolution);
    texc = vec2(texcoord);
    //Wandle in Koordinaten zwischen -1 und 1
    vec2 pos = (vec2(2.0, -2.0) * vec2(fpos/fres)) - vec2(1.0, -1.0);

    gl_Position = vec4(pos, 0.0, 1.0);
}


