#include "raise.h"

/**
 * trans_iso - function that transform the 2d grid to iso
 * @map: grid struct
 * @str: argument string
 */
void trans_iso(grid **map, char *str)
{
	float incx = sqrt(2) / 2;
	float incy = 1 / sqrt(6);
	float incz = sqrt(2) / sqrt(3);
	int i, j, k;
	static int n = 1;

	if (n == 1)
		open_file(map, str);

	n++;

	for (i = 0, k = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++, k++)
		{
			(*map)->p[i][j].x = (incx * (*map)->p[i][j].x) -
				(incx * (*map)->p[i][j].y);
			(*map)->p[i][j].x += (G_WIDTH * 1.1);

			(*map)->p[i][j].y = (incy * (*map)->p[i][j].x) +
				(incy * (*map)->p[i][j].y) - (incz * (*map)->alt[k]);
			(*map)->p[i][j].y += (G_HEIGHT / 4);
		}

	}
}
