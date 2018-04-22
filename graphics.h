#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <stdio.h>
# include <SDL2/SDL.h>
# include "libft/libft.h"

# define WIN_WIDTH (512)
# define WIN_HEIGHT (512)
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

typedef unsigned int	t_uint32;
typedef unsigned char	t_uint8;

/*
** Boolean type 0 = FALSE, 1 = TRUE
*/
typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

/*
** Todo, not implemented yet
*/
typedef struct		s_perlin
{
	unsigned int	seed;
	float			freq;
	float			depth;
}					t_perlin;

/*
** Vectors2 in int (i) and float (f)
*/
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
	t_sdl			*sdl;
	t_data			*data;
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
int				clampi(int min, int max, int val);
float			clampf(float min, float max, float val);

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
void			apply_fnc_to_each_pixel(t_uint32 *pixels, t_color *(*fnc_ptr)(t_uint32, t_uint32));
void			clear_frame(t_uint32 *frame);
int				sdl_draw(t_sdl *sdl, t_uint32 *pixels);
void			put_pixel(t_uint32 *pixels, t_uint32 x, t_uint32 y, const t_color *color);
void			draw_line(t_uint32 *pixels, const t_vector2i *p1,
						const t_vector2i *p2, const t_color *color);

int				draw_mandelbrot(const t_vector2f *p, const size_t nb_iteration);
t_color			*draw_frac(t_uint32 x, t_uint32 y);

#endif