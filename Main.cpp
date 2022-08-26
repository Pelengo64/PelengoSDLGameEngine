#include <stdio.h>
#include <SDL.h>
#include "EntityHandler.h"
#include "testObject.h"
#include<time.h>
#include<random>
#include<list>
#include<vector>
#include"SDL_Utils.h"
#include"KeyInput.h"
int width = 640;
int height = 480;

EntityHandler entityHandler;

int main(int, char**) {
    //Seed random
    srand(time(NULL));
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Failed to initialize the SDL2 library\n");
        return -1;
    }
    KeyInput keyInput = KeyInput();

    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    SDL_Window* window = SDL_CreateWindow("Pelengo Game Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width, height,
        0);
    //Make window fullscreen
    //SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    if (!window)
    {
        printf("Failed to create window\n");
        return -1;
    }
    entityHandler.screenWidth = width;
    entityHandler.screenHeight = height;
    SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);    
    //Create testObject
    SDL_Texture* texture = loadTextureFromBMP("Player.bmp", renderer);
    //GameObject obj = GameObject({0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f},renderer,"test");
    //testObject obj1 = testObject({(float)(rand() % width),(float)(rand() % height),0.0f},{0.0f,0.0f,0.0f},{64.0f,64.0f,64.0f},renderer,"testObject",texture,&keyInput);
    for (int i = 0; i < 1000000; i++) {
        testObject* toAdd = new testObject({ (float)(rand() % width),(float)(rand() % height),0.0f }, { 0.0f,0.0f,0.0f }, { 2.0f,2.0f,2.0f }, renderer, "testObject", texture, &keyInput);
        toAdd->color = Vector3((float)(rand() % 255), (float)(rand() % 255), (float)(rand() % 255));
        toAdd->speed = (rand() % 12) + 1;
        entityHandler.addEntity(toAdd);

    }
    
    
    
    
    SDL_Surface* window_surface = SDL_GetWindowSurface(window);
    bool running = true;
    SDL_Event e;
   
    SDL_Rect clearRect = SDL_Rect();
    clearRect.x=0;
    clearRect.y=0;
    clearRect.w=width;
    clearRect.h=height;
    while (running) {
        while (SDL_PollEvent(&e) > 0)
        {
            switch (e.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                keyInput.pressKey(e.key.keysym.scancode);
                //keyInput.update();
                break;
            
            case SDL_KEYUP:
                keyInput.releaseKey(e.key.keysym.scancode);
                //keyInput.update();
                break;
            }
        }
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_FillRect(window_surface,&clearRect,0);
	//printf("%i",obj.position.x);
    entityHandler.tick();

	SDL_RenderClear(renderer);
	
    entityHandler.render(renderer);
	
    SDL_RenderPresent(renderer);
	//SDL_BlitSurface(image,NULL,window_surface,&out);
        //SDL_UpdateWindowSurface(window);
    }
    SDL_FreeSurface(window_surface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    //Clean up all entities
    for(GameObject* entity : entityHandler.entities)
    {
        SDL_DestroyTexture(entity->texture);
    }
    return 0;
}
