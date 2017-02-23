/*
** calc_dir_vector.c for raytracer1 in /home/tsuna/Epitech/projects/Infograph/raytracer/raytracer1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sat Feb 18 16:21:03 2017 Martin Van Elslande
** Last update Thu Feb 23 10:55:52 2017 Martin Van Elslande
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
