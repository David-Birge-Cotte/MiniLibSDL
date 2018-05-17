/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:39:28 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/05/04 14:39:28 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

t_vector3d	cone_norm(t_3dobject obj, t_vector3d p)
{
	t_vector3d	n;
	t_vector3d	v;

	n.x = (p.x - obj.pos.x) * 1 / 0.5f;
	n.y = 0.5f / 1;
	n.z = (p.z - obj.pos.z) * 1 / 0.5f;
	return (v3d_unit(n));
}

t_bool	cone_intersect(const t_ray ray, const t_3dobject obj,
						t_hit_data *hit)
{
	double		a;
	double		b;
	double		c;
	double		delta;
	t_vector3d	eyedir;

	
	eyedir = v3d_sub(ray.pos, obj.pos);
	a = v3d_dot(ray.dir, ray.dir) - (1 + pow(tan(0.5f), 2)) *
		pow(v3d_dot(ray.dir, obj.rot), 2);
	b = 2 * (v3d_dot(ray.dir, eyedir) - (1 + pow(tan(0.5f), 2))
		* v3d_dot(ray.dir, obj.rot) * v3d_dot(eyedir, obj.rot));
	c = v3d_dot(eyedir, eyedir) - (1 +
		pow(tan(0.5f), 2)) * pow(v3d_dot(eyedir, obj.rot), 2);
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
	hit->normal = cone_norm(obj, hit->pos);
	return (TRUE);
}
