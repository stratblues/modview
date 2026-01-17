//#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h> 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


SDL_Window* window;
SDL_GPUDevice* device;

int main
()
{
   	window = SDL_CreateWindow("Hello, Triangle!", 960, 540, SDL_WINDOW_RESIZABLE);
	device = SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_SPIRV, false, NULL);
    	
	SDL_ClaimWindowForGPUDevice(device, window);
    	
    	return 0;
}

