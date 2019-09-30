#ifndef DEMO_H_
#define DEMO_H_

#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define S_WIDTH 1260
#define S_HEIGHT 720
#define G_WIDTH ((S_HEIGHT * 0.8))
#define G_HEIGHT ((S_HEIGHT * 0.8))

/**
 * struct grid - grid struct
 * @center: center of the grid
 * @p: matrix of points
 * @angle: angle of rotation
 *
 * Description: grid struct of the matrix of
 * points for Holberton Project
 */
typedef struct grid
{
	SDL_Point center;
	SDL_Point **p;
        int *alt;
	float angle;
} grid;

/**
 * struct SDL_Instance - instance struct
 * @window: window instance of SDL
 * @renderer: renderer instance of SDL
 *
 * Description: instance struct of SDL
 * program for Holberton Project
 */
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *instance);
void draw_iso(SDL_Instance *instance, grid **map, char *str);
int poll_events(grid **map);
void draw_points(grid **map);
void trans_iso(grid **map, char *str);
void draw_lines(SDL_Instance *instance, grid **map);
void rotate_iso(grid **map);
void free_all(grid *map);
void open_file(grid **map, char *str);

#endif
