#include "EntityHandler.h"



void EntityHandler::addEntity(GameObject *obj)
{
    this->entities.push_front(obj);
}
void EntityHandler::tick()
{
    for (GameObject *entity : this->entities)
    {
        entity->tick();

    }
}
GameObject *EntityHandler::getEntity(std::string tag)
{
    for (GameObject *entity : this->entities)
    {
        if (entity->tag == tag)
        {
            return entity;
        }
    }
    return nullptr;
    // return GameObject({0,0,0},{0,0,0},{0,0,0},nullptr,"");
}
void EntityHandler::render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0,255,255, 255);
    for (GameObject *entity : this->entities)
    {
        
        /*out.x = entity->position.x;
        out.y=entity->position.y;
        out.w=entity->scale.x;
        out.h=entity->scale.y;
        //SDL_RenderCopy(renderer,entity->texture,NULL,&out);
        SDL_SetRenderDrawColor(renderer, entity->color.x, entity->color.y, entity->color.z,255);*/
        SDL_RenderDrawPoint(renderer, entity->position.x,entity->position.y);
        

    }
}
