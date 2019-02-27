#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
int main( int argc, char *argv[] )
 {

SDL_Surface *ecran = NULL, *background = NULL,*play=NULL,*option=NULL,*quit=NULL, *play2=NULL,*option2=NULL,*quit2=NULL,*im=NULL,*Menu_anime[256];
SDL_Event event;
background=IMG_Load("Mood.png");
SDL_Rect  posbackground,posplay,possetting,posquit,posplay2,possetting2,posquit2;
posbackground.x=0;
posbackground.y=0;
background=IMG_Load("Mood.png");
ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
SDL_BlitSurface(background,NULL,ecran,&posbackground);
SDL_Flip(ecran);
play=IMG_Load("play.png");
play2=IMG_Load("play2.png");
option=IMG_Load("option.png");
option2=IMG_Load("option2.png");
quit=IMG_Load("Quit.png");
quit2=IMG_Load("Quit2.png");
int audio_rate = 45000;
	Uint16 audio_format = AUDIO_S16; /* 16-bit stereo */
	int audio_channels = 1;
	int audio_buffers = 4096;
if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) < 0) {
	    printf("Unable to open audio!\n");
	    exit(1);
		}
Mix_Music *song=NULL, *song1=NULL;
Mix_VolumeMusic(MIX_MAX_VOLUME);
                song=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(song, MIX_MAX_VOLUME);
Mix_Music *musique;
Mix_Chunk *ding;

     
int curseur=1,continuer=1,m=0,i,fix=0;
     char menu[40];

while(continuer)
{
posbackground.x=0;
posbackground.y=0;
posplay.x=30;
posplay.y=100;
possetting.x=30;
possetting.y=170;
posquit.x=30;
posquit.y=240;
posplay2.x=30;
posplay2.y=100;
possetting2.x=30;
possetting2.y=170;
posquit2.x=30;
posquit2.y=240;
SDL_BlitSurface(play,NULL,ecran,&posplay);
SDL_BlitSurface(option,NULL,ecran,&possetting);
SDL_BlitSurface(quit,NULL,ecran,&posquit);
SDL_Flip(ecran);

SDL_Init( SDL_INIT_VIDEO ); 
ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE );
     SDL_WM_SetCaption("Time Machine", NULL);


 if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) 
     {
    	printf("%s", Mix_GetError());
     }
 
     musique = Mix_LoadMUS("music.mp3");
     Mix_PlayMusic(musique, -1);
 for (i=0; i<=35; i++)
     {
     	sprintf(menu,"%d.png",i);
        Menu_anime[i]=IMG_Load(menu);
        SDL_BlitSurface(Menu_anime[i],NULL,ecran,&posbackground);
        SDL_Flip(ecran);
        SDL_Delay(20);
     }

play= IMG_Load("play.png");
option= IMG_Load("option.png");
quit = IMG_Load ("quit.png" ) ; 

 for (i=0; i<=35; i++)
    {
        sprintf(menu,"%d.png",i);
        Menu_anime[i]=IMG_Load(menu);
        
    }
    while (continuer!=0)
    {
	if (curseur>3)
		curseur=1;
	if (curseur<1)
		curseur=3;
	if (i>35) i=1;
	sprintf(menu,"%d.png",i);
    SDL_BlitSurface(Menu_anime[i],NULL,ecran,&posbackground); 
    SDL_Delay(100);
    i++;
while (SDL_PollEvent(&event))
	{
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYUP:
                fix=0;
			break;
case SDL_KEYDOWN:
				if(!fix)
				{
             switch(event.key.keysym.sym)
                {
                    case SDLK_UP: 
			curseur--;
			Mix_PlayChannel(-1, ding, 0);
                    break;
                    case SDLK_DOWN: 
			curseur++;
			Mix_PlayChannel(-1, ding, 0);
                    break;
		    case SDLK_KP_ENTER:
			if (curseur==4)
			{
			Mix_PlayChannel(-1, ding, 0);
			continuer = 0;
			}
                    break;
			fix=1;
			}
                }
            break;
case SDL_MOUSEMOTION:
            	{//SDL_MOUSEMOTION
            	if
 ((event.motion.x>posplay.x )&&(event.motion.x<posplay.x+posplay.w)&&(event.motion.y>posplay.y)&&(event.motion.y<posplay.y+posplay.h))
            	{//loading 2eme button play
            		curseur=1;
play2=IMG_Load("play2.png"); 
}
            	if ((event.motion.x>possetting.x)&&(event.motion.x<possetting.x+possetting.w)&&(event.motion.y>possetting.y)&&(event.motion.y<possetting.y+possetting.h))
            	{
            		curseur=2;
option2=IMG_Load("option2.png");
}
            	
            	if ((event.motion.x>posquit.x)&&(event.motion.x<posquit.x+posquit.w)&&(event.motion.y>posquit.y)&&(event.motion.y<posquit.y+posquit.h))
            	{
            		curseur=3;
quit2=IMG_Load("Quit2.png");

            	}

}
 case SDL_MOUSEBUTTONUP:
{
        if ((event.button.button == SDL_BUTTON_LEFT)&&(curseur==3))
     {
      continuer=0;
     }
        
        if ((event.button.button == SDL_BUTTON_LEFT)&&(curseur==2))
      {
      continuer=0;
     }
    if ((event.button.button == SDL_BUTTON_LEFT)&&(curseur==1))
      {
      continuer=0;
     }
    
}
        }
	}
if (curseur==1)
	{
		
		
		SDL_BlitSurface(option, NULL, ecran, &possetting);
		SDL_BlitSurface(quit, NULL, ecran, &posquit);
    	        SDL_BlitSurface(play2, NULL, ecran, &posplay2);

	}
if (curseur==2)
	{
		
		SDL_BlitSurface(play, NULL, ecran, &posplay);
		SDL_BlitSurface(quit, NULL, ecran, &posquit);
		SDL_BlitSurface(option2, NULL, ecran, &possetting2);
    }
if (curseur==3)
	{
		
		SDL_BlitSurface(play, NULL, ecran, &posplay);
		SDL_BlitSurface(option, NULL, ecran, &possetting);
		SDL_BlitSurface(quit2, NULL, ecran, &posquit2);
    	
	}


SDL_Flip(ecran);
} 
   }
    Mix_FreeMusic(musique);
    Mix_FreeChunk(ding);
    Mix_CloseAudio();
    SDL_FreeSurface(background);
    SDL_Quit();
 
    return EXIT_SUCCESS;




}
