/*
** main.c for raytracer1 in /home/tsuna/Epitech/projects/Infograph/raytracer/raytracer1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Feb 24 17:06:27 2017 Martin Van Elslande
** Last update Tue Mar 14 18:18:11 2017 Martin Van Elslande
*/

#include	<SFML/Graphics.h>
#include	"raytracer.h"

int	main(int ac, char **av)
{
  if (ac != 2 || all_tasks(av[1]) == 84)
    return (84);
  return (0);
}
