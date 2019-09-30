#include "raise.h"

/**
 * rotate_iso - Function that rotates the isometric grid
 * @map: grid struct
 */
void rotate_iso(grid **map)
{
	int i, j;
	float newx, newy;

	(*map)->center.x = (*map)->p[3][3].x;
	(*map)->center.y = (*map)->p[3][3].y + 40;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			(*map)->p[i][j].x -= (*map)->center.x;
			(*map)->p[i][j].y -= (*map)->center.y;

			newx = (*map)->p[i][j].x * cos((*map)->angle * M_PI / 180) -
				(*map)->p[i][j].y * sin((*map)->angle * M_PI / 180);
			newy = (*map)->p[i][j].y * cos((*map)->angle * M_PI / 180) +
				(*map)->p[i][j].x * sin((*map)->angle * M_PI / 180);

			(*map)->p[i][j].x = newx + (*map)->center.x;
			(*map)->p[i][j].y = newy + (*map)->center.y;
		}
	}
}
