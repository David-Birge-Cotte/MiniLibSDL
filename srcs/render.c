/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:23:45 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:23:47 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

/*
** Sets all the pixels of the frame to a color
*/

void	fill_frame (t_uint32 *pixels, size_t nb_pixels, t_color *color)
{
	t_uint32	pixel_color;
	
	pixel_color = color_to_pixeldata(color);
	ft_memset((void*)pixels, pixel_color, (size_t)(nb_pixels * sizeof(t_uint32)));
}

/*
** Sets all the pixels of the frame to a 0 (transparent)
*/

void	clear_frame(t_uint32 *pixels, size_t nb_pixels)
{
	t_color	*transparent;

	transparent = new_color(TRANSP);
	fill_frame(pixels, nb_pixels, transparent);
	ft_memdel((void**)&transparent);
}

/*
** Draws the frame (*pixels) to the SDL
*/

int		display(t_sdl *sdl, t_uint32 *pixels)
{
	size_t	win_size;

	win_size = WIN_WIDTH * sizeof(t_uint32);
	if (SDL_UpdateTexture(sdl->frame, NULL, pixels, win_size) == -1)
		return (-1);
	if (SDL_RenderClear(sdl->renderer) == -1)
		return (-1);
	if (SDL_RenderCopy(sdl->renderer, sdl->frame, NULL, NULL) == -1)
		return (-1);
	SDL_RenderPresent(sdl->renderer);
	return (0);
}

/*
** changes the color of a pixel in a frame (*pixels)
*/

void	put_pixel(t_uint32 *pixels, t_uint32 x, t_uint32 y,
					const t_color *color)
{
	if (x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	pixels[y * WIN_WIDTH + x] = color_to_pixeldata(color);
}
