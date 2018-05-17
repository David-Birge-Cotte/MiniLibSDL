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

t_bool	cone_intersect(const t_ray ray, const t_3dobject obj,
						t_hit_data *hit)
{
	double		a;
	double		b;
	double		c;
	double		delta;
	t_vector3d	eyedir;

	
	eyedir = v3d_sub(ray.pos, obj.pos);
	a = ray.dir.x * ray.dir.x + ray.dir.y * ray.dir.y - ray.dir.z * ray.dir.z;
	b = 2 * eyedir.x * ray.dir.x + 2 * eyedir.y * ray.dir.y
		- 2 * eyedir.z * ray.dir.z;
	c = pow(eyedir.x, 2) + pow(eyedir.y, 2) - pow(eyedir.z, 2);
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
	hit->normal = v3d_unit(v3d_sub(hit->pos, obj.pos));
	return (FALSE);
}
