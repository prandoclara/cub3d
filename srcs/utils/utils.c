/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:08:03 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 12:15:04 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_put_pixel_to_image2(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = cub->image->addr + (y * cub->image->line_length
				+ x * (cub->image->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	my_put_pixel_to_image(t_cub *cub, int x, int y, long color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = cub->minimap->map_addr + (y * cub->minimap->line_length
				+ x * (cub->minimap->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
