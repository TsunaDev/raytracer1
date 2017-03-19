##
## Makefile for raytracer1 in /home/tsuna/Epitech/projects/Infograph/raytracer/raytracer1
## 
## Made by Martin Van Elslande
## Login   <martin.van-elslande@epitech.eu>
## 
## Started on  Tue Mar 14 18:01:15 2017 Martin Van Elslande
## Last update Sat Mar 18 21:38:07 2017 Martin Van Elslande
##

SRC	=	src/atof.c		\
		src/calc_dir_vector.c	\
		src/cone.c		\
		src/sphere.c		\
		src/cylinder.c		\
		src/plane.c		\
		src/main.c		\
		src/translate.c		\
		src/u_calc_dir_vector.c	\
		src/window.c		\
		src/light.c		\
		src/rotate.c		\
		src/raytracer.c		\
		src/my_put_pixel.c	\
		src/get_next_line.c	\
		src/coordinates.c	\
		src/objects.c		\
		src/scene_light.c	\
		src/my_str_to_doubletab.c

OBJ	=	$(SRC:.c=.o)

NAME	=	raytracer

CFLAGS	=	-Wall -Wextra -Iinclude

all:	$(NAME)

debug:	CFLAGS += -ggdb3

debug:	fclean all

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lm -lc_graph_prog

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
