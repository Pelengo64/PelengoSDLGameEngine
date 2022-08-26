#pragma once
#include"GameObject.h"
#include"SDL_Utils.h"
#include "math.h"

class testObject : public GameObject{
    
    public:
    testObject(Vector3 position, Vector3 rotation, Vector3 scale, SDL_Renderer* renderer, std::string tag, SDL_Texture* texture,KeyInput *keyInput) : GameObject(position, rotation, scale, texture, tag,keyInput){}
    /*int speed = 3;
    int speedMod = 1;
    void tick() override {

        if(keyInput->isKeyDown(SDL_SCANCODE_W)){
            position.y -= speed*speedMod;
        }
        if(keyInput->isKeyDown(SDL_SCANCODE_S)){
            position.y += speed*speedMod;
        }
        if(keyInput->isKeyDown(SDL_SCANCODE_A)){
            position.x -= speed*speedMod;
        }
        if(keyInput->isKeyDown(SDL_SCANCODE_D)){
            position.x += speed*speedMod;
        }
        if(keyInput->isKeyDown(SDL_SCANCODE_LEFT)){
            scale.x -= speed*speedMod;
        }
        if(keyInput->isKeyDown(SDL_SCANCODE_RIGHT)){
            scale.x += speed*speedMod;
        }
        if(keyInput->isKeyDown(SDL_SCANCODE_UP)){
            scale.y -= speed*speedMod;
        }
        if(keyInput->isKeyDown(SDL_SCANCODE_DOWN)){
            scale.y += speed*speedMod;
        }
        if(keyInput->isKeyDown(SDL_SCANCODE_LSHIFT)){
            speedMod = 2;
        }
        else{
            speedMod = 1;
        }
        
    };*/
    int i = 0;
    int speed = 8;
    bool started = false;
    int velX = 0;
    int velY = 0;
    void tick() override {
        if (!started) {
            started = true;
            i = 0;
            velX = getXDirection() / 25;
            velY = getYDirection() / 25;
        }
        //Move in circle
        position.x += velX + cos(i * M_PI / 180) * speed;
        position.y += velY + sin(i * M_PI / 180) * speed;


        i += speed;
    };
    int getXDirection() {
        return 320 - position.x;
    }
    int getYDirection() {
        return 240 - position.y;
    }
};
