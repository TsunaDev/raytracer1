/*
** intersect_sphere.c for bsraytracer in /home/tsuna/Epitech/projects/Infograph/raytracer/bsraytracer1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Tue Feb  7 09:38:45 2017 Martin Van Elslande
** Last update Fri Mar 17 11:59:23 2017 Martin Van Elslande
*/

#include	<math.h>
#include	<SFML/Graphics.h>
#include	"raytracer.h"

float	intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector, float radius)
{
  float	a;
  float	b;
  float	c;
  float	delta;
  float	x1;
  float	x2;

  a = powf(dir_vector.x, 2.0f) + powf(dir_vector.y, 2.0f) + powf(dir_vector.z, 2.0f);
  b = 2.0f * (dir_vector.x * eye_pos.x + eye_pos.y * dir_vector.y + eye_pos.z * dir_vector.z);
  c = powf(eye_pos.x, 2.0f) + powf(eye_pos.y, 2.0f) + powf(eye_pos.z, 2.0f) - radius * radius;
  delta = (b * b) - 4 * a * c;
  if (delta < 0)
    return (-1.0f);
  else if (delta == 0)
    return ((b * (-1)) / (2.0f * a));
  else
    {
      x1 = ((b * (-1)) + sqrt(delta)) / (2.0f * a);
      x2 = ((b * (-1)) - sqrt(delta)) / (2.0f * a);
      if (x1 < 0 && x2 < 0)
	return (-1.0f);
      if (x1 > x2)
	return ((x2 > 0) ? (x2) : (x1));
      else if (x2 > x1)
	return ((x1 > 0) ? (x1) : (x2));
      else
	return (-1.0f);
    }
  return (0.0f);
}

float	u_intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector, t_obj *obj)
{
  float	a;
  float	b;
  float	c;
  float	delta;
  float	x1;
  float	x2;

  eye_pos = r_translate(eye_pos, obj->coords);
  //  eye_pos = rotate_xyz(eye_pos, obj->angles);
  //  dir_vector = rotate_xyz(dir_vector, obj->angles);
  a = powf(dir_vector.x, 2.0f) + powf(dir_vector.y, 2.0f) + powf(dir_vector.z, 2.0f);
  b = 2.0f * (dir_vector.x * eye_pos.x + eye_pos.y * dir_vector.y + eye_pos.z * dir_vector.z);
  c = powf(eye_pos.x, 2.0f) + powf(eye_pos.y, 2.0f) + powf(eye_pos.z, 2.0f) - powf(obj->radius, 2.0f);
  delta = (b * b) - 4 * a * c;
  if (delta < 0)
    return (-1.0f);
  else if (delta == 0)
    return ((b * (-1)) / (2.0f * a));
  else
    {
      x1 = ((b * (-1)) + sqrt(delta)) / (2.0f * a);
      x2 = ((b * (-1)) - sqrt(delta)) / (2.0f * a);
      if (x1 < 0 && x2 < 0)
	return (-1.0f);
      if (x1 > x2)
	return ((x2 > 0) ? (x2) : (x1));
      else if (x2 > x1)
	return ((x1 > 0) ? (x1) : (x2));
      else
	return (-1.0f);
    }
  return (0.0f);
}

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  return (intersection_point);
}
