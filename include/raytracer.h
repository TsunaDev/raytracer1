/*
** raytracer.h for raytracer1 in /home/tsuna/Epitech/projects/Infograph/raytracer/bsraytracer1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Tue Feb  7 10:04:46 2017 Martin Van Elslande
** Last update Fri Feb 24 17:40:59 2017 Martin Van Elslande
*/

#ifndef		RAY_TRACER_
# define	RAY_TRACER_

# define	SCREEN_WIDTH	1920
# define	SCREEN_HEIGHT	1080

typedef	struct	s_my_framebuffer
{
  sfUint8	*pixels;
  int		width;
  int		height;
}		t_my_framebuffer;

typedef struct          s_obj
{
  struct s_obj          *prev;
  int                   type;
  sfVector3f            coords;
  float                 radius;
  sfColor               color;
  struct s_obj          *next;
}			t_obj;

sfVector3f		translate(sfVector3f, sfVector3f);
sfVector3f		rotation_xyz(sfVector3f, sfVector3f);
sfVector3f		rotation_zyx(sfVector3f, sfVector3f);
sfVector3f              u_calc_dir_vector(sfVector2i, sfVector2i);
float                   intersect_sphere(sfVector3f, sfVector3f, float);
float                   u_intersect_sphere(sfVector3f, sfVector3f, t_obj *);
float                   intersect_plane(sfVector3f, sfVector3f);
float                   intersect_cylinder(sfVector3f, sfVector3f, float);
float                   intersect_cone(sfVector3f, sfVector3f, float);
sfRenderWindow          *window_open(int, int);
t_my_framebuffer        *my_framebuffer_create(int, int);


#endif		/* !RAY_TRACER */
