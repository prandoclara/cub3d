/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:12:50 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 12:03:25 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_minimap(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 4)
	{
		x = 0;
		while (x < WIDTH / 4)
		{
			my_put_pixel_to_image(cub, x, y, 0xFF000000000);
			x++;
		}
		y++;
	}
}

void	clear_image_with_transparency(t_cub *cub, int width, int height)
{
	int	x;
	int	y;
	int	pixel_index;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			pixel_index = (y * cub->minimap->line_length)
				+ (x * (cub->minimap->bits_per_pixel / 8));
			*(unsigned int *)(cub->minimap->map_addr + pixel_index)
				= MINI_MAP_WALL;
			x++;
		}
		y++;
	}
}

int	find_width_mini_map(char **map)
{
	int	i;
	int	j;
	int	ret;

	ret = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (j > ret)
				ret = j;
			j++;
		}
		i++;
	}
	return (ret);
}

int	find_height_mini_map(char **map)
{
	int	i;
	int	j;
	int	ret;

	ret = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (i > ret)
			ret = i;
		i++;
	}
	return (ret);
}
