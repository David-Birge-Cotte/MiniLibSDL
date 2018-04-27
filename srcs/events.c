/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:23:28 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:23:30 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

static void	keydown(t_app *app, int keycode)
{
	if (keycode == SDLK_ESCAPE)
		app->loop = FALSE;
}

/*
** Listens to event and responds to them
*/

void		handle_event(t_app *app)
{
	if (SDL_PollEvent(app->sdl->event) == 0)
		return ;
	if (app->sdl->event->type == SDL_QUIT)
		app->loop = FALSE;
	else if (app->sdl->event->type == SDL_KEYDOWN)
		keydown(app, app->sdl->event->key.keysym.sym);
}
