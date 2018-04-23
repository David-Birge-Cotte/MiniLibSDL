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

#include "graphics.h"

/*
** Sets all the pixels of the frame to transparent
*/
void	clear_frame(t_uint32 *frame)
{
	int	size;

	size = WIN_WIDTH * WIN_HEIGHT * sizeof(t_uint32);
	ft_memset((void*)frame, 0, size);
}

/*
** Draws the frame (*pixels) to the SDL
*/
int		sdl_draw(t_sdl *sdl, t_uint32 *pixels)
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
void	put_pixel(t_uint32 *pixels, t_uint32 x, t_uint32 y, const t_color *color)
{
	if (x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	pixels[y * WIN_WIDTH + x] = color_to_pixeldata(color);
}
