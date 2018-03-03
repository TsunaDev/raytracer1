/*
** EPITECH PROJECT, 2017
** raytracer1
** File description:
** gnl's include
*/

#ifndef		READ_SIZE
# define	READ_SIZE 1
#endif		/* !READ_SIZE */

#ifndef		GET_LINE_
# define	GET_LINE_

typedef	struct	s_next_line
{
  char		buff[READ_SIZE + 1];
  int		i;
  int		bytes;
}		t_next_line;

#endif		/* !READ_SIZE */
