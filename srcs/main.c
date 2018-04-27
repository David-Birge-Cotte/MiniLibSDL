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
	//calculate_frame(app);
	display(app->sdl, app->pixels);
}

/*
** Function called once before the loop starts
*/

static void			start(t_app *app)
{
	t_mesh	box;

	box = create_box(5, 5, 2);
	box.transform = m_translate(box.transform, v3d(5, 0, 0));
	box.transform = m_rotate(box.transform, v3d(0, 45, 0));
	app->scene.camera.transform = m_identity();
	app->scene.camera.projection = m_identity();
	app->scene.objs = (t_mesh*)ft_memalloc(sizeof(t_mesh) * 1);
	app->scene.objs[0] = box;
	app->scene.nb_obj = 1;

	//m_print(box.transform);

	draw_mesh(app->pixels, box);
}

/*
** The entry point of the program
*/

int					main(void)
{
	t_app		*app;

	if ((app = new_app()) == NULL)
		return (-1);
	start(app);
	while (app->loop)
		loop(app);
	app_del(app);
	return (0);
}
