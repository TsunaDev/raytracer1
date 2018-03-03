/*
** EPITECH PROJECT, 2017
** raytracer1
** File description:
** main functions
*/

#include	<SFML/Graphics.h>
#include	"raytracer.h"

int			my_strncmp(char *str, char *str2, int n)
{
	int			i;

	i = 0;
	if (my_strlen(str) < n || my_strlen(str2) < n)
		return (0);
	while (str[i] && str2[i] && i < n) {
		if (str[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

int                     my_checkenv(char **env)
{
	int                   i = 0;

	while (env[i] != NULL) {
		if (my_strncmp(env[i], "DISPLAY=", 8))
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	if (!my_checkenv(env))
		return (84);
	if (ac != 2 || all_tasks(av[1]) == 84)
		return (84);
	return (0);
}
