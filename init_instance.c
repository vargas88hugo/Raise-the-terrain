#include "raise.h"

/**
 * init_instance - function that initializes the SDL program
 * @instance: SDL instance
 * Return: Return 0 on success or -1 if it fails
 */
int init_instance(SDL_Instance *instance)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return (1);
	}

	instance->window = SDL_CreateWindow(
		"SDL2 \\o/",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		S_WIDTH,
		S_HEIGHT,
		0
		);

	if (instance->window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	instance->renderer = SDL_CreateRenderer(instance->window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (instance->renderer == NULL)
	{
		SDL_DestroyWindow(instance->window);
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	return (0);
}
