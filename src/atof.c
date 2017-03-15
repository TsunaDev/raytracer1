/*
** atof.c for raytracer1 in /home/tsuna/Epitech/projects/Infograph/raytracer/raytracer1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Tue Mar 14 18:09:22 2017 Martin Van Elslande
** Last update Tue Mar 14 18:13:19 2017 Martin Van Elslande
*/

#include	<math.h>

int     my_isneg(char *str)
{
  int   i;
  int   n;

  i = 0;
  n = 0;
  while (str[i] && (str[i] == '-' || str[i] == '+'))
    {
      if (str[i] == '-')
        n++;
      i++;
    }
  if (n % 2 == 0)
    return (-1);
  else
    return (1);
}

int     my_isnumber(char *str, int i)
{
  if (str[i] >= '0' && str[i] <= '9')
    return (0);
  else
    return (1);
}

int     my_getnbr(char *str)
{
  int   i;
  int   num;
  int   neg;
  int   nbr;

  i = 0;
  nbr = 0;
  neg = my_isneg(str);
  num = my_isnumber(str, i);
  while (num == 0 || str[i] == '-' || str[i] == '+')
    {
      if (num == 0)
        {
          nbr = (10 * nbr) + (str[i] - 48);
          i++;
        }
      else
        i++;
      num = my_isnumber(str, i);
    }
  nbr = nbr * ((-1) * neg);
  return (nbr);
}

int	my_strlen_atof(char *str)
{
  int	i;

  i = 0;
  while (str[i] >= '0' && str[i] <= '9')
    i++;
  return (i);
}

double		my_atof(char *str)
{
  int		decimal_part;
  double	decimal_part_f;
  int		i;

  i = 0;
  while (str[i] != '.' && str[i] != ',')
    i++;
  i++;
  decimal_part = my_getnbr(&str[i]);
  decimal_part_f = (double)decimal_part / powf(10.0f, my_strlen_atof(&str[i]));
  decimal_part_f += (double)my_getnbr(str);
  return (decimal_part_f);
}
