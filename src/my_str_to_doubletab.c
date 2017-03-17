/*
** my_str_to_wordtab.c for task 4 in /home/martin_v/pool/day8/clone1/CPool_Day08/task04
** 
** Made by Martin Van Elslande
** Login   <martin_v@epitech.net>
** 
** Started on  Wed Oct 12 16:53:36 2016 Martin Van Elslande
** Last update Wed Mar 15 18:40:13 2017 Martin Van Elslande
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

double		*my_str_to_doubletab(char *str)
{
  double	*array;
  int		number_words;

  if (!str)
    return (NULL);
  number_words = number_of_words(str, 0, 0);
  if (number_words != 12)
    {
      if (str[0] >= '0' && str[0] <= '9')
	{
	  write(1, "Error on line: \n", 16);
	  write(1, str, my_strlen(str));
	  write(1, "\n\n", 2);
	  write(1, "You have to put 12 arguments in the config file,", 48);
	  write(1, "not more, not less !\n", 21);
	}
      return (NULL);
    }
  if ((array = malloc(sizeof(double) * number_words)) == NULL)
    return (NULL);
  process(str, array);
  return (array);
}
