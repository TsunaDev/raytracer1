/*
** my_put_pixel.c for raytracer in /home/tsuna/Epitech/projects/Infograph/raytracer/bsraytracer1/src
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Tue Feb  7 10:03:19 2017 Martin Van Elslande
** Last update Thu Feb 23 00:05:54 2017 Martin Van Elslande
*/

#include	<SFML/Graphics.h>
#include	"raytracer.h"

void	my_put_pixel(t_my_framebuffer *framebuffer, int x, int y,
		     sfColor color)
{
  if (x >= 0 && y >= 0 && x < framebuffer->width && y < framebuffer->height)
    {
      framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
    }
}
