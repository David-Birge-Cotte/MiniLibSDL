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

static t_matrix	m_create_rot_x(float const a)
{
	t_matrix	m;

	m = m_identity();
	m.m[1][1] = cosf(a);
	m.m[1][2] = sinf(a);
	m.m[2][1] = -sinf(a);
	m.m[2][2] = cosf(a);
	return (m);
}

static t_matrix	m_create_rot_y(float const a)
{
	t_matrix	m;

	m = m_identity();
	m.m[0][0] = cosf(a);
	m.m[0][2] = -sinf(a);
	m.m[2][0] = sinf(a);
	m.m[2][2] = cosf(a);
	return (m);
}

static t_matrix	m_create_rot_z(float const a)
{
	t_matrix	m;

	m = m_identity();
	m.m[0][0] = cosf(a);
	m.m[0][1] = sinf(a);
	m.m[1][0] = -sinf(a);
	m.m[1][1] = cosf(a);
	return (m);
}

t_matrix	m_rotate(t_vector3d const v)
{
	t_matrix	m;

	m = m_identity();
	m = m_mult(m, m_create_rot_x(v.x));
	m = m_mult(m, m_create_rot_y(v.y));
	m = m_mult(m, m_create_rot_z(v.z));
	return (m);
}