#ifndef KEYINPUT_H
#define KEYINPUT_H
#include<SDL.h>
#include<vector>

class KeyInput{
    public:
    KeyInput();
    bool isKeyDown(SDL_Scancode key);
    bool isKeyPressed(SDL_Scancode key);
    bool isKeyReleased(SDL_Scancode key);

    void update();
    void pressKey(SDL_Scancode key);
    void releaseKey(SDL_Scancode key);
    private:
    std::vector<bool> keys;
    std::vector<bool> prevKeys;



};
#endif // KEYINPUT_H