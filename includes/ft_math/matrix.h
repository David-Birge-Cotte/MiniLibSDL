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

# include "ft_math.h"

typedef struct	s_matrix
{
	float	m[4][4];
}				t_matrix;

t_matrix		m_identity();
t_matrix		m_new(const float data[4][4]);
t_matrix		m_transpose(const t_matrix m);
t_matrix		m_add(const t_matrix m1, const t_matrix m2);
t_matrix		m_mult(const t_matrix m1, const t_matrix m2);
t_matrix		m_scale(const t_vector3d v);
t_matrix		m_translate(const t_vector3d v);
t_matrix		m_rotate(const t_vector3d v);
t_vector3d		m_pt_apply(const t_vector3d v, const t_matrix m);
t_vector3d		m_vec_apply(const t_vector3d v, const t_matrix m);
t_vector3d		m_to_pos(const t_matrix m);
t_vector3d		m_to_scale(const t_matrix m);
t_vector3d		m_to_rot(const t_matrix m);
t_matrix		m_create_rot_x(const float a);
t_matrix		m_create_rot_y(const float a);
t_matrix		m_create_rot_z(const float a);
void			m_print(const t_matrix m);

#endif
