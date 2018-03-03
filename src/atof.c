/*
** EPITECH PROJECT, 2017
** raytracer1
** File description:
** Functions that permits to convert a string to a float
*/

#include	<math.h>

int     my_isneg(char *str)
{
	int   i = 0;
	int   n = 0;

	while (str[i] && (str[i] == '-' || str[i] == '+')) {
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
	int   i = 0;
	int   num = my_isnumber(str, i);;
	int   neg = my_isneg(str);
	int   nbr = 0;

	while (num == 0 || str[i] == '-' || str[i] == '+') {
		if (num == 0) {
			nbr = (10 * nbr) + (str[i] - 48);
			i++;
		} else
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
	decimal_part_f = (double)decimal_part /
		powf(10.0f, my_strlen_atof(&str[i]));
	decimal_part_f += (double)my_getnbr(str);
	return (decimal_part_f);
}
