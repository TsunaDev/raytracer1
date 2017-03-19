/*
** plane.c for raytracer1 in /home/tsuna/Epitech/projects/Infograph/raytracer/bsraytracer1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Tue Feb  7 11:25:47 2017 Martin Van Elslande
** Last update Sat Mar 18 23:41:28 2017 Martin Van Elslande
*/

#include	<SFML/Graphics.h>
#include	"raytracer.h"

float	u_intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector,
			  t_obj *obj)
{
  float	k;

  eye_pos.z = eye_pos.z - obj->coords.z;
  if (dir_vector.z == 0.0f)
    return (-1.0f);
  k = (eye_pos.z * (-1)) / dir_vector.z;
  if (k < 0)
    return (-1.0f);
  else
    return (k);
}

float	intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float	k;

  if (dir_vector.z == 0.0f)
    return (-1.0f);
  k = (eye_pos.z * (-1)) / dir_vector.z;
  if (k < 0)
    return (-1.0f);
  else
    return (k);
}

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	normal;

  normal.x = 0.0f;
  normal.y = 0.0f;
  if (!upward)
    normal.z = -1.0f;
  else
    normal.z = 1.0f;
  return (normal);
}
