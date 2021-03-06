/*
** EPITECH PROJECT, 2017
** raytracer1
** File description:
** objects manipulation functions
*/

#include		<SFML/Graphics.h>
#include		<stdlib.h>
#include		<fcntl.h>
#include		"raytracer.h"

void                    set_data(t_obj *obj, char *obj_data, int *id)
{
	double                *tab = my_str_to_doubletab(obj_data);

	if (!tab)
		return ;
	obj->id = *id;
	obj->type = tab[0];
	obj->coords.x = tab[1];
	obj->coords.y = tab[2];
	obj->coords.z = tab[3];
	obj->angles.x = tab[4];
	obj->angles.y = tab[5];
	obj->angles.z = tab[6];
	obj->radius = tab[7];
	obj->color.r = tab[8];
	obj->color.g = tab[9];
	obj->color.b = tab[10];
	obj->color.a = tab[11];
	(*id)++;
}

t_obj                   *add_form(t_obj *node, char *form, int *id)
{
	t_obj                 *new_form = malloc(sizeof(t_obj));

	while (node->next)
		node = node->next;
	if (!new_form)
		return (NULL);
	node->next = new_form;
	new_form->prev = node;
	set_data(new_form, form, id);
	new_form->next = NULL;
	return (new_form);
}

void			set_light(t_obj *obj)
{
	obj->id = 0;
	obj->type = 0;
	obj->coords.x = 360.0f;
	obj->coords.y = -100.0f;
	obj->coords.z = 50.0f;
	obj->color = sfWhite;
}

t_obj                   *scene_objects(t_obj *obj, char *dir)
{
	t_obj		*head;
	int		id = 1;
	int		fd = open(dir, O_RDONLY);
	char		*line;

	if (fd == -1)
		return (NULL);
	obj = NULL;
	obj = malloc(sizeof(t_obj));
	head = obj;
	obj->prev = NULL;
	set_light(obj);
	obj->next = NULL;
	while ((line = get_next_line(fd)))
		if (line[0] != '/')
			obj = add_form(obj, line, &id);
	return (head);
}
