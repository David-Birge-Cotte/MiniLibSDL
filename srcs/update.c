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
	t_multit_arg	arg;

	fill_frame(app->pixels, app->nb_pixels, to_color(BLACK));
	arg.app = app;
	arg.fnc_ptr = &ray_trace;
	threader(arg);
}

/*
** Applies a function on each pixel
** The function takes pixel coordonates t_uint32 x, y as arguments
** Not used when multithreading
*/

void	apply_fnc_to_each_pixel(t_app *app,
			t_color (*fnc_ptr)(t_uint32 x, t_uint32 y, t_app *app))
{
	t_uint32	x;
	t_uint32	y;
	t_color		col;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			col = fnc_ptr(x, y, app);
			put_pixel(app->pixels, x, y, &col);
			y++;
		}
		x++;
	}
}
