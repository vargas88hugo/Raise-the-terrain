#include "raise.h"

/**
 * draw_points - functio that comfigures the points of the matrix
 * @map: grid struct
 */
void draw_points(grid **map)
{
	float x = ((G_WIDTH) / 7) * 1.3, y = ((G_HEIGHT) / 7) * 1.3;
	float w;
	float h;
	int i, j;

	(*map)->p = malloc(sizeof(SDL_Point *) * 8);

	for (i = 0, h = -(G_HEIGHT / 2) - y; i < 8; i++, h += y)
	{
		(*map)->p[i] = malloc(sizeof(SDL_Point) * 8);
		for (j = 0, w = -(G_WIDTH / 2) - x; j < 8; j++, w += y)
		{
			(*map)->p[i][j].x = w;
			(*map)->p[i][j].y = h;
		}
	}
}
