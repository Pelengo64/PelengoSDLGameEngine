#pragma once
#include"Vector3.h"
#include<SDL.h>
#include<string>
#include"KeyInput.h"

class GameObject{
	public:
	
	virtual void tick() = 0;
	std::string tag;
	Vector3 position = Vector3(0,0,0);
	Vector3 rotation = Vector3(0,0,0);
	Vector3 scale = Vector3(1,1,1);
	SDL_Texture* texture;
	Vector3 color = Vector3(255,255,255);
	KeyInput *keyInput;
	GameObject(Vector3 position, Vector3 rotation, Vector3 scale, SDL_Texture* texture, std::string tag,KeyInput *keyInput){
		this->position = position;
		this->rotation = rotation;
		this->scale = scale;
		this->tag = tag;
		this->texture = texture;
		this->keyInput = keyInput;
	};
};

/*
class GameObject
{
public:
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;
	std::string tag;
	SDL_Texture* texture;
	
	virtual void tick();
protected:
	void loadTexture(std::string path, SDL_Renderer* renderer){
		SDL_Surface* image = SDL_LoadBMP(path.c_str());
		texture = SDL_CreateTextureFromSurface(renderer,image);
		SDL_FreeSurface(image);
	}
};
*/