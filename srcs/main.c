/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:23:38 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:23:40 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

/*
** This is the main loop
*/

static void			loop(t_app *app)
{
	handle_event(app);
	display(app->sdl, app->pixels);
}

/*
** Function called once before the loop starts
*/

static int			start(t_app *app, char *file)
{
	if (load_scene(file, app) < 0)
		return (-1);
	calculate_frame(app);
	if (display(app->sdl, app->pixels) == -1)
		return (-1);
	return (1);
}

/*
** The entry point of the program
*/

int					main(int argc, char **argv)
{
	t_app		*app;

	if ((app = new_app()) == NULL)
		return (-1);
	if (start(app, argv[1]) < 0)
		return (-1);
	while (app->loop)
		loop(app);
	app_del(app);
	return (0);
}
