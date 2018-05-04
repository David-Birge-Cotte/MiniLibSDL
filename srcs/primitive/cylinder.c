/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:38:37 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/05/04 14:38:38 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

t_bool	cylinder_intersect(const t_ray ray, const t_matrix transform,
						t_hit_data *hit)
{
	double		a;
	double		b;
	double		c;
	double		delta;
	t_vector2f	eyedir;

	eyedir = v2f_sub(v2f(ray.pos.x, ray.pos.z),
		v2f(m_to_pos(transform).x, m_to_pos(transform).z));
	a = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
	b = 2 * ray.dir.x * eyedir.x + 2 * ray.dir.z * eyedir.y;
	c = eyedir.x * eyedir.x + eyedir.y * eyedir.y
		- pow(m_to_scale(transform).x, 2);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (FALSE);
	hit->t2 = (-b + sqrt(delta)) / (2 * a);
	hit->t1 = (-b - sqrt(delta)) / (2 * a);
	if (hit->t1 > hit->t2)
		ft_swap(&hit->t1, &hit->t2);
	if (hit->t1 < 0)
		return (FALSE);
	hit->pos = v3d_add(ray.pos, v3d_scale(ray.dir, hit->t1));
	hit->normal = v3d_unit(v3d_sub(hit->pos, m_to_pos(transform)));
	return (TRUE);
}
