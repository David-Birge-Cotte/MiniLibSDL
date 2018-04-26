/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 08:58:04 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/26 08:58:09 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V3D_H
# define V3D_H

# include <math.h>

typedef struct		s_vector3d
{
	double			x;
	double			y;
	double			z;
}					t_vector3d;

typedef struct		s_coord_v3d
{
	t_vector3d	x;
	t_vector3d	y;
	t_vector3d	z;
}					t_coord_v3d;

t_vector3d			v3d(double x, double y, double z);
t_vector3d			v3d_add(t_vector3d v1, t_vector3d v2);
t_vector3d			v3d_sub(t_vector3d v1, t_vector3d v2);
t_vector3d			v3d_scale(t_vector3d v, float factor);
t_vector3d			v3d_unit(t_vector3d v);
float				v3d_mag(t_vector3d v);
float				v3d_dot(t_vector3d v1, t_vector3d v2);
float				v3d_angle(t_vector3d v1, t_vector3d v2);
t_vector3d			v3d_cross(t_vector3d v1, t_vector3d v2);

t_coord_v3d			coord_frame(t_vector3d v1, t_vector3d v2);

#endif
 