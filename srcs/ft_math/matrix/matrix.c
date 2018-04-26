/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:44:01 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/26 13:44:03 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_math/matrix.h"

/*
** Creates a new matrix from a 4x4 array
*/

t_matrix	m_new(float data[4][4])
{
	t_matrix	m;
	size_t		i;
	size_t		j;

	i = -1;
	j = -1;
	while (++i < 4)
		while (++j < 4)
			m.m[i][j] = data[i][j];
	return (m);
}

/*
** Returns a new matrix with its diagonal at 1
*/

t_matrix	m_identity()
{
	t_matrix	m;
	size_t		i;
	size_t		j;

	i = -1;
	j = -1;
	while (++i < 4)
		while (++j < 4)
			m.m[i][j] = (i == j ? 1 : 0);
	return (m);
}

/*
** Adds two matrix together
*/

t_matrix	m_add(t_matrix m1, t_matrix m2)
{
	t_matrix	m;
	size_t		i;
	size_t		j;

	i = -1;
	j = -1;
	while (++i < 4)
		while (++j < 4)
			m.m[i][j] = m1.m[i][j] + m2.m[i][j];
	return (m);
}

/*
** Scales a matrix by a factor
*/

t_matrix	m_scale(t_matrix m, float factor)
{
	size_t		i;
	size_t		j;

	i = -1;
	j = -1;
	while (++i < 4)
		while (++j < 4)
			m.m[i][j] *= factor;
	return (m);
}

/*
** Swap rows and column
*/

t_matrix	m_transpose(t_matrix m)
{
	t_matrix	t_m;
	size_t		i;
	size_t		j;

	i = -1;
	j = -1;
	while (++i < 4)
		while (++j < 4)
			t_m.m[i][j] = m.m[j][i];
	return (t_m);
}
