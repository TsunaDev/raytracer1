/*
** intersect_cylinder.c for raytracer1 in /home/tsuna/Epitech/projects/Infograph/raytracer/raytracer1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Wed Feb 22 22:16:06 2017 Martin Van Elslande
** Last update Fri Mar 17 12:16:47 2017 Martin Van Elslande
*/

#include	<SFML/Graphics.h>
#include	<math.h>
#include	"raytracer.h"

float	u_intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector, t_obj *obj)
{
  float	a;
  float	b;
  float	c;
  float	delta;
  float	x1;
  float	x2;
  sfVector3f	angles;

  //angles.x = obj->angles.x * (-1);
  //angles.y = obj->angles.y * (-1);
  //angles.z = obj->angles.z * (-1);
  eye_pos = r_translate(eye_pos, obj->coords);
  //  dir_vector = rotate_xyz(dir_vector, angles);
  a = powf(dir_vector.x, 2.0f) + powf(dir_vector.y, 2.0f);
  b = 2.0f * (dir_vector.x * eye_pos.x + dir_vector.y * eye_pos.y);
  c = powf(eye_pos.x, 2.0f) + powf(eye_pos.y, 2.0f) - powf(obj->radius, 2.0f);
  delta = powf(b, 2.0f) - 4.0f * a * c;
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

float	intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector, float radius)
{
  float	a;
  float	b;
  float	c;
  float	delta;
  float	x1;
  float	x2;

  a = powf(dir_vector.x, 2.0f) + powf(dir_vector.y, 2.0f);
  b = 2.0f * (dir_vector.x * eye_pos.x + dir_vector.y * eye_pos.y);
  c = powf(eye_pos.x, 2.0f) + powf(eye_pos.y, 2.0f) - powf(radius, 2.0f);
  delta = powf(b, 2.0f) - 4.0f * a * c;
  if (delta < 0 || a == 0)
    return (-1.0f);
  else if (delta == 0)
    {
      x1 = (b * (-1)) / (2.0f * a);
      if (x1 < 0)
	return (-1.0f);
      return (x1);
    }
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

sfVector3f	get_normal_cylinder(sfVector3f intersection_point)
{
  intersection_point.z = 0.0f;
  return (intersection_point);
}
