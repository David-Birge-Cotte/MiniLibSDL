/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:59:36 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/05/02 10:59:36 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

static t_ray	ray_through_cam(t_camera cam, t_uint32 x, t_uint32 y)
{
	t_ray		ray;
	float		px;
	float		py;
	t_vector3d	view_plane_up_left;

	ray.pos = m_to_pos(cam.transform);
	px = (2 * ((x + 0.5) / WIN_WIDTH) - 1) * tanf(PI * 0.5f * 30 / 180);
	py = (1 - 2 * (y + 0.5) / WIN_HEIGHT) * tanf(PI * 0.5f * 30 / 180);
	ray.dir = v3d(px, py, -1);
	ray.dir = v3d_unit(ray.dir);
	return (ray);
}

static t_bool	ray_hit(const t_ray *ray, const t_scene *scene)
{
	t_bool	hit;
	size_t	i;

	hit = FALSE;
	i = 0;
	while (i < scene->nb_obj)
	{
		if (scene->objs[i].inter(*ray, scene->objs[i].transform) == TRUE)
			hit = TRUE;
		i++;
	}
	return (hit);
}

t_color			*ray_trace(t_uint32 x, t_uint32 y, t_app *app)
{
	t_color	*col;
	t_ray	primary_ray;
	t_ray	secondary_ray;

	col = new_color(BLACK);
	primary_ray = ray_through_cam(app->scene.camera, x, y);
	if (ray_hit(&primary_ray, &app->scene) == TRUE)
	{
		col = new_color(RED);
	}
	return (col);
}