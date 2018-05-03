/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:14:08 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/05/02 16:14:08 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

/*
** Solves a * t^2 + b*t + c = 0
*/

t_bool	sphere_intersect(const t_ray ray, const t_matrix transform,
							t_hit_data *hit)
{
	double		a;
	double		b;
	double		c;
	double		delta;
	double		t;

	a = v3d_norm2(ray.dir);
	b = 2 * v3d_dot(ray.dir, v3d_sub(ray.pos, m_to_pos(transform)));
	c = v3d_norm2(v3d_sub(ray.pos, m_to_pos(transform)))
					- pow(m_to_scale(transform).x, 2);
	delta = pow(b, 2) - 4 * a * c;
	if (delta < 0)
		return (FALSE);
	if ((-b - sqrt(delta)) / (2 * a) > 0)
		t = (-b - sqrt(delta)) / (2 * a);
	else
		t = (-b + sqrt(delta)) / (2 * a);
	hit->pos = v3d_add(ray.pos, v3d_scale(ray.dir, t));
	hit->normal = v3d_unit(v3d_sub(hit->pos, m_to_pos(transform)));
	hit->t = t;
	return (TRUE);
}

t_bool	plane_intersect(const t_ray ray, const t_matrix transform,
						t_hit_data *hit)
{
	return (FALSE);
}
