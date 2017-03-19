/*
** my_str_to_doubletab.c for raytracer1 in /home/tsuna/Epitech/projects/Infograph/raytracer/raytracer1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sun Mar 19 21:57:38 2017 Martin Van Elslande
** Last update Sun Mar 19 21:58:54 2017 Martin Van Elslande
*/

#include	<stdlib.h>
#include	<unistd.h>

double	my_atof(char *);

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	number_of_words(char *str, int i, int j)
{
  j = 0;
  while (str[i] != '\0')
    {
      if ((str[i] == ' ' || str[i] == '\t') && str[i - 1] > 32)
	j++;
      i++;
    }
  if (str[i - 1] > 32)
    j++;
  return (j);
}

void	process(char *str, double *array)
{
  int	slot;
  int	i;

  i = 0;
  slot = 0;
  while (str[i] && i < my_strlen(str))
    {
      while (str[i] && str[i] <= 32)
	i++;
      array[slot] = my_atof(&str[i]);
      while (str[i] && str[i] > 32)
	i++;
      slot++;
    }
}

int		check_line(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9') && str[i] != '.' &&
	  str[i] != '\t' && str[i] != ' ' && str[i] != '-' &&
	  str[i] != '+')
	return (0);
      i++;
    }
  return (1);
}

double		*my_str_to_doubletab(char *str)
{
  double	*array;
  int		number_words;

  if (!str)
    return (NULL);
  number_words = number_of_words(str, 0, 0);
  if (number_words != 12 || !check_line(str))
    {
      if (str[0] != 't')
	{
	  write(2, "Error on line: \n", 16);
	  write(1, str, my_strlen(str));
	  write(1, "\n\n", 2);
	  write(1, "You have to put 12 values (numbers) in the config file,",
		55);
	  write(1, " separated by tabulations, ", 27);
	  write(1, "not more, not less !\n", 21);
	}
      return (NULL);
    }
  if ((array = malloc(sizeof(double) * number_words)) == NULL)
    return (NULL);
  process(str, array);
  return (array);
}
