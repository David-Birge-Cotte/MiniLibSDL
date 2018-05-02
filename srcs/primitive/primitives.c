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


t_bool	sphere_intersect(const t_ray ray, const t_matrix transform)
{
	double		a;
	double		b;
	double		c;
	double		det;
	t_vector3d	sphere_pos;

	sphere_pos = m_to_pos(transform);
	a = pow(ray.dir.x, 2) + pow(ray.dir.y, 2) + pow(ray.dir.z, 2);
	b = 2 * (ray.dir.x * (ray.pos.x - sphere_pos.x) +
			ray.dir.y * (ray.pos.y - sphere_pos.y) +
			ray.dir.z * (ray.pos.z - sphere_pos.z));
	c = pow((ray.pos.x - sphere_pos.x), 2) +
		pow((ray.pos.y - sphere_pos.y), 2) +
		pow((ray.pos.z - sphere_pos.z), 2) - 1; // -1 for pow(radius, 2)
	det = pow(b, 2) - 4 * a * c;
	if (det >= 0)
		return (TRUE);
	return (FALSE);
}


/*
t_bool	sphere_intersect(const t_ray ray, const t_matrix transform)
{
	t_vector3d		l;
	double		tca;
	double 		d2;
	double		det;
	t_vector3d	sphere_pos;

	sphere_pos = m_to_pos(transform);
	l = v3d_add(sphere_pos, v3d(-ray.pos.x, -ray.pos.y, -ray.pos.z));
	tca = v3d_dot(l, ray.dir);
	d2 = v3d_dot(l, l) - tca * tca;
	if (d2 > 1)
		return (FALSE);
	return (TRUE);
}*/

t_bool	box_intersect(const t_ray ray, const t_matrix transform)
{
	return (FALSE);
}
