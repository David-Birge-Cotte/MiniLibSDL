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

t_matrix	m_translate(const t_vector3d v)
{
	t_matrix	m;

	m = m_identity();
	m.m[0][3] = v.x;
	m.m[1][3] = v.y;
	m.m[2][3] = v.z;
	return (m);
}

/*
** Adds two matrix together
*/

t_matrix	m_add(const t_matrix m1, const t_matrix m2)
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

t_matrix	m_mult(const t_matrix m1, const t_matrix m2)
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

t_matrix	m_scale(const t_vector3d v)
{
	t_matrix	m;

	m = m_identity();
	m.m[0][0] *= v.x;
	m.m[1][1] *= v.y;
	m.m[2][2] *= v.z;
	return (m);
}
