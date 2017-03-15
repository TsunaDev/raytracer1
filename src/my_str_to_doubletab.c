/*
** my_str_to_wordtab.c for task 4 in /home/martin_v/pool/day8/clone1/CPool_Day08/task04
** 
** Made by Martin Van Elslande
** Login   <martin_v@epitech.net>
** 
** Started on  Wed Oct 12 16:53:36 2016 Martin Van Elslande
** Last update Tue Mar 14 18:17:41 2017 Martin Van Elslande
*/

#include	<stdlib.h>

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

  if (str == 0)
    return (0);
  number_words = number_of_words(str, 0, 0);
  if (number_words != 9)
    return (0);
  if ((array = malloc(sizeof(double) * number_words)) == NULL)
    return (NULL);
  process(str, array);
  return (array);
}
