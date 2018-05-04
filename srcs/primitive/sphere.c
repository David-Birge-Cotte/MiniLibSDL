/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:38:25 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/05/04 14:38:26 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

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
	delta = b * b - 4 * a * c;
	if (delta < 0 || (hit->t2 = (-b + sqrt(delta)) / (2 * a) < 0))
		return (FALSE);
	hit->t1 = (-b - sqrt(delta)) / (2 * a);
	if (hit->t1 > 0)
		t = hit->t1;
	else
		t = hit->t2;
	hit->pos = v3d_add(ray.pos, v3d_scale(ray.dir, t));
	hit->normal = v3d_unit(v3d_sub(hit->pos, m_to_pos(transform)));
	return (TRUE);
}
