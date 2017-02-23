/*
** light.c for raytracer1 in /home/tsuna
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Wed Feb 22 23:54:10 2017 Martin Van Elslande
** Last update Thu Feb 23 11:25:49 2017 Martin Van Elslande
*/

#include	<SFML/Graphics.h>
#include	<math.h>

float	get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
  float	coef;
  float	norm1;
  float	norm2;
  float	vec1;
  float	vec2;

  vec1 = sqrt(powf(light_vector.x, 2.0f) + powf(light_vector.y, 2.0f) + powf(light_vector.z, 2.0f));
  vec2 = sqrt(powf(normal_vector.x, 2.0f) + powf(normal_vector.y, 2.0f) + powf(normal_vector.z, 2.0f));
  light_vector.x /= vec1;
  light_vector.y /= vec1;
  light_vector.z /= vec1;
  normal_vector.x /= vec2;
  normal_vector.y /= vec2;
  normal_vector.z /= vec2;
  coef = light_vector.x * normal_vector.x + light_vector.y * normal_vector.y + light_vector.z * normal_vector.z;
  norm1 = sqrt(powf(light_vector.x, 2.0f) + powf(light_vector.y, 2.0f) + powf(light_vector.z, 2.0f));
  norm2 = sqrt(powf(normal_vector.x, 2.0f) + powf(normal_vector.y, 2.0f) + powf(normal_vector.z, 2.0f));
  coef /= norm1 * norm2;
  if (coef > 0.0f)
    return (coef);
  return (0.0f);
}
