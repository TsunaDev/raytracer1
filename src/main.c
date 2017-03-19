/*
** main.c for raytracer1 in /home/tsuna/Epitech/projects/Infograph/raytracer/raytracer1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Feb 24 17:06:27 2017 Martin Van Elslande
** Last update Sun Mar 19 20:13:12 2017 Martin Van Elslande
*/

#include	<SFML/Graphics.h>
#include	"raytracer.h"

int			my_strncmp(char *str, char *str2, int n)
{
  int			i;

  i = 0;
  if (my_strlen(str) < n || my_strlen(str2) < n)
    return (0);
  while (str[i] && str2[i] && i < n)
    {
      if (str[i] != str2[i])
	return (0);
      i++;
    }
  return (1);
}

int                     my_checkenv(char **env)
{
  int                   i;
  int                   n;

  i = 0;
  n = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], "DISPLAY=", 8))
        n++;
      else if (my_strncmp(env[i], "LIBRARY_PATH=", 13))
        n++;
      else if (my_strncmp(env[i], "LD_LIBRARY_PATH=", 16))
        n++;
      else if (my_strncmp(env[i], "CPATH=", 6))
        n++;
      else if (my_strncmp(env[i], "XDG_RUNTIME_DIR=", 16))
        n++;
      i++;
    }
  if (n != 5)
    return (0);
  else
    return (1);
}

int	main(int ac, char **av, char **env)
{
  if (!my_checkenv(env))
    return (84);
  if (ac != 2 || all_tasks(av[1]) == 84)
    return (84);
  return (0);
}
