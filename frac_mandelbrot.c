/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 09:55:50 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:23:33 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"


static int	draw_mandelbrot(const t_vector2f *p, const size_t nb_iteration)
{
	size_t		i;
	t_vector2f	pt;
	t_vector2f	sqr;

	i = 0;
	pt.x = 0;
	pt.y = 0;
	sqr.x = 0;
	sqr.y = 0;
	while (i < nb_iteration && sqr.x + sqr.y < 4)
	{
		pt.y = pt.y * pt.x;
		pt.y += pt.y;
		pt.y += p->y;
		pt.x = sqr.x - sqr.y + p->x;
		sqr.x = (pt.x * pt.x);
		sqr.y = (pt.y * pt.y);
		i++;
	}
	if (i == nb_iteration)
		i = 0;
	return (i);
}

t_color	*draw_frac(t_uint32 x, t_uint32 y)
{
	t_vector2f	pt;
	t_color		*color;
	int			val;

	pt = vector2f(map((float)x, vector2f(0, WIN_WIDTH), vector2f(-2.3f, 1.3f)),
							map((float)y, vector2f(0, WIN_HEIGHT), vector2f(-1.8f, 1.8f)));
	val = draw_mandelbrot(&pt, 64);
	val = map(val, vector2f(0, 64), vector2f(0, 255));
	color = new_color(val, val, val, 255);
	return (color);
}
