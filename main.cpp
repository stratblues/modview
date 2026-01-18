//#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h> 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


SDL_Window* window;
SDL_GPUDevice* device;

static int gameRunning;

int initWindow()
{
	gameRunning = 1;
 	window = SDL_CreateWindow("Hello, Triangle!", 960, 540, SDL_WINDOW_RESIZABLE);
	if(window == NULL)
	{
		//TODO: add logging
		return NULL;
	}
        device = SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_SPIRV, false, NULL);
	if(device == NULL)
	{
		return NULL;
	}

        SDL_ClaimWindowForGPUDevice(device, window);	

}


int main
()
{
	initWindow();
	while(gameRunning)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_EVENT_QUIT:
					SDL_Log("quit event");
					gameRunning = 0;
					break;
			}
		}

	}
	    	
    	return 0;
}

