/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:56:50 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/26 15:56:50 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

#include "ft_math.h"

typedef struct	s_matrix
{
	float	m[4][4];
}				t_matrix;

t_matrix		m_new(float data[4][4]);
t_matrix		m_identity();
t_matrix		m_add(t_matrix m1, t_matrix m2);
t_matrix		m_scale(t_matrix m, float factor);
t_matrix		m_transpose(t_matrix m);

t_vector3d		m_pt_apply(t_vector3d v, t_matrix m);
t_vector3d		m_vec_apply(t_vector3d v, t_matrix m);

#endif
