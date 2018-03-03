/*
** EPITECH PROJECT, 2017
** raytracer1
** File description:
** cone object functions
*/

#include	<SFML/Graphics.h>
#include	<math.h>
#include	<stdlib.h>
#include	"intersect.h"
#include	"raytracer.h"

static float    get_k(float a, float b, float delta)
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

int		get_delta(sfVector3f eye_pos, sfVector3f dir_vector,
			  float semiangle, t_inter *cone)
{
	if (tanf((90.0f - semiangle) * M_PI / 180.0f) == 0)
		cone->delta = -1.0f;
	else {
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

float		u_intersect_cone(sfVector3f eye_pos, sfVector3f d_vec,
				 t_obj *obj)
{
	float		k;
	float		b;
	float		c;
	float		delta;
	float		angle = obj->radius * M_PI / 180.0f;
	float		a = powf(d_vec.x, 2.0f) + powf(d_vec.y, 2.0f) -
		(powf(d_vec.z, 2.0f) * powf(tanf(angle), 2.0f));

	eye_pos = r_translate(eye_pos, obj->coords);
	b = 2.0f * (d_vec.x * eye_pos.x + d_vec.y * eye_pos.y -
		    ((d_vec.z * eye_pos.z) * powf(tanf(angle), 2.0f)));
	c = powf(eye_pos.x, 2.0f) + powf(eye_pos.y, 2.0f) -
		(powf(eye_pos.z, 2.0f) * powf(tanf(angle), 2.0f));
	delta = powf(b, 2.0f) - 4.0f * a * c;
	if (delta < 0 || (b == 0 && a == 0))
		return (-1.0f);
	else if (delta == 0.0f)	{
		if ((k = (b * (-1)) / (2.0f * a)) < 0.0f)
			return (-1.0f);
		return (k);
	}
	return (get_k(a, b, delta));
}

float	intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
			       float semiangle)
{
	t_inter	*cone = malloc(sizeof(t_inter));
	float	k1;
	float	k2;

	get_delta(eye_pos, dir_vector, semiangle, cone);
	if (cone->delta < 0)
		return (-1.0f);
	else if (cone->delta == 0.0f)
		return ((cone->b * (-1)) / (2.0f * cone->a));
	else {
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
