/*
** EPITECH PROJECT, 2017
** raytracer1
** File description:
** object translate functions
*/

#include	<SFML/Graphics.h>

sfVector3f	translate(sfVector3f to_translate, sfVector3f translations)
{
	sfVector3f	translated;

	translated.x = to_translate.x + translations.x;
	translated.y = to_translate.y + translations.y;
	translated.z = to_translate.z + translations.z;
	return (translated);
}

sfVector3f	r_translate(sfVector3f to_translate, sfVector3f translations)
{
	sfVector3f	translated;

	translated.x = to_translate.x - translations.x;
	translated.y = to_translate.y - translations.y;
	translated.z = to_translate.z - translations.z;
	return (translated);
}
