/*
** intersect_cone.c for raytracer1 in /home/tsuna/Epitech/projects/Infograph/raytracer/raytracer1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Wed Feb 22 22:24:14 2017 Martin Van Elslande
** Last update Thu Feb 23 11:52:01 2017 Martin Van Elslande
*/

#include	<SFML/Graphics.h>
#include	<math.h>

float	intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector, float semiangle)
{
  float	a;
  float	b;
  float	c;
  float	delta;
  float	k1;
  float	k2;

  a = powf(dir_vector.x, 2.0f) + powf(dir_vector.y, 2.0f) - (powf(dir_vector.z, 2.0f) / powf(tan((90.0f - semiangle) * M_PI / 180.0f), 2.0f));
  b = 2.0f * (dir_vector.x * eye_pos.x + dir_vector.y * eye_pos.y - ((dir_vector.y * eye_pos.y) / powf(tan((90.0f - semiangle) * M_PI / 180.0f), 2.0f)));
  c = powf(eye_pos.x, 2.0f) + powf(eye_pos.y, 2.0f) - (powf(eye_pos.z, 2.0f) / powf(tan((90.0f - semiangle) * M_PI / 180.0f), 2.0f));
  delta = powf(b, 2.0f) - 4.0f * a * c;
  if (a == 0 && b == 0)
    return (0.0f);
  if (delta < 0)
    return (-1.0f);
  else if (delta == 0)
    return ((b * (-1)) / (2.0f * a));
  else
    {
      k1 = ((b * (-1)) + sqrt(delta)) / (2.0f * a);
      k2 = ((b * (-1)) - sqrt(delta)) / (2.0f * a);
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

sfVector3f	get_normal_cone(sfVector3f intersection_point, float semiangle)
{
  intersection_point.z = intersection_point.y * (sin(semiangle) * -1);
  return (intersection_point);
}
