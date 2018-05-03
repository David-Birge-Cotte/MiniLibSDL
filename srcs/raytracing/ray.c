/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:50:57 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/05/03 12:50:58 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

t_ray	new_ray(t_vector3d pos, t_vector3d dir)
{
	t_ray	ray;

	ray.pos = pos;
	ray.dir = dir;
	return (ray);
}

t_ray	ray_from_cam(t_camera cam, t_uint32 x, t_uint32 y)
{
	t_ray		ray;
	float		px;
	float		py;

	ray.pos = m_to_pos(cam.transform);
	ray.dir = v3d((double)(x - WIN_WIDTH / 2.0f) + ray.pos.x,
				(double)(y - WIN_HEIGHT / 2.0f) + ray.pos.y,
				(double)(-WIN_WIDTH / (2.0f * tanf(CAM_FOV / 2 * PI / 180)))
						+ ray.pos.z);
	ray.dir = m_vec_apply(ray.dir, cam.transform);
	ray.dir = v3d_unit(ray.dir);
	return (ray);
}
