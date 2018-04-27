/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 09:05:25 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/27 09:05:25 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_math/matrix.h"

/*
** Translates a matrix
*/

static t_matrix	m_create_translation(t_vector3d const v)
{
	t_matrix	m;

	m = m_identity();
	m.m[0][3] = v.x;
	m.m[1][3] = v.y;
	m.m[2][3] = v.z;
	return (m);
}

t_matrix	m_translate(t_matrix const m, t_vector3d const v)
{
	t_matrix	ma;

	ma = m_mult(m, m_create_translation(v));
	return (ma);
}

/*
** Adds two matrix together
*/

t_matrix	m_add(t_matrix const m1, t_matrix const m2)
{
	t_matrix	m;
	size_t		i;
	size_t		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			m.m[i][j] = m1.m[i][j] + m2.m[i][j];
	}
	return (m);
}

/*
** Multiply two matrix together
*/

t_matrix	m_mult(t_matrix const m1, t_matrix const m2)
{
	t_matrix	m;
	size_t		i;
	size_t		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			m.m[i][j] = m1.m[i][0] * m2.m[0][j] +
						m1.m[i][1] * m2.m[1][j] +
						m1.m[i][2] * m2.m[2][j] +
						m1.m[i][3] * m2.m[3][j];
	}
	return (m);
}

/*
** Scales a matrix by a vector
*/

t_matrix	m_scale(t_matrix const m, t_vector3d const v)
{
	t_matrix	ma;

	ma = m_new(m.m);
	ma.m[0][0] *= v.x;
	ma.m[1][1] *= v.y;
	ma.m[2][2] *= v.z;
	return (ma);
}
