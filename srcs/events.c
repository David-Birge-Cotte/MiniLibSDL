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

/*
** key press (one frame)
*/

static void	keypress(t_app *app, int keycode)
{
	if (keycode == SDLK_ESCAPE)
		app->loop = FALSE;
}

/*
** Key down (multiple frame possible)
*/

static void	keydown(const t_uint8 *state, t_scene *scene)
{
	scene->camera.pos = v3d_add(scene->camera.pos, v3d(
		MOVE_SPEED * state[SDL_SCANCODE_D] - MOVE_SPEED * state[SDL_SCANCODE_A],
		MOVE_SPEED * state[SDL_SCANCODE_E] - MOVE_SPEED * state[SDL_SCANCODE_Q],
		MOVE_SPEED * state[SDL_SCANCODE_W] - MOVE_SPEED * state[SDL_SCANCODE_S]));
	scene->camera.rot = v3d_add(scene->camera.rot, v3d(
		TURN_SPEED * PI / 180 * state[SDL_SCANCODE_UP]
			- TURN_SPEED * PI / 180 * state[SDL_SCANCODE_DOWN],
		TURN_SPEED * PI / 180 * state[SDL_SCANCODE_LEFT]
			- TURN_SPEED * PI / 180 * state[SDL_SCANCODE_RIGHT], 0));
}

/*
** Listens to event and responds to them
*/

void		handle_event(t_app *app)
{
	const t_uint8	*state;
	int				nb_keys;

	while (SDL_PollEvent(app->sdl->event))
	{
		if (app->sdl->event->type == SDL_QUIT)
			app->loop = FALSE;
		else if (app->sdl->event->type == SDL_KEYDOWN)
			keypress(app, app->sdl->event->key.keysym.sym);
	}
	nb_keys = 0;
	state = SDL_GetKeyboardState(&nb_keys);
	if (nb_keys != 0)
	{
		keydown(state, &app->scene);
		calculate_frame(app);
	}
}
