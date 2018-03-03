/*
** EPITECH PROJECT, 2017
** raytracer1
** File description:
** usable dir vector function
*/

#include        <SFML/Graphics.h>
#include        <math.h>

sfVector3f      u_calc_dir_vector(sfVector2i screen_size,
				sfVector2i screen_pos)
{
	sfVector3f    dir_vector;

	dir_vector.x = ((float)screen_size.x / 2.0f) / tan(25.0f * M_PI / 180.0f);
	dir_vector.y = ((float)screen_size.x / 2.0f) - (float)screen_pos.x;
	dir_vector.z = ((float)screen_size.y / 2.0f) - (float)screen_pos.y;
	return (dir_vector);
}
