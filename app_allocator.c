/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_allocator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:22:12 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:22:38 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

/*
** Starts a new app with an new sdl instance
*/
t_app	*new_app(void)
{
	t_app	*app;

	app = ft_memalloc(sizeof(t_app));
	app->pixels = ft_memalloc(sizeof(t_uint32) * WIN_HEIGHT * WIN_WIDTH);
	app->sdl = new_sdl();
	app->loop = TRUE;
	return (app);
}

/*
** Stops the app and the sdl instance then properly exit the program
*/
void		app_del(t_app *app)
{
	sdl_del(app->sdl);
	ft_memdel((void**)&app->pixels);
	ft_memdel((void**)&app);
}
