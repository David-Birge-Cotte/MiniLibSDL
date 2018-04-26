/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 09:28:18 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/26 09:28:19 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_math/v3d.h"

float		v3d_dot(t_vector3d v1, t_vector3d v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

float		v3d_angle(t_vector3d v1, t_vector3d v2)
{
	return (acosf(v3d_dot(v1, v2) / (v3d_mag(v1) * v3d_mag(v2))));
}

float		v3d_mag(t_vector3d v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vector3d	v3d_cross(t_vector3d v1, t_vector3d v2)
{
	return (v3d(
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x));
}