#include"KeyInput.h"

bool KeyInput::isKeyDown(SDL_Scancode key){
    return keys[key];
}
bool KeyInput::isKeyPressed(SDL_Scancode key){
    return keys[key] && !prevKeys[key];
}
bool KeyInput::isKeyReleased(SDL_Scancode key){
    return !keys[key] && prevKeys[key];
}
KeyInput::KeyInput(){
    for(int i = 0; i < SDL_NUM_SCANCODES; i++){
        keys.push_back(false);
        prevKeys.push_back(false);
    }
}
void KeyInput::update(){
    for(int i = 0; i < SDL_NUM_SCANCODES; i++){
        prevKeys[i] = keys[i];
    }
}
void KeyInput::pressKey(SDL_Scancode key){
    keys[key] = true;
}
void KeyInput::releaseKey(SDL_Scancode key){
    keys[key] = false;
}