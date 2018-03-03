/*
** EPITECH PROJECT, 2017
** raytracer1
** File description:
** computing of coordinates
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
	switch (obj->type) {
	case 1:
		return (obj->coords.z <= 0.0f) ? get_normal_plane(1) :
		get_normal_plane(0);
	case 2:
		return get_normal_sphere(intersection_point);
	case 3:
		return get_normal_cylinder(intersection_point);
	case 4:
		return get_normal_cone(intersection_point, obj->radius);
	}
	return intersection_point;
}
