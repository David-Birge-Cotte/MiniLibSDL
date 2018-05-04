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

#include "../../includes/graphics.h"

/*
** Test a ray in the scene
*/

static t_bool	ray_hit(const t_ray *ray, const t_scene *scene, t_hit_data *hit)
{
	t_hit_data	hit_tmp;
	size_t		i;

	i = 0;
	while (i < scene->nb_obj)
	{
		if (scene->objs[i].inter(*ray, scene->objs[i].transform, &hit_tmp))
		{
			if (v3d_mag(v3d_sub(ray->pos, hit_tmp.pos))
				< v3d_mag(v3d_sub(ray->pos, hit->pos)))
			{
				*hit = hit_tmp;
				hit->mat = scene->objs[i].mat;
			}
		}
		i++;
	}
	if (hit->pos.x != INFINITY)
		return (TRUE);
	return (FALSE);
}

/*
** Test if intersection between origin and dest
*/

static t_bool	shadow_ray_hit(const t_vector3d origin, const t_vector3d dest,
					const t_scene *scene)
{
	t_hit_data	hit;
	t_ray		ray;

	hit.pos = v3d(INFINITY, INFINITY, INFINITY);
	ray = new_ray(origin, v3d_unit(v3d_sub(dest, origin)));
	ray.pos = v3d_add(ray.pos, v3d_scale(ray.dir, 0.05f));
	if (ray_hit(&ray, scene, &hit))
	{
		if (v3d_norm2(v3d_sub(ray.pos, hit.pos))
			< v3d_norm2(v3d_sub(ray.pos, dest)))
			return (TRUE);
	}
	return (FALSE);
}

/*
** Returns the color of the pixel x, y on the screen
** using the ray-tracing algorithm to compute visibility and shadows
*/

t_color			ray_trace(t_uint32 x, t_uint32 y, t_app *app)
{
	t_color		col;
	t_ray		primary_ray;
	t_hit_data	hit;
	double		shade;
	double		pix_i;

	hit.pos = v3d(INFINITY, INFINITY, INFINITY);
	col = to_color(BLACK);
	primary_ray = ray_from_cam(app->scene.camera, x, y);
	if (ray_hit(&primary_ray, &app->scene, &hit) == TRUE)
	{
		if (!shadow_ray_hit(hit.pos, app->scene.lights[0].pos, &app->scene))
		{
			shade = v3d_dot(v3d_unit(
				v3d_sub(app->scene.lights[0].pos, hit.pos)), hit.normal);
			if (shade < 0)
				shade = 0;
			pix_i = AMBIANT + (25 * app->scene.lights[0].intensity * shade
					/ v3d_mag(v3d_sub(app->scene.lights[0].pos, hit.pos)));
			col = color_mult(hit.mat.diffuse, pix_i);
		}
		else
			col = color_mult(hit.mat.diffuse, AMBIANT);
	}
	return (col);
}
