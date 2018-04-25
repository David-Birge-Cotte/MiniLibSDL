/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:23:34 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:23:36 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

static void	octant_one(const t_vector2i p1, const t_vector2i p2,
						t_uint32 *pixels, const t_color *color)
{
	int			e;
	int			dx;
	int			dy;
	t_vector2i	p1_cpy;

	p1_cpy = v2i(p1.x, p1.y);
	e = p2.x - p1.x;
	dy = (p2.y - p1.y) * 2;
	dx = e * 2;
	while (p1_cpy.x <= p2.x)
	{
		put_pixel(pixels, p1_cpy.x, p1_cpy.y, color);
		p1_cpy.x++;
		if ((e = e - dy) < 0)
		{
			p1_cpy.y++;
			e = e + dx;
		}
	}
}

static void	octant_two(const t_vector2i p1, const t_vector2i p2,
						t_uint32 *pixels, const t_color *color)
{
	int			e;
	int			dx;
	int			dy;
	t_vector2i	p1_cpy;

	p1_cpy = v2i(p1.x, p1.y);
	dx = (p2.x - p1.x) * 2;
	e = p2.y - p1.y;
	dy = e * 2;
	while (p1_cpy.y <= p2.y)
	{
		put_pixel(pixels, p1_cpy.x, p1_cpy.y, color);
		p1_cpy.y++;
		if ((e = e - dx) < 0)
		{
			p1_cpy.x++;
			e = e + dy;
		}
	}
}

static void	octant_seven(const t_vector2i p1, const t_vector2i p2,
							t_uint32 *pixels, const t_color *color)
{
	int			e;
	int			dx;
	int			dy;
	t_vector2i	p1_cpy;

	p1_cpy = v2i(p1.x, p1.y);
	dx = (p2.x - p1.x) * 2;
	e = p2.y - p1.y;
	dy = e * 2;
	while (p1_cpy.y >= p2.y)
	{
		put_pixel(pixels, p1_cpy.x, p1_cpy.y, color);
		p1_cpy.y--;
		if ((e = e + dx) > 0)
		{
			p1_cpy.x++;
			e = e + dy;
		}
	}
}

static void	octant_eight(const t_vector2i p1, const t_vector2i p2,
							t_uint32 *pixels, const t_color *color)
{
	int			e;
	int			dx;
	int			dy;
	t_vector2i	p1_cpy;

	p1_cpy = v2i(p1.x, p1.y);
	e = p2.x - p1.x;
	dy = (p2.y - p1.y) * 2;
	dx = e * 2;
	while (p1_cpy.x <= p2.x)
	{
		put_pixel(pixels, p1_cpy.x, p1_cpy.y, color);
		p1_cpy.x++;
		if ((e = e + dy) < 0)
		{
			p1_cpy.y--;
			e = e + dx;
		}
	}
}

void		draw_line(t_uint32 *pixels, t_vector2i p1, t_vector2i p2,
						const t_color *color)
{
	int			dx;
	int			dy;
	t_vector2i	tmp;

	if (p1.x > p2.x)
	{
		tmp = v2i(p2.x, p2.y);
		p2 = p1;
		p1 = tmp;
	}
	dx = p2.x - p1.x;
	if ((dy = p2.y - p1.y) > 0)
	{
		if (dx > dy)
			octant_one(p1, p2, pixels, color);
		else
			octant_two(p1, p2, pixels, color);
	}
	else
	{
		if (dx > -dy)
			octant_eight(p1, p2, pixels, color);
		else
			octant_seven(p1, p2, pixels, color);
	}
}
