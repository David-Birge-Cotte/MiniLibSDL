/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 10:08:02 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/05/04 10:08:03 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

void				apply_fnc_from_to_pixel(t_multit_arg *arg)
{
	t_uint32	x;
	t_uint32	y;
	t_color		col;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = arg->y_min;
		while (y < arg->y_max)
		{
			col = arg->fnc_ptr(x, y, arg->app);
			put_pixel(arg->app->pixels, x, y, &col);
			y++;
		}
		x++;
	}
	ft_memdel((void**)&arg);
}

static t_multit_arg	*cpy_arg(t_multit_arg arg)
{
	t_multit_arg	*new_arg;

	new_arg = ft_memalloc(sizeof(t_multit_arg));
	new_arg->app = arg.app;
	new_arg->fnc_ptr = arg.fnc_ptr;
	return (new_arg);
}

void				threader(t_multit_arg arg)
{
	size_t			i;
	SDL_Thread		**threads;
	t_multit_arg	*spearg;

	i = 0;
	threads = ft_memalloc(sizeof(SDL_Thread*) * 4);
	while (i < 4)
	{
		spearg = cpy_arg(arg);
		spearg->y_min = i * WIN_HEIGHT / 4;
		spearg->y_max = (i + 1) * WIN_HEIGHT / 4;
		threads[i] = SDL_CreateThread((void*)apply_fnc_from_to_pixel,
						"thread", (void *)(spearg));
		i++;
	}
	i = 0;
	while (i < 4)
		SDL_WaitThread(threads[i++], NULL);
}
