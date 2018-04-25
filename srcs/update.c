/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:23:52 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:23:53 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

/*
** Use this function to calculate the next frame
** Compute data and then draw to the pixels* frame
*/

void	calculate_frame(t_app *app)
{
	static int	i = 0;
	t_color		*white;
	t_vector2i	left;
	t_vector2i	right;

	clear_frame(app->pixels, app->nb_pixels);

	if (i < WIN_WIDTH)
		i++;
	else
		i = 0;

	white = new_color(WHITE);
	left = v2i(i, i);
	right = v2i(WIN_WIDTH - i, WIN_HEIGHT - i);

	draw_line(app->pixels, left, right, white);
	ft_memdel((void**)&white);
}

/*
** Applies a function on each pixel
** The function takes pixel coordonates t_uint32 x, y as arguments
*/

void	apply_fnc_to_each_pixel(t_uint32 *pixels,
			t_color *(*fnc_ptr)(t_uint32, t_uint32))
{
	t_uint32	x;
	t_uint32	y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			put_pixel(pixels, x, y, fnc_ptr(x, y));
			y++;
		}
		x++;
	}
}
