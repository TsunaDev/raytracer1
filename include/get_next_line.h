/*
** get_next_line.h for get_next_line in /home/tsuna/Epitech/projects/prog_elem/GNL/CPE_2016_getnextline
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Mon Jan  2 23:38:58 2017 Martin Van Elslande
** Last update Sun Mar  5 17:03:27 2017 Martin Van Elslande
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
