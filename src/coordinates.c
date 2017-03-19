/*
** coordinates.c for raytracer1 in /home/tsuna/Epitech/projects/Infograph/raytracer/raytracer1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sat Mar 18 21:17:36 2017 Martin Van Elslande
** Last update Sat Mar 18 23:40:08 2017 Martin Van Elslande
*/

#include		<SFML/Graphics.h>
#include		"raytracer.h"

sfVector3f              set_light_vector(sfVector3f light_coords,
					 sfVector3f intersection)
{
  sfVector3f            light_vector;

  light_vector.x = light_coords.x - intersection.x;
  light_vector.y = light_coords.y - intersection.y;
  light_vector.z = light_coords.z - intersection.z;
  return (light_vector);
}

sfVector3f              get_point_pos(float k, sfVector3f dir_vector,
				      sfVector3f eye_pos)
{
  eye_pos.x += dir_vector.x * k;
  eye_pos.y += dir_vector.y * k;
  eye_pos.z += dir_vector.z * k;
  return (eye_pos);
}

sfVector3f              get_normal(sfVector3f intersection_point, t_obj *obj)
{
  intersection_point = r_translate(intersection_point, obj->coords);
  if (obj->type == 1)
    {
      if (obj->coords.z <= 0.0f)
        return (get_normal_plane(1));
      else
        return (get_normal_plane(0));
    }
  else if (obj->type == 2)
    return (get_normal_sphere(intersection_point));
  else if (obj->type == 3)
    return (get_normal_cylinder(intersection_point));
  else if (obj->type == 4)
    return (get_normal_cone(intersection_point, obj->radius));
  else
    return (intersection_point);
}
