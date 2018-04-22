#include "graphics.h"

t_vector2i	*new_vector2i(int x, int y)
{
	t_vector2i	*vector2i;

	vector2i = ft_memalloc(sizeof(t_vector2i));
	vector2i->x = x;
	vector2i->y = y;
	return (vector2i);
}

t_vector2i	vector2i(int x, int y)
{
	t_vector2i	vector2i;

	vector2i.x = x;
	vector2i.y = y;
	return (vector2i);
}
