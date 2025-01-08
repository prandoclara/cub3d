/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:09:02 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 10:51:14 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_parse(t_cub *cub)
{
	t_parse	*parse;

	parse = malloc(sizeof(t_parse) * 1);
	if (!parse)
		return (error_handler(17), 1);
	cub->parse = parse;
	cub->parse->files = NULL;
	cub->parse->fd = 0;
	cub->parse->map = NULL;
	cub->parse->copy_map = NULL;
	cub->parse->north_path = NULL;
	cub->parse->south_path = NULL;
	cub->parse->east_path = NULL;
	cub->parse->west_path = NULL;
	cub->parse->texture_north = NULL;
	cub->parse->texture_south = NULL;
	cub->parse->texture_west = NULL;
	cub->parse->texture_east = NULL;
	cub->parse->rgb_sky = NULL;
	cub->parse->rgb_floor = NULL;
	cub->parse->str_r = NULL;
	cub->parse->str_g = NULL;
	cub->parse->str_b = NULL;
	cub->parse->start_m = 0;
	return (0);
}

int	init_game_s(t_cub *cub)
{
	t_game	*game;

	game = malloc(sizeof(t_game) * 1);
	if (!game)
		return (error_handler(17), 1);
	cub->game = game;
	cub->game->mlx_ptr = NULL;
	cub->game->mlx_win_ptr = NULL;
	cub->game->east_texture = NULL;
	cub->game->west_texture = NULL;
	cub->game->north_texture = NULL;
	cub->game->south_texture = NULL;
	cub->game->rgb_floor = 0;
	cub->game->rgb_sky = 0;
	return (0);
}

int	init_image(t_cub *cub)
{
	t_image	*img;

	img = malloc(sizeof(t_image) * 1);
	if (!img)
		return (error_handler(17), 1);
	cub->image = img;
	cub->image->tex_x = 0;
	cub->image->tex_y = 0;
	cub->image->offset = 0;
	cub->image->step = 0;
	cub->image->tex_w = 64;
	cub->image->tex_h = 64;
	cub->image->line_bytes = 0;
	cub->image->tex_pos = 0;
	cub->image->pixels = 0;
	cub->image->img_ptr = NULL;
	cub->image->addr = NULL;
	cub->image->bits_per_pixel = 0;
	cub->image->line_length = 0;
	cub->image->endian = 0;
	return (0);
}

int	init_minimap(t_cub *cub)
{
	t_minimap	*minimap;

	minimap = malloc(sizeof(t_minimap) * 1);
	if (!minimap)
		return (error_handler(17), 1);
	cub->minimap = minimap;
	cub->minimap->map_img = NULL;
	return (0);
}

int	init_textures(t_cub *cub)
{
	t_textures	*tex;
	int			i;

	i = 0;
	while (i < 4)
	{
		tex = malloc(sizeof(t_textures) * 1);
		if (!tex)
			return (error_handler(17), 1);
		cub->image->textures[i] = tex;
		tex->endian = 0;
		tex->bits_per_pixel = 0;
		tex->line_length = 0;
		tex->addr = 0;
		tex->xpm = NULL;
		tex->pixels = NULL;
		i++;
	}
	return (0);
}
