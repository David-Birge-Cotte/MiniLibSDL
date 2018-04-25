/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:04:30 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/25 15:04:30 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>

typedef struct		s_vector2i
{
	int				x;
	int				y;
}					t_vector2i;

typedef struct		s_vector2f
{
	float			x;
	float			y;
}					t_vector2f;

t_vector2i		v2i(int x, int y);
t_vector2i		v2i_add(t_vector2f v1, t_vector2f v2);
t_vector2i		v2i_sub(t_vector2f v1, t_vector2f v2);
float			v2i_magnitude(t_vector2i v);

t_vector2f		v2f(float x, float y);
t_vector2f		v2f_add(t_vector2f v1, t_vector2f v2);
t_vector2f		v2f_sub(t_vector2f v1, t_vector2f v2);
float			v2f_magnitude(t_vector2f v);

float			lerp(const float start, const float end, const float t);
float			map(float input, t_vector2f input_range, t_vector2f output_range);
int				clampi(int min, int max, int val);
float			clampf(float min, float max, float val);
