#include "scrolling.h"
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include<stdio.h>
#include<stdlib.h>
SDL_Rect AnimationHero(Hero hero)
{
  int i;
  SDL_Rect frame;

    if(hero.etat == WALK_RIGHT)
    {
      i = 0;
        while(i<MAXF)
        {
          frame.x = i*PLAYER_WIDTH;
          frame.y = 0;
          frame.w = PLAYER_WIDTH;
          frame.h = PLAYER_HEIGHT;
          i++;
        }
      if(i = MAXF-1)
        i = 0;
    }
    else if(hero.etat == WALK_LEFT)
    {
      i = MAXF-1;
      while(i>=0)
        {
          frame.x = i*PLAYER_WIDTH;
          frame.y = 0;
          frame.w = PLAYER_WIDTH;
          frame.h = PLAYER_HEIGHT;
          i--;
        }
      if(i < 0)
        i = MAXF-1;
    }
    else if(hero.etat == IMMOBILE)
    {
      if(hero.direction == RIGHT)
      {

        frame.x = 0;
        frame.y = 0;
        frame.w = PLAYER_WIDTH;
        frame.h = PLAYER_HEIGHT;
      }
      else if(hero.direction == LEFT)
      {
        frame.x = MAXF-1;
        frame.y = 0;
        frame.w = PLAYER_WIDTH;
        frame.h = PLAYER_HEIGHT;
      }
    }
  return frame;
}
