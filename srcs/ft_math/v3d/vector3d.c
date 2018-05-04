/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 09:28:15 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/26 09:28:17 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_math/v3d.h"

t_vector3d	v3d(double x, double y, double z)
{
	t_vector3d	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vector3d	v3d_add(t_vector3d v1, t_vector3d v2)
{
	return (v3d(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vector3d	v3d_sub(t_vector3d v1, t_vector3d v2)
{
	return (v3d(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vector3d	v3d_unit(t_vector3d v)
{
	float		mag;

	mag = v3d_mag(v);
	return (v3d(v.x / mag, v.y / mag, v.z / mag));
}

t_vector3d	v3d_scale(t_vector3d v, float factor)
{
	return (v3d(v.x * factor, v.y * factor, v.z * factor));
}
