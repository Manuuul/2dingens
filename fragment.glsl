#version 120
varying      vec2 texc;
uniform sampler2D tex;

void main(){
    gl_FragColor = texture2D(tex, texc);
}
