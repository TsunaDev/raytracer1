/*
** rotate.c for raytracer1 in /home/tsuna/Epitech/projects/Infograph/raytracer/raytracer1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sat Feb 18 20:04:53 2017 Martin Van Elslande
** Last update Sat Feb 18 20:28:11 2017 Martin Van Elslande
*/

#include	<SFML/Graphics.h>
#include	<math.h>

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	rotated;

  rotated.x = to_rotate.x;
  rotated.y = to_rotate.y * cos(angles.x) + to_rotate.z * (sin(angles.x) * -1);
  rotated.z = to_rotate.y * sin(angles.x) + to_rotate.z * cos(angles.x);
  rotated.x = rotated.x * cos(angles.y) + rotated.z * sin(angles.y);
  rotated.y = rotated.y;
  rotated.z = rotated.x * (sin(angles.y) * -1) + rotated.z * cos(angles.y);
  rotated.x = rotated.x * cos(angles.z) + rotated.y * (sin(angles.z) * -1);
  rotated.y = rotated.x * sin(angles.z) + rotated.y * cos(angles.z);
  rotated.z = rotated.z;

  return (rotated);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	rotated;
  
  rotated.x = rotated.x * cos(angles.z) + rotated.y * (sin(angles.z) * -1);
  rotated.y = rotated.x * sin(angles.z) + rotated.y * cos(angles.z);
  rotated.z = rotated.z;
  rotated.x = rotated.x * cos(angles.y) + rotated.z * sin(angles.y);
  rotated.y = rotated.y;
  rotated.z = rotated.x * (sin(angles.y) * -1) + rotated.z * cos(angles.y);
  rotated.x = to_rotate.x;
  rotated.y = to_rotate.y * cos(angles.x) + to_rotate.z * (sin(angles.x) * -1);
  rotated.z = to_rotate.y * sin(angles.x) + to_rotate.z * cos(angles.x);

  return (rotated);
}
