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


t_bool	cylinder_intersect(t_ray ray, const t_3dobject obj,
						t_hit_data *hit)
{
	double		a;
	double		b;
	double		c;
	double		delta;
	t_vector3d	eyedir;

	eyedir = v3d_sub(ray.pos, obj.pos);
	v3d_unit(obj.rot);

	a = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
	b = 2 * ray.dir.x * (ray.pos.x - obj.pos.x) +
		2 * ray.dir.z * (ray.pos.z - obj.pos.z);
	c = (ray.pos.x - obj.pos.x) * (ray.pos.x - obj.pos.x) +
		(ray.pos.z - obj.pos.z) * (ray.pos.z - obj.pos.z) - 1;

	
	/*a = v3d_dot(ray.dir, ray.dir) + pow(v3d_dot(ray.dir, obj.rot), 2);
	b = 2 * (v3d_dot(ray.dir, eyedir) -
		(v3d_dot(ray.dir, obj.rot) * v3d_dot(eyedir, obj.rot)));
	c = v3d_dot(eyedir, eyedir) -
		pow(v3d_dot(eyedir, obj.rot), 2) - pow(1, 2);*/
	
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
	//hit->normal = v3d_sub(v3d_sub(hit->pos, obj.pos),
	//		v3d_scale(obj.rot, (v3d_dot(ray.dir, obj.rot) * hit->t1 + v3d_dot(eyedir, obj.rot))));
	return (TRUE);
}
