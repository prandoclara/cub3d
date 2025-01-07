/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:58:06 by claprand          #+#    #+#             */
/*   Updated: 2025/01/06 14:52:39 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line_from_player(t_cub *cub, double agl, double maxlen, int color)
{
	double	start_x;
	double	start_y;
	double	current_x;
	double	current_y;
	double	step;
	double	traveled_length;
	int		map_x;
	int		map_y;

	start_x = cub->player->pos.x * 8;
	start_y = cub->player->pos.y * 8;
	current_x = start_x;
	current_y = start_y;
	step = 1.0;
	traveled_length = 0.0;
	while (traveled_length < maxlen)
	{
		my_put_pixel_to_image(cub, (int)current_y, (int)current_x, color);
		map_x = (int)(current_x / (8));
		map_y = (int)(current_y / (8));
		if (cub->parse->map[map_x][map_y] == '1')
			break ;
		current_x += cos(agl) * step;
		current_y += sin(agl) * step;
		traveled_length += step;
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

void	pixel_draw_square(t_cub *cub, int i, int j, int size_i, int size_j, int color)
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
				my_put_pixel_to_image(cub, j * 8 + y, i * 8 + x, color);
			x++;
		}
		y++;
	}
}

int	draw_2d_player(t_cub *cub)
{
	pixel_draw_square(cub, cub->player->pos.x, cub->player->pos.y, 4, 4, MM_P);
	draw_fov(cub);
	return (0);
}

int	draw_2d_map(t_cub *cub)
{
	int	i;
	int	j;
	int	map_width;
	int	map_height;

	i = -1;
	map_width = find_width_mini_map(cub->parse->map);
	map_height = find_height_mini_map(cub->parse->map);
	cub->minimap->map_img = mlx_new_image(cub->game->mlx_ptr,
			map_width * 8.5, map_height * 8.5);
	cub->minimap->map_addr = mlx_get_data_addr(cub->minimap->map_img,
			&cub->minimap->bits_per_pixel,
			&cub->minimap->line_length,
			&cub->minimap->endian);
	clear_image_with_transparency(cub, map_width * 8.5, map_height * 8.5);
	while (cub->parse->map[++i])
	{
		j = 0;
		while (cub->parse->map[i][j])
		{
			if (cub->parse->map[i][j] != '1')
				pixel_draw_square(cub, i, j, 8, 8, cub->game->rgb_sky);
			j++;
		}
	}
	draw_2d_player(cub);
	return (0);
}
