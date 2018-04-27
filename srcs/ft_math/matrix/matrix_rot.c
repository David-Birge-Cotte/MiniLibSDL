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
	t_matrix	ma;

	ma = m_identity();
	ma.m[1][1] = cosf(a);
	ma.m[1][2] = sinf(a);
	ma.m[2][1] = -sinf(a);
	ma.m[2][2] = cosf(a);
	return (ma);
}

static t_matrix	m_create_rot_y(float const a)
{
	t_matrix	ma;

	ma = m_identity();
	ma.m[0][0] = cosf(a);
	ma.m[0][2] = -sinf(a);
	ma.m[2][0] = sinf(a);
	ma.m[2][2] = cosf(a);
	return (ma);
}

static t_matrix	m_create_rot_z(float const a)
{
	t_matrix	ma;

	ma = m_identity();
	ma.m[0][0] = cosf(a);
	ma.m[0][1] = sinf(a);
	ma.m[1][0] = -sinf(a);
	ma.m[1][1] = cosf(a);
	return (ma);
}

t_matrix	m_rotate(t_matrix const m, t_vector3d const v)
{
	t_matrix	ma;

	ma = m_new(m.m);
	ma = m_mult(ma, m_create_rot_x(v.x));
	ma = m_mult(ma, m_create_rot_y(v.y));
	ma = m_mult(ma, m_create_rot_z(v.z));
	return (ma);
}