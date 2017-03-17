/*
** raytracer.c for raytracer1 in /home/tsuna/Epitech/projects/Infograph/raytracer/raytracer1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Mar 10 17:21:19 2017 Martin Van Elslande
** Last update Fri Mar 17 13:09:11 2017 Martin Van Elslande
*/

#include		<SFML/Graphics.h>
#include		<stdlib.h>
#include		<fcntl.h>
#include		<math.h>
#include		"raytracer.h"

sfVector3f		set_light_vector(sfVector3f light_coords, sfVector3f intersection)
{
  sfVector3f		light_vector;

  light_vector.x = light_coords.x - intersection.x;
  light_vector.y = light_coords.y - intersection.y;
  light_vector.z = light_coords.z - intersection.z;
  return (light_vector);
}

sfVector3f		get_point_pos(float k, sfVector3f dir_vector, sfVector3f eye_pos)
{
  eye_pos.x += dir_vector.x * k;
  eye_pos.y += dir_vector.y * k;
  eye_pos.z += dir_vector.z * k;
  return (eye_pos);
}

sfVector3f		get_normal(sfVector3f intersection_point, t_obj *obj)
{
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

void			obj_copy(t_obj *src, t_obj *cpy)
{
  cpy->id = src->id;
  cpy->type = src->type;
  cpy->coords = src->coords;
  cpy->radius = src->radius;
  cpy->color = src->color;
}

float			object_infront(sfVector3f p, t_obj *light,
				       int id, t_obj *obj)
{
  sfVector3f		d_vec;
  float			k;

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

float			get_nearest_form(t_obj *obj, sfVector3f dir_vector,
					 sfVector3f eye_pos,
					 t_obj *nearest_object)
{
  float			k;
  float			k2;

  k2 = -1.0f;
  while (obj)
    {
      if (obj->type == 1)
	k = u_intersect_plane(eye_pos, dir_vector, obj);
      else if (obj->type == 2)
	k = u_intersect_sphere(eye_pos, dir_vector, obj);
      else if (obj->type == 3)
	k = u_intersect_cylinder(eye_pos, dir_vector, obj);
      else if (obj->type == 4)
	k = u_intersect_cone(eye_pos, dir_vector, obj);
      else
	k = -1.0f;
      if ((k2 == -1.0f && k > 0.0f) || (k < k2 && k > 0.0f))
	{
	  k2 = k;
	  obj_copy(obj, nearest_object);
	}
      obj = obj->next;
    }
  return (k2);
}

sfColor			set_shadows(t_obj *nearest_object, t_obj *light_obj,
				    t_obj *objhead, sfVector3f intersection)
{
  sfColor		color;
  sfVector3f		light_vector;
  sfVector3f		t_light;
  sfVector3f		inter2;
  sfVector3f		angles;

  inter2 = r_translate(intersection, nearest_object->coords);
  angles.x = nearest_object->angles.x * (-1);
  angles.y = nearest_object->angles.y * (-1);
  angles.z = nearest_object->angles.z * (-1);
  //  inter2 = rotate_xyz(inter2, angles);
  t_light = r_translate(light_obj->coords, nearest_object->coords);
  //  t_light = rotate_xyz(t_light, angles);
  light_vector = set_light_vector(light_obj->coords, inter2);
  //  light_vector = set_light_vector(light_obj->coords, intersection);
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

void			create_raytrace(t_my_framebuffer *framebuffer, t_obj *obj)
{
  sfVector2i		screen_pos;
  sfVector2i		screen_size;
  sfVector3f		dir_vector;
  sfVector3f		eye_pos;
  float			k2;
  t_obj			*light_obj;
  t_obj			*objhead;
  t_obj			*nearest_object;
  sfColor		color;
  sfVector3f		intersection;

  screen_size.x = SCREEN_WIDTH;
  screen_size.y = SCREEN_HEIGHT;
  screen_pos.y = 0;
  eye_pos.x = -400.0f;
  eye_pos.y = 0.0f;
  eye_pos.z = 0.0f;
  light_obj = obj;
  obj = obj->next;
  objhead = obj;
  nearest_object = obj;
  while (screen_pos.y < SCREEN_HEIGHT)
    {
      screen_pos.x = 0;
      while (screen_pos.x < SCREEN_WIDTH)
	{
	  obj = objhead;
	  dir_vector = u_calc_dir_vector(screen_size, screen_pos);
	  k2 = get_nearest_form(obj, dir_vector, eye_pos, nearest_object);
	  if (k2 > 0.0f)
	    {
	      intersection = get_point_pos(k2, dir_vector, eye_pos);
      	      color = set_shadows(nearest_object, light_obj, objhead, intersection);
     	      my_put_pixel(framebuffer, screen_pos.x, screen_pos.y, color);
	    }
	  screen_pos.x++;
	}
      screen_pos.y++;
    }
}

void			set_data(t_obj *obj, char *obj_data, int *id)
{
  double		*tab;

  if ((tab = my_str_to_doubletab(obj_data)) == NULL)
    return ;
  obj->id = *id;
  obj->type = tab[0];
  obj->coords.x = tab[1];
  obj->coords.y = tab[2];
  obj->coords.z = tab[3];
  obj->angles.x = tab[4];
  obj->angles.y = tab[5];
  obj->angles.z = tab[6];
  obj->radius = tab[7];
  obj->color.r = tab[8];
  obj->color.g = tab[9];
  obj->color.b = tab[10];
  obj->color.a = tab[11];
  (*id)++;
}

t_obj			*add_form(t_obj *node, char *form, int *id)
{
  t_obj			*new_form;

  while (node->next)
    node = node->next;
  if (!(new_form = malloc(sizeof(t_obj))))
    return (NULL);
  node->next = new_form;
  new_form->prev = node;
  set_data(new_form, form, id);
  new_form->next = NULL;
  return (new_form);
}

t_obj			*scene_objects(t_obj *obj, char *dir)
{
  t_obj			*head;
  int			id;
  int			fd;
  char			*line;

  if ((fd = open(dir, O_RDONLY)) == -1)  
    return (NULL);
  id = 1;
  obj = NULL;
  obj = malloc(sizeof(t_obj));
  head = obj;
  obj->prev = NULL;
  obj->id = 0;
  obj->type = 0;
  obj->coords.x = -200.0f;
  obj->coords.y = 0.0f;
  obj->coords.z = 10.0f;
  obj->color = sfWhite;
  obj->next = NULL;
  while ((line = get_next_line(fd)))
    if (line[0] != '/')
      obj = add_form(obj, line, &id);
  return (head);
}

int                    all_tasks(char *dir)
{
  sfRenderWindow        *window;
  sfTexture             *texture;
  sfSprite              *sprite;
  t_my_framebuffer      *framebuffer;
  t_obj			*obj;

  window = window_open(SCREEN_WIDTH, SCREEN_HEIGHT);
  sprite = sfSprite_create();
  texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  framebuffer = my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(sprite, texture, sfTrue);
  obj = malloc(sizeof(t_obj));
  obj = scene_objects(obj, dir);
  if (!obj)
    return (84);
  create_raytrace(framebuffer, obj);
  sfTexture_updateFromPixels(texture, framebuffer->pixels,
                             SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  window_loop(window, sprite);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
  free(framebuffer->pixels);
  sfRenderWindow_destroy(window);
  return (0);
}
