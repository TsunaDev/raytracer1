/*
** scene_light.c for raytracer1 in /home/tsuna/Epitech/projects/Infograph/raytracer/raytracer1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sat Mar 18 21:34:12 2017 Martin Van Elslande
** Last update Sun Mar 19 13:12:44 2017 Martin Van Elslande
*/

#include		<SFML/Graphics.h>
#include		"raytracer.h"

float                   object_infront(sfVector3f p, t_obj *light,
                                       int id, t_obj *obj)
{
  sfVector3f            d_vec;
  float                 k;

  d_vec = set_light_vector(light->coords, p);
  while (obj)
    {
      if (obj->id != id)
        {
          if (obj->type == 1 && (k = u_intersect_plane(p, d_vec, obj)) >= 0.0f
              && k < 0.999f)
            return (0.1f);
          else if (obj->type == 2 && (k = u_intersect_sphere(p, d_vec, obj))
                   >= 0.0f && k < 0.999f)
            return (0.1f);
          else if (obj->type == 3 && (k = u_intersect_cylinder(p, d_vec, obj))
                   >= 0.0f && k < 0.999f)
            return (0.1f);
          else if (obj->type == 4 && (k = u_intersect_cone(p, d_vec, obj))
                   >= 0.0f && k < 0.999f)
            return (0.1f);
        }
      obj = obj->next;
    }
  return (1.0f);
}

sfColor                 set_shadows(t_obj *nearest_object, t_obj *light_obj,
                                    t_obj *objhead, sfVector3f intersection)
{
  sfColor               color;
  sfVector3f            light_vector;
  sfVector3f            inter2;
  sfVector3f		light;

  inter2 = r_translate(intersection, nearest_object->coords);
  light = r_translate(light_obj->coords, nearest_object->coords);
  light_vector = set_light_vector(light, inter2);
  color = nearest_object->color;
  color.r = nearest_object->color.r *
    get_light_coef(light_vector, get_normal(intersection, nearest_object))
    * object_infront(intersection, light_obj, nearest_object->id, objhead);
  color.g = nearest_object->color.g *
    get_light_coef(light_vector, get_normal(intersection, nearest_object))
    * object_infront(intersection, light_obj, nearest_object->id, objhead);
  color.b = nearest_object->color.b *
    get_light_coef(light_vector, get_normal(intersection, nearest_object))
    * object_infront(intersection, light_obj, nearest_object->id, objhead);
  return (color);
}
