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
	calculate_frame(app);
	display(app->sdl, app->pixels);
}

/*
** The entry point of the program
*/

int					main(void)
{
	t_app		*app;

	if ((app = new_app()) == NULL)
		return (-1);
	while (app->loop)
		loop(app);
	app_del(app);
	return (0);
}