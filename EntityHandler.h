#ifndef ENTITYHANDLER_H
#define ENTITYHANDLER_H
#include<SDL.h>
#include<list>
#include<string>
#include"GameObject.h"
class EntityHandler{
    public:
	void addEntity(GameObject* obj);
	GameObject* getEntity(std::string tag);
	void tick();
	void render(SDL_Renderer* renderer);
	std::list<GameObject*> entities;
	int screenWidth;
	int screenHeight;
	private:
	SDL_Rect out = SDL_Rect();
};

#endif