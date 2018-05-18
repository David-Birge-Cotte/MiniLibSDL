/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 09:36:11 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/27 09:36:11 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_math/matrix.h"

t_matrix	m_create_rot_x(const float a)
{
	t_matrix	m;

	m = m_identity();
	m.m[1][1] = cosf(a);
	m.m[1][2] = sinf(a);
	m.m[2][1] = -sinf(a);
	m.m[2][2] = cosf(a);
	return (m);
}

t_matrix	m_create_rot_y(const float a)
{
	t_matrix	m;

	m = m_identity();
	m.m[0][0] = cosf(a);
	m.m[0][2] = -sinf(a);
	m.m[2][0] = sinf(a);
	m.m[2][2] = cosf(a);
	return (m);
}

t_matrix	m_create_rot_z(const float a)
{
	t_matrix	m;

	m = m_identity();
	m.m[0][0] = cosf(a);
	m.m[0][1] = sinf(a);
	m.m[1][0] = -sinf(a);
	m.m[1][1] = cosf(a);
	return (m);
}

t_matrix	m_rotate(const t_vector3d v)
{
	t_matrix	m;
	t_matrix	m_x;
	t_matrix	m_y;
	t_matrix	m_z;

	m_x = m_create_rot_x(v.x);
	m_y = m_create_rot_y(v.y);
	m_z = m_create_rot_z(v.z);
	m = m_mult(m_mult(m_x, m_y), m_z);
	return (m);
}
