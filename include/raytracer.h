/*
** raytracer.h for raytracer1 in /home/tsuna/Epitech/projects/Infograph/raytracer/bsraytracer1
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Tue Feb  7 10:04:46 2017 Martin Van Elslande
** Last update Sun Mar 19 13:05:16 2017 Martin Van Elslande
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
  int			id;
  int                   type;
  sfVector3f            coords;
  sfVector3f		angles;
  float                 radius;
  sfColor               color;
  struct s_obj          *next;
}			t_obj;

typedef struct		s_main_obj
{
  t_obj			*light_obj;
  t_obj			*objhead;
  t_obj			*nearest_object;
  sfVector3f		eye_pos;
  sfVector3f		eye_angles;
}			t_main_obj;

int			all_tasks(char *);
int			my_getnbr(char *);
void			my_put_pixel(t_my_framebuffer *, int, int, sfColor);
void			window_loop(sfRenderWindow *, sfSprite *);
float                   intersect_sphere(sfVector3f, sfVector3f, float);
float                   u_intersect_sphere(sfVector3f, sfVector3f, t_obj *);
float                   intersect_plane(sfVector3f, sfVector3f);
float			u_intersect_plane(sfVector3f, sfVector3f, t_obj *);
float                   intersect_cylinder(sfVector3f, sfVector3f, float);
float			u_intersect_cylinder(sfVector3f, sfVector3f, t_obj *);
float                   intersect_cone(sfVector3f, sfVector3f, float);
float                   u_intersect_cone(sfVector3f, sfVector3f, t_obj *);
float			get_light_coef(sfVector3f, sfVector3f);
double			*my_str_to_doubletab(char *);
char			*get_next_line(int);
sfRenderWindow          *window_open(int, int);
sfVector3f		translate(sfVector3f, sfVector3f);
sfVector3f		r_translate(sfVector3f, sfVector3f);
sfVector3f		rotate_xyz(sfVector3f, sfVector3f);
sfVector3f		rotate_zyx(sfVector3f, sfVector3f);
sfVector3f		get_normal_plane(int);
sfVector3f		get_normal_sphere(sfVector3f);
sfVector3f		get_normal_cylinder(sfVector3f);
sfVector3f		get_normal(sfVector3f, t_obj *);
sfVector3f		get_normal_cone(sfVector3f, float);
sfVector3f		set_light_vector(sfVector3f, sfVector3f);
sfVector3f		get_point_pos(float, sfVector3f, sfVector3f);
sfVector3f              u_calc_dir_vector(sfVector2i, sfVector2i);
sfColor			set_shadows(t_obj *, t_obj *, t_obj *, sfVector3f);
t_my_framebuffer        *my_framebuffer_create(int, int);
t_obj			*scene_objects(t_obj *, char *);

#endif		/* !RAY_TRACER */
