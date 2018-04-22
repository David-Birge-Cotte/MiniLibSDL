#include "graphics.h"

/*
** Creates a new sdl instance
*/
t_sdl	*new_sdl(void)
{
	t_sdl	*sdl;

	sdl = ft_memalloc(sizeof(t_sdl));
	SDL_Init(SDL_INIT_VIDEO);
	sdl->event = ft_memalloc(sizeof(SDL_Event));
	sdl->win = SDL_CreateWindow(WIN_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WIN_WIDTH, WIN_HEIGHT, 0);
	sdl->renderer = SDL_CreateRenderer(sdl->win, -1, 0);
	SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 255);
	sdl->frame = SDL_CreateTexture(sdl->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING,
			WIN_WIDTH, WIN_HEIGHT);
	SDL_SetTextureBlendMode(sdl->frame, SDL_BLENDMODE_BLEND);
	return (sdl);
}

/*
** Destroys the sdl instance
*/
void	sdl_del(t_sdl *sdl)
{
	SDL_DestroyTexture(sdl->frame);
	SDL_DestroyRenderer(sdl->renderer);
	SDL_DestroyWindow(sdl->win);
	ft_memdel((void**)&sdl->event);
	ft_memdel((void**)&sdl);
	SDL_Quit();
}