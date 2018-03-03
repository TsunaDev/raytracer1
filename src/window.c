/*
** EPITECH PROJECT, 2017
** raytracer1
** File description:
** window management
*/

#include                <SFML/Graphics.h>
#include		<stdlib.h>
#include		"raytracer.h"

t_my_framebuffer        *my_framebuffer_create(int width, int height)
{
	int                   i = 0;
	t_my_framebuffer      *fb = malloc(sizeof(t_my_framebuffer));

	if (!fb)
		return (NULL);
	fb->width = width;
	fb->height = height;
	fb->pixels = malloc(width * height * 4 * sizeof(fb->pixels));
	if (!fb->pixels)
		return (NULL);
	while (i < width * height * 4) {
		fb->pixels[i] = 0;
		i++;
	}
	return (fb);
}

void                    window_loop(sfRenderWindow *window, sfSprite *sprite)
{
	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, sprite, NULL);
		sfRenderWindow_display(window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
			sfRenderWindow_close(window);
	}
}

sfRenderWindow          *window_open(int width, int height)
{
	sfVideoMode           mode;
	sfRenderWindow*       window;

	mode.width = width;
	mode.height = height;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "Raytracer",
				sfResize | sfClose, NULL);
	if (window == NULL)
		return (NULL);
	return (window);
}
