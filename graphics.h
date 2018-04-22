#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <stdio.h>
# include <SDL2/SDL.h>
# include "libft/libft.h"

# define WIN_WIDTH (512)
# define WIN_HEIGHT (512)
# define WIN_TITLE "Window Title"

typedef unsigned int	t_uint32;
typedef unsigned char	t_uint8;

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct		s_perlin
{
	unsigned int	seed;
	float			freq;
	float			depth;
}					t_perlin;

typedef struct		s_vector2i
{
	int				x;
	int				y;
}					t_vector2i;

typedef struct		s_vector2f
{
	int				x;
	int				y;
}					t_vector2f;

typedef struct		s_color
{
	t_uint8			r;
	t_uint8			g;
	t_uint8			b;
	t_uint8			a;
}					t_color;

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Texture		*frame;
	SDL_Event		*event;
}					t_sdl;

typedef struct		s_app
{
	t_bool			loop;
	t_uint32		*pixels;
	t_sdl			*sdl;
}					t_app;

/*
** Math
*/
t_vector2i		*new_vector2i(int x, int y);
t_vector2i		vector2i(int x, int y);
t_vector2f		*new_vector2f(float x, float y);
t_vector2f		vector2f(float x, float y);
float			lerp(const float start, const float end, const float t);
float			map(float input, t_vector2f input_range, t_vector2f output_range);

/*
** Colors
*/
t_uint32		color_to_pixeldata(const t_color *color);
t_color			*new_color(t_uint8 r, t_uint8 g, t_uint8 b, t_uint8 a);
t_color			*copy_color(const t_color *color_cpy);
t_color			*lerp_color(const t_color *start, const t_color *end, float t);

/*
** app &SDL
*/
t_app			*new_app(void);
void			app_del(t_app *app);
t_sdl			*new_sdl(void);
void			sdl_del(t_sdl *sdl);
void			quit_app(void);

/*
** Events
*/
void			handle_event(t_app *app);
void			calculate_frame(t_app *app);


/*
** Draw
*/
void			clear_frame(t_uint32 *frame);
int				sdl_draw(t_sdl *sdl, t_uint32 *pixels);
void			put_pixel(t_uint32 *pixels, const t_vector2i *point,
					const t_color *color);
void			draw_line(t_uint32 *pixels, const t_vector2i *p1,
						const t_vector2i *p2, const t_color *color);

#endif