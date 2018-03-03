/*
** EPITECH PROJECT, 2018
** raytracer1
** File description:
** raytracer main functions
*/

#include		<SFML/Graphics.h>
#include		<stdlib.h>
#include		<fcntl.h>
#include		<math.h>
#include		"raytracer.h"

void			obj_copy(t_obj *src, t_obj *cpy)
{
	cpy->id = src->id;
	cpy->type = src->type;
	cpy->coords = src->coords;
	cpy->radius = src->radius;
	cpy->color = src->color;
}

float			get_nearest_form(t_obj *obj, sfVector3f dir_vector,
					 sfVector3f eye_pos,
					 t_obj *nearest_object)
{
	float			k;
	float			k2;

	k2 = -1.0f;
	while (obj) {
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
		if ((k2 == -1.0f && k > 0.0f) || (k < k2 && k > 0.0f)) {
			k2 = k;
			obj_copy(obj, nearest_object);
		}
		obj = obj->next;
	}
	return (k2);
}

int			determine_pixel_color(t_main_obj *main_obj,
					sfVector2i screen_pos,
					sfVector3f intersection,
					t_my_framebuffer *framebuffer)
{
	float		k;
	sfVector3f	dir_vector;
	sfVector2i	screen_size;
	sfColor		color;
	t_obj		*obj;

	main_obj->eye_angles.x = 30.0f;
	main_obj->eye_angles.y = 30.0f;
	main_obj->eye_angles.z = 30.0f;
	screen_size.x = SCREEN_WIDTH;
	screen_size.y = SCREEN_HEIGHT;
	obj = main_obj->objhead;
	dir_vector = u_calc_dir_vector(screen_size, screen_pos);
	dir_vector = rotate_xyz(dir_vector, main_obj->eye_angles);
	k = get_nearest_form(obj, dir_vector, main_obj->eye_pos,
			     main_obj->nearest_object);
	if (k > 0.0f)
	{
		intersection = get_point_pos(k, dir_vector, main_obj->eye_pos);
		color = set_shadows(main_obj->nearest_object, main_obj->light_obj,
				    main_obj->objhead, intersection);
		my_put_pixel(framebuffer, screen_pos.x, screen_pos.y, color);
	}
	screen_pos.x++;
	return (screen_pos.x);
}

void			create_raytrace(t_my_framebuffer *framebuffer,
					t_obj *obj)
{
	sfVector2i		screen_pos;
	t_main_obj		*main_obj;
	sfVector3f		intersection;

	screen_pos.y = 0;
	if ((main_obj = malloc(sizeof(t_main_obj))) == NULL)
		return ;
	main_obj->eye_pos.x = -200.0f;
	main_obj->eye_pos.y = -200.0f;
	main_obj->eye_pos.z = 400.0f;
	main_obj->light_obj = obj;
	obj = obj->next;
	main_obj->objhead = obj;
	main_obj->nearest_object = obj;
	while (screen_pos.y < SCREEN_HEIGHT) {
		screen_pos.x = 0;
		while (screen_pos.x < SCREEN_WIDTH)
			screen_pos.x = determine_pixel_color(main_obj, screen_pos,
							     intersection, framebuffer);
		screen_pos.y++;
	}
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
