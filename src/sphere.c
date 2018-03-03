/*
** EPITECH PROJECT, 2017
** raytracer1
** File description:
** sphere's calculations
*/

#include	<math.h>
#include	<SFML/Graphics.h>
#include	"raytracer.h"

static float	get_k(float a, float b, float delta)
{
	float x1;
	float x2;

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
	return (0.0f);
}

float	intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector,
			 float radius)
{
	float	a = powf(dir_vector.x, 2.0f) + powf(dir_vector.y, 2.0f) +
		powf(dir_vector.z, 2.0f);
	float	b = 2.0f * (dir_vector.x * eye_pos.x + eye_pos.y *
			dir_vector.y + eye_pos.z * dir_vector.z);
	float	c = powf(eye_pos.x, 2.0f) + powf(eye_pos.y, 2.0f) +
		powf(eye_pos.z, 2.0f) - radius * radius;
	float	delta = (b * b) - 4 * a * c;
	float	k;

	if (delta < 0)
		return (-1.0f);
	else if (delta == 0) {
		k = ((b * (-1)) / (2.0f * a));
		if (k < 0.0f)
			return (-1.0f);
		return (k);
	}
	return (get_k(a, b, delta));
}

float	u_intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector,
			   t_obj *obj)
{
	float	a = powf(dir_vector.x, 2.0f) + powf(dir_vector.y, 2.0f) +
		powf(dir_vector.z, 2.0f);
	float	b;
	float	c;
	float	delta;
	float	k;

	eye_pos = r_translate(eye_pos, obj->coords);
	b = 2.0f * (dir_vector.x * eye_pos.x +
		    eye_pos.y * dir_vector.y + eye_pos.z * dir_vector.z);
	c = powf(eye_pos.x, 2.0f) + powf(eye_pos.y, 2.0f) +
		powf(eye_pos.z, 2.0f) - powf(obj->radius, 2.0f);
	delta = (b * b) - 4 * a * c;
	if (delta < 0)
		return (-1.0f);
	else if (delta == 0) {
		k = (b * (-1)) / (2.0f * a);
		if (k < 0.0f)
			return (-1.0f);
		return (k);
	}
	return (get_k(a, b, delta));
}

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
	return (intersection_point);
}
