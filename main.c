#include "raise.h"

/**
 * main - Entry point of the SDL program that rotates a isometric grid
 * @argc: Number of arguments
 * @argv: Matrix of arguments
 * Return: 0 on succes and -1 otherwise
 */
int main(int argc, char **argv)
{
	SDL_Instance instance;
	grid *map = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: terrain file\n");
		return (1);
	}

	if (init_instance(&instance) != 0)
	{
		return (1);
	}

	map = malloc(sizeof(grid));

	while ("C is awesome")
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);

		draw_iso(&instance, &map, argv[1]);

		if (poll_events(&map) == 1)
			break;

		SDL_RenderPresent(instance.renderer);

	}

	free_all(map);
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();

	return (0);
}

/**
 * draw_iso - function that manages the draw of the isometric grid
 * @instance: SDL instance
 * @map: grid struct
 * @str: argument string
 */
void draw_iso(SDL_Instance *instance, grid **map, char *str)
{
	SDL_SetRenderDrawColor(instance->renderer, 255, 255, 255, 255);

	draw_points(map);

	trans_iso(map, str);

	rotate_iso(map);

	draw_lines(instance, map);
}
