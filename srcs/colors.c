/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:52:21 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:23:26 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

/*
** Converts a t_color data structure to an uint32 (4 uint8)
*/

t_uint32		color_to_pixeldata(const t_color *color)
{
	t_uint32	col;

	col = 0;
	col |= (color->r << 24);
	col |= (color->g << 16);
	col |= (color->b << 8);
	col |= (color->a);
	return (col);
}

/*
** Creates a new pointer to color
*/

t_color			*new_color(t_uint8 r, t_uint8 g, t_uint8 b, t_uint8 a)
{
	t_color *color;

	color = ft_memalloc(sizeof(t_color));
	color->r = r;
	color->g = g;
	color->b = b;
	color->a = a;
	return (color);
}

/*
** Creates a new color
*/

t_color			to_color(t_uint8 r, t_uint8 g, t_uint8 b, t_uint8 a)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

/*
** Creates a new color, based on a linear interpolation between two colors
** with t == 0 : returns copy of start
** with t > 0 && t < 1 : returns linear interpolation of start and end at t
** with t == 1 : returns copy of end
*/

t_color			*lerp_color(const t_color *start, const t_color *end, float t)
{
	t_color *color;

	if (t > 1 || t < 0)
	{
		ft_putendl("Lerp error. t must be between 0 and 1");
		return (new_color(0, 0, 0, 0));
	}
	color = new_color(
		lerp(start->r, end->r, t),
		lerp(start->g, end->g, t),
		lerp(start->b, end->b, t),
		lerp(start->a, end->a, t));
	return (color);
}

/*
** Multiplies a color by a constant (between 0 and 1)
*/

t_color			color_mult(const t_color color, const float m)
{
	t_color	col;
	float	m_clamp;

	m_clamp = clampf(0, 1, m);
	col = to_color(color.r * m_clamp, color.g * m_clamp,
					color.b * m_clamp, color.a * m_clamp);
	return (col);
}
