/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2f.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 08:57:55 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/26 08:57:56 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V2F_H
# define V2F_H

# include <math.h>

typedef struct		s_vector2f
{
	float			x;
	float			y;
}					t_vector2f;

t_vector2f			v2f(float x, float y);
t_vector2f			v2f_add(t_vector2f v1, t_vector2f v2);
t_vector2f			v2f_sub(t_vector2f v1, t_vector2f v2);
t_vector2f			v2f_unit(t_vector2f v);
t_vector2f			v2f_scale(t_vector2f v, float factor);
float				v2f_mag(t_vector2f v);
float				v2f_dot(t_vector2f v1, t_vector2f v2);
float				v2f_angle(t_vector2f v1, t_vector2f v2);

#endif
