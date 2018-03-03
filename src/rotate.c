/*
** EPITECH PROJECT, 2018
** raytracer1
** File description:
** object rotate functions
*/

#include	<SFML/Graphics.h>
#include	<math.h>

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
	sfVector3f	rotated;

	angles.x = angles.x * M_PI / 180.0f;
	angles.y = angles.y * M_PI / 180.0f;
	angles.z = angles.z * M_PI / 180.0f;
	rotated.x = to_rotate.x;
	rotated.y = to_rotate.y * cos(angles.x) + to_rotate.z * (-sin(angles.x));
	rotated.z = to_rotate.y * sin(angles.x) + to_rotate.z * cos(angles.x);
	to_rotate.x = rotated.x * cos(angles.y) + rotated.z * sin(angles.y);
	to_rotate.y = rotated.y;
	to_rotate.z = rotated.x * (-sin(angles.y)) + rotated.z * cos(angles.y);
	rotated.x = to_rotate.x * cos(angles.z) + to_rotate.y * (-sin(angles.z));
	rotated.y = to_rotate.x * sin(angles.z) + to_rotate.y * cos(angles.z);
	rotated.z = to_rotate.z;
	return (rotated);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
	sfVector3f	rotated;

	angles.x = angles.x * M_PI / 180.0f;
	angles.y = angles.y * M_PI / 180.0f;
	angles.z = angles.z * M_PI / 180.0f;
	rotated.x = to_rotate.x * cos(angles.z) + to_rotate.y * (-sin(angles.z));
	rotated.y = to_rotate.x * sin(angles.z) + to_rotate.y * cos(angles.z);
	rotated.z = to_rotate.z;
	to_rotate.x = rotated.x * cos(angles.y) + rotated.z * sin(angles.y);
	to_rotate.y = rotated.y;
	to_rotate.z = rotated.x * (-sin(angles.y)) + rotated.z * cos(angles.y);
	rotated.x = to_rotate.x;
	rotated.y = to_rotate.y * cos(angles.x) + to_rotate.z * (-sin(angles.x));
	rotated.z = to_rotate.y * sin(angles.x) + to_rotate.z * cos(angles.x);
	return (rotated);
}
