/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2i.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 08:57:52 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/26 08:57:54 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V2I_H
# define V2I_H

# include <math.h>

typedef struct		s_vector2i
{
	int				x;
	int				y;
}					t_vector2i;

t_vector2i			v2i(int x, int y);
t_vector2i			v2i_add(t_vector2i v1, t_vector2i v2);
t_vector2i			v2i_sub(t_vector2i v1, t_vector2i v2);
t_vector2i			v2i_unit(t_vector2i v);
t_vector2i			v2i_scale(t_vector2i v, float factor);
float				v2i_mag(t_vector2i v);
float				v2i_dot(t_vector2i v1, t_vector2i v2);
float				v2i_angle(t_vector2i v1, t_vector2i v2);

#endif
