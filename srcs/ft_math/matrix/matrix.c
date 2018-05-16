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

t_matrix	m_new(const float data[4][4])
{
	t_matrix	m;
	size_t		i;
	size_t		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			m.m[i][j] = data[i][j];
	}
	return (m);
}

/*
** Returns a new matrix with its diagonal at 1
*/

t_matrix	m_identity(void)
{
	t_matrix	m;
	size_t		i;
	size_t		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			m.m[i][j] = (i == j ? 1 : 0);
	}
	return (m);
}

/*
** Swap rows and column
*/

t_matrix	m_transpose(const t_matrix m)
{
	t_matrix	ma;
	size_t		i;
	size_t		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			ma.m[i][j] = m.m[j][i];
	}
	return (ma);
}

void		m_print(const t_matrix m)
{
	size_t		i;
	size_t		j;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			printf("%f", m.m[i][j]);
			printf(" ");
		}
		printf("\n");
	}
}
