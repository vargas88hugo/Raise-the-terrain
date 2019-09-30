#include "raise.h"

/**
 * free_all - Function that frees memory of the program
 * @map: grid struct
 */
void free_all(grid *map)
{
	int i;

	for (i = 0; i < 8; i++)
		free(map->p[i]);

	free(map->alt);
	free(map->p);
	free(map);
}
