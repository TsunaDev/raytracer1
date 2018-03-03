/*
** EPITECH PROJECT, 2017
** raytracer1
** File description:
** light management
*/

#include	<SFML/Graphics.h>
#include	<math.h>

sfVector3f	normalize(sfVector3f vec)
{
	sfVector3f	normalized;
	float		norm;

	norm = sqrt(powf(vec.x, 2.0f) + powf(vec.y, 2.0f) + powf(vec.z, 2.0f));
	normalized.x = vec.x / norm;
	normalized.y = vec.y / norm;
	normalized.z = vec.z / norm;
	return (normalized);
}

float	get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
	float	coef;
	float	norm1;
	float	norm2;

	light_vector = normalize(light_vector);
	normal_vector = normalize(normal_vector);
	coef = light_vector.x * normal_vector.x +
		light_vector.y * normal_vector.y + light_vector.z *
		normal_vector.z;
	norm1 = sqrt(powf(light_vector.x, 2.0f) +
		powf(light_vector.y, 2.0f) + powf(light_vector.z, 2.0f));
	norm2 = sqrt(powf(normal_vector.x, 2.0f) +
		powf(normal_vector.y, 2.0f) + powf(normal_vector.z, 2.0f));
	coef /= norm1 * norm2;
	if (coef > 0.0f)
		return (coef);
	return (0.0f);
}
