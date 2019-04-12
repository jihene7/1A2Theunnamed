#include "scrolling.h"
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include<stdio.h>
#include<stdlib.h>
void initialisation(Acteurs* acteurs, SDL_Rect* camera, SDL_Rect* frame)
{
  acteurs->backg = IMG_Load("stage1.jpg");
  camera->x = 0;
  camera->y = 0;
  camera->w = SCREEN_WIDTH;
  camera->h = SCREEN_HEIGHT;

  frame->x = 0;
  frame->y = 0;
  frame->w = PLAYER_WIDTH;
  frame->h = PLAYER_HEIGHT;
}

void centerScrollingOnPlayer(Hero hero, Acteurs* acteurs, SDL_Rect* camera)
{
  if(acteurs->event.type == SDL_KEYDOWN)
  {
    if(acteurs->event.key.keysym.sym == SDLK_RIGHT)
  {
    if((hero.x + PLAYER_WIDTH/2) > SCREEN_WIDTH/2)
      {
        camera->x += PLAYER_SPEED;
      }
    if(camera->x > Backg_W - SCREEN_WIDTH)
      {
        camera->x = Backg_W - SCREEN_WIDTH;
      }
  }
  else if(acteurs->event.key.keysym.sym == SDLK_LEFT)
  {

        camera->x -= PLAYER_SPEED;
    if((hero.x + PLAYER_WIDTH/2) > (Backg_W - SCREEN_WIDTH/2))
    {
      camera->x = Backg_W - SCREEN_WIDTH;
    }

    if(camera->x < 0)
      {
        camera->x = 0;
      }
  }
  }
}

