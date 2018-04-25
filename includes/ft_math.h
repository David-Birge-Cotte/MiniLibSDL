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


t_vector2i		*new_vector2i(int x, int y);
t_vector2i		vector2i(int x, int y);
t_vector2f		*new_vector2f(float x, float y);
t_vector2f		vector2f(float x, float y);
float			lerp(const float start, const float end, const float t);
float			map(float input, t_vector2f input_range, t_vector2f output_range);
int				clampi(int min, int max, int val);
float			clampf(float min, float max, float val);
