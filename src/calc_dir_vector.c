/*
** EPITECH PROJECT, 2017
** raytracer1
** File description:
** direction vector calculus
*/

#include        <SFML/Graphics.h>
#include        <math.h>

sfVector3f      calc_dir_vector(float dist_to_plane, sfVector2i screen_size,
				sfVector2i screen_pos)
{
	sfVector3f    dir_vector;

	dir_vector.x = dist_to_plane;
	dir_vector.y = ((float)screen_size.x / 2.0f) - (float)screen_pos.x;
	dir_vector.z = ((float)screen_size.y / 2.0f) - (float)screen_pos.y;
	return (dir_vector);
}
