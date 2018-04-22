#include "graphics.h"

t_vector2f	*new_vector2f(float x, float y)
{
	t_vector2f	*vector2i;

	vector2i = ft_memalloc(sizeof(t_vector2f));
	vector2i->x = x;
	vector2i->y = y;
	return (vector2i);
}

t_vector2f	vector2f(float x, float y)
{
	t_vector2f	vector2i;

	vector2i.x = x;
	vector2i.y = y;
	return (vector2i);
}