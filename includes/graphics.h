/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:27:21 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:27:23 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

/*
** Required libraries
*/
# include <SDL2/SDL.h>
# include "../libft/libft.h"
# include "ft_math.h"

/*
** optionnal libraries
*/
# include <stdio.h>

/*
** Window settings
*/
# define WIN_WIDTH (1024)
# define WIN_HEIGHT (1024)
# define WIN_TITLE "Window Title"

/*
** Easy access simple colors RGBA8888
*/
# define WHITE	255	, 255	, 255	, 255
# define BLACK	0	, 0		, 0		, 255
# define RED	255	, 0		, 0		, 255
# define GREEN	0	, 255	, 0		, 255
# define BLUE	0	, 0		, 255	, 255
# define TRANSP	0	, 0		, 0		, 0

/*
** Boolean type 0 = FALSE, 1 = TRUE
*/
typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

/*
** 32 bit color structure RGBA8888
*/
typedef struct		s_color
{
	t_uint8			r;
	t_uint8			g;
	t_uint8			b;
	t_uint8			a;
}					t_color;

/*
** This data structure is used to store custom game/app data
*/
typedef struct		s_data
{
	t_uint32		score;
}					t_data;

/*
** Contains the bare minimum for communicating with the SDL library
*/
typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Texture		*frame;
	SDL_Event		*event;
}					t_sdl;

/*
** App structure instantiated in main()
*/
typedef struct		s_app
{
	t_bool			loop;
	t_uint32		*pixels;
	size_t			nb_pixels;
	t_sdl			*sdl;
	t_data			*data;
}					t_app;

/*
** Colors
*/
t_uint32		color_to_pixeldata(const t_color *color);
t_color			*new_color(t_uint8 r, t_uint8 g, t_uint8 b, t_uint8 a);
t_color			*copy_color(const t_color *color_cpy);
t_color			*lerp_color(const t_color *start, const t_color *end, float t);

/*
** Events
*/
void			handle_event(t_app *app);


/*
** Draw
*/
void			calculate_frame(t_app *app);
void			apply_fnc_to_each_pixel(t_uint32 *pixels, t_color *(*fnc_ptr)(t_uint32, t_uint32));
void			clear_frame(t_uint32 *pixels, size_t nb_pixels);
void			fill_frame (t_uint32 *pixels, size_t nb_pixels, t_color *color);
int				display(t_sdl *sdl, t_uint32 *pixels);
void			put_pixel(t_uint32 *pixels, t_uint32 x, t_uint32 y, const t_color *color);
void			draw_line(t_uint32 *pixels, t_vector2i p1, t_vector2i p2, const t_color *color);
t_color			*draw_frac(t_uint32 x, t_uint32 y);

/*
** App & SDL
*/
t_app			*new_app(void);
void			app_del(t_app *app);
t_sdl			*new_sdl(void);
void			sdl_del(t_sdl *sdl);
void			quit_app(void);

/*
** Fractal (use for test with apply_fnc_to_each_pixel())
*/
t_color			*draw_frac(t_uint32 x, t_uint32 y);

#endif
