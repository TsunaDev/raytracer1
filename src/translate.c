/*
** translate.c for raytracer1 in /home/tsuna/Epitech/projects/Infograph/raytracer/raytracer1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sat Feb 18 16:55:40 2017 Martin Van Elslande
** Last update Sat Feb 18 17:14:34 2017 Martin Van Elslande
*/

#include	<SFML/Graphics.h>

sfVector3f	translate(sfVector3f to_translate, sfVector3f translations)
{
  sfVector3f	translated;
  
  translated.x = to_translate.x + translations.x;
  translated.y = to_translate.y + translations.y;
  translated.z = to_translate.z + translations.z;
  return (translated);
}
