#include "raise.h"

/*
static int arr[8][8] = {
		{120, 60, 40, 60, 20, -20, -80, -120},
		{40, 20, 30, 30, -10, -40, -90, -110},
		{20, 30, 10, 06, -6, -20, -26, -90},
		{00, -6, 10, 10, -6, -20, -20, -40},
		{-20, -20, -18, -14, -40, -20, -20, -30},
		{-10, -10, -10, -10, -8, -20, -20, -30},
		{20, 10, 10, 10, 10, 04, 10, -10},
		{30, 24, 24, 22, 20, 18, 14, 16}
	};
*/
/**
 * trans_iso - function that transform the 2d grid to iso
 * @map: grid struct
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
