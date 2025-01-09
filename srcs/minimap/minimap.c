/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:58:06 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 16:44:24 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line_from_player(t_cub *cub, double agl, double maxlen, int color)
{
	init_draw_line_from_player(cub);
	while (cub->minimap->traveled_length < maxlen)
	{
		my_put_pixel_to_image2(cub, (int)cub->minimap->current_y,
			(int)cub->minimap->current_x, color);
		cub->minimap->map_x = (int)(cub->minimap->current_x / (8));
		cub->minimap->map_y = (int)(cub->minimap->current_y / (8));
		if (cub->parse->map[cub->minimap->map_x][cub->minimap->map_y] == '1')
			break ;
		cub->minimap->current_x += cos(agl) * cub->minimap->step;
		cub->minimap->current_y += sin(agl) * cub->minimap->step;
		cub->minimap->traveled_length += cub->minimap->step;
	}
}

void	draw_fov(t_cub *cub)
{
	int		i;
	int		width;
	double	agl_step;
	double	current_agl;

	i = 0;
	width = 640;
	agl_step = FOV / width;
	current_agl = cub->player->angle + (FOV / 2);
	while (i < width)
	{
		draw_line_from_player(cub, current_agl, 100, MINI_MAP_RAY);
		current_agl -= agl_step;
		i++;
	}
}

void	pixel_draw_square(t_cub *cub, int size_i, int size_j, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size_i)
	{
		x = 0;
		while (x < size_j)
		{
			if (color != 0x00000000)
				my_put_pixel_to_image2(cub, cub->minimap->j * 8 + y,
					cub->minimap->i * 8 + x, color);
			x++;
		}
		y++;
	}
}

int	draw_2d_map(t_cub *cub)
{
	int	map_width;
	int	map_height;

	cub->minimap->i = 0;
	map_width = find_width_mini_map(cub->parse->map);
	map_height = find_height_mini_map(cub->parse->map);
	clear_image_with_transparency(cub, map_width * 8.5, map_height * 8.5);
	while (cub->parse->map[cub->minimap->i])
	{
		cub->minimap->j = 0;
		while (cub->parse->map[cub->minimap->i][cub->minimap->j])
		{
			if (cub->parse->map[cub->minimap->i][cub->minimap->j] != '1')
				pixel_draw_square(cub, 8, 8, cub->game->rgb_sky);
			cub->minimap->j++;
		}
		cub->minimap->i++;
	}
	draw_fov(cub);
	return (0);
}
