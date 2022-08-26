#ifndef SDL_UTILS_H
#define SDL_UTILS_H
#include <SDL.h>
#include <string>
SDL_Texture* loadTextureFromBMP(std::string path, SDL_Renderer* renderer){
	SDL_Surface* image = SDL_LoadBMP(path.c_str());
	SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 0, 0, 0));
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,image);
	SDL_FreeSurface(image);
	return texture;
}
#endif // SDL_UTILS_H