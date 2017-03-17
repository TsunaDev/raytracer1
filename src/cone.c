/*
** intersect_cone.c for raytracer1 in /home/tsuna/Epitech/projects/Infograph/raytracer/raytracer1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Wed Feb 22 22:24:14 2017 Martin Van Elslande
** Last update Fri Mar 17 14:15:25 2017 Martin Van Elslande
*/

#include	<SFML/Graphics.h>
#include	<math.h>
#include	<stdlib.h>
#include	"intersect.h"
#include	"raytracer.h"

int		u_get_delta(sfVector3f eye_pos, sfVector3f dir_vector,
			    t_obj *obj, t_inter *cone)
{
  float		semiangle;

  semiangle = obj->radius * M_PI / 180.0f;
  cone->a = powf(dir_vector.x, 2.0f) + powf(dir_vector.y, 2.0f) -
    (powf(dir_vector.z, 2.0f) * powf(tanf(semiangle), 2.0f));
  cone->b = 2.0f * (dir_vector.x * eye_pos.x + dir_vector.y * eye_pos.y -
		    ((dir_vector.z * eye_pos.z) *
		     powf(tanf(semiangle), 2.0f)));
  cone->c = powf(eye_pos.x, 2.0f) + powf(eye_pos.y, 2.0f) -
    (powf(eye_pos.z, 2.0f) * powf(tanf(semiangle), 2.0f));
  cone->delta = powf(cone->b, 2.0f) - 4.0f * cone->a * cone->c;
  if (cone->a == 0 && cone->b == 0)
    return (1);
  return (0);
}

int		get_delta(sfVector3f eye_pos, sfVector3f dir_vector,
			  float semiangle, t_inter *cone)
{
  if (tanf((90.0f - semiangle) * M_PI / 180.0f) == 0)
    cone->delta = -1.0f;
  else
    {
      cone->a = powf(dir_vector.x, 2.0f) + powf(dir_vector.y, 2.0f) -
	(powf(dir_vector.z, 2.0f) /
	 powf(tanf((90.0f - semiangle) * M_PI / 180.0f), 2.0f));
      cone->b = 2.0f * (dir_vector.x * eye_pos.x + dir_vector.y * eye_pos.y -
			((dir_vector.z * eye_pos.z) /
			 powf(tanf((90.0f - semiangle) * M_PI / 180.0f), 2.0f)));
      cone->c = powf(eye_pos.x, 2.0f) + powf(eye_pos.y, 2.0f) -
	(powf(eye_pos.z, 2.0f) / powf(tanf((90.0f - semiangle) *
					   M_PI / 180.0f), 2.0f));
      cone->delta = powf(cone->b, 2.0f) - 4.0f * cone->a * cone->c;
      if (cone->a == 0 && cone->b == 0)
	return (1);
    }
  return (0);
}

/*
**else if (cone->a == 0)
**  return (-cone->c / cone->b);
*/

float		u_intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
				 t_obj *obj)
{
  t_inter	*cone;
  float		k1;
  float		k2;

  cone = malloc(sizeof(t_inter));
  eye_pos = r_translate(eye_pos, obj->coords);
  u_get_delta(eye_pos, dir_vector, obj, cone);
  if (cone->delta < 0 || (cone->b == 0 && cone->a == 0))
    return (-1.0f);
  else if (cone->delta == 0.0f)
    return ((cone->b * (-1)) / (2.0f * cone->a));
  else
    {
      k1 = ((cone->b * (-1)) + sqrt(cone->delta)) / (2.0f * cone->a);
      k2 = ((cone->b * (-1)) - sqrt(cone->delta)) / (2.0f * cone->a);
      if (k1 < 0 && k2 < 0)
        return (-1.0f);
      if (k1 > k2)
        return ((k2 > 0) ? (k2) : (k1));
      else if (k2 > k1)
        return ((k1 > 0) ? (k1) : (k2));
      else
        return (-1.0f);
    }
  return (0.0f);
}

float		intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
			       float semiangle)
{
  t_inter	*cone;
  float		k1;
  float		k2;

  cone = malloc(sizeof(t_inter));
  get_delta(eye_pos, dir_vector, semiangle, cone);
  if (cone->delta < 0)
    return (-1.0f);
  else if (cone->delta == 0.0f)
    return ((cone->b * (-1)) / (2.0f * cone->a));
  else
    {
      k1 = ((cone->b * (-1)) + sqrt(cone->delta)) / (2.0f * cone->a);
      k2 = ((cone->b * (-1)) - sqrt(cone->delta)) / (2.0f * cone->a);
      if (k1 < 0 && k2 < 0)
        return (-1.0f);
      if (k1 > k2)
        return ((k2 > 0) ? (k2) : (k1));
      else if (k2 > k1)
        return ((k1 > 0) ? (k1) : (k2));
      else
        return (-1.0f);
    }
  return (0.0f);
}

sfVector3f	get_normal_cone(sfVector3f intersection_point,
				float semiangle)
{
  semiangle = tanf(semiangle * M_PI / 180.0f);
  intersection_point.z = -semiangle * intersection_point.z;
  return (intersection_point);
}
