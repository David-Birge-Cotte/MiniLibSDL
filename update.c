#include "graphics.h"

/*
** Use this function to calculate the next frame
** Compute data and then draw to the pixels* frame
*/
void	calculate_frame(t_app *app)
{
	clear_frame(app->pixels);
	//draw_line(app->pixels, new_vector2i(0, 0), new_vector2i(WIN_WIDTH, WIN_HEIGHT), new_color(WHITE));
}

/*
** Applies a function on each pixel
** The function takes pixel coordonates t_uint32 x, y as arguments
*/
void	apply_fnc_to_each_pixel(t_uint32 *pixels, t_color *(*fnc_ptr)(t_uint32, t_uint32))
{
	t_uint32	x;
	t_uint32	y;

	x = 0;
	while(x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			put_pixel(pixels, x, y, fnc_ptr(x, y));
			y++;
		}
		x++;
	}
}