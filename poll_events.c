#include "raise.h"

/**
 * poll_events - function that manages the events of SDL
 * @map: grid struct
 * Return: 1 on success and 0 otherwise
 */
int poll_events(grid **map)
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			return (1);
		case SDL_KEYDOWN:
			key = event.key;

			if (key.keysym.scancode == 0x29)
				return (1);
			if (key.keysym.scancode == SDL_SCANCODE_RIGHT)
			{
				(*map)->angle += 1;
			}

			if (key.keysym.scancode == SDL_SCANCODE_LEFT)
				(*map)->angle -= 1;
			break;
		}
	}

	return (0);
}
