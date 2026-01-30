//#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h> 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>



static SDL_Window* window = nullptr;
static SDL_GPUDevice* device = nullptr;
static int gameRunning = 0;

int initWindow()
{
	
	
	if(SDL_Init(SDL_INIT_VIDEO) == 0)
	{
		SDL_Log("SDL_Init failed: %s", SDL_GetError());
        	return 0;
	}
	gameRunning = 1;
 	window = SDL_CreateWindow("Hello, Triangle!", 960, 540, SDL_WINDOW_RESIZABLE);
	if(window == nullptr)
	{
		SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
		return 0;
	}

        device = SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_SPIRV, true, nullptr);
	if(device == nullptr)
	{
		SDL_Log("SDL_CreateDevice failed: %s", SDL_GetError());
		return 0;
	}

        SDL_ClaimWindowForGPUDevice(device, window);	
	return 1;
}


int main
()
{
	if(initWindow() == 0)
	{
		return 1;
	}
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
	SDL_DestroyGPUDevice(device);
    	SDL_DestroyWindow(window);
    	SDL_Quit();
    	return 0;
}












