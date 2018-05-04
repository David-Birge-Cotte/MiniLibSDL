/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:38:31 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/05/04 14:38:32 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

t_bool	plane_intersect(const t_ray ray, const t_matrix transform,
						t_hit_data *hit)
{
	float		delta;

	hit->normal = m_vec_apply(v3d(0, 1, 0), transform);
	delta = v3d_dot(ray.dir, hit->normal);
	if (fabsf(delta) < 0.0001f)
		return (FALSE);
	hit->t1 = v3d_dot(v3d_sub(m_to_pos(transform), ray.pos),
										hit->normal) / delta;
	hit->pos = v3d_add(ray.pos, v3d_scale(ray.dir, hit->t1));
	if (hit->t1 < 0)
		return (FALSE);
	return (TRUE);
}