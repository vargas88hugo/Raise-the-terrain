#include "raise.h"

/**
 * draw_lines - function that fraws the matrix points
 * @instance: instance of SDL
 * @map: grid struct
 */
void draw_lines(SDL_Instance *instance, grid **map)
{
	int i, j;

	SDL_RenderDrawPoint(instance->renderer, 0, 0);

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 7; j++)
		{
			SDL_RenderDrawLine(instance->renderer,
					   (*map)->p[j][i].x,
					   (*map)->p[j][i].y,
					   (*map)->p[j + 1][i].x,
					   (*map)->p[j + 1][i].y
				);
			SDL_RenderDrawLine(instance->renderer,
					   (*map)->p[i][j].x,
					   (*map)->p[i][j].y,
					   (*map)->p[i][j + 1].x,
					   (*map)->p[i][j + 1].y
				);
		}
	}

}
