/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:54:21 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 11:37:19 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_sky(t_cub *cub, int i, int j)
{
	my_put_pixel_to_image2(cub, i, j, cub->game->rgb_sky);
}

void	draw_floor(t_cub *cub, int i, int j)
{
	my_put_pixel_to_image2(cub, i, j, cub->game->rgb_floor);
}

void	draw_wall_pixel(t_cub *cub, int i, int j, double tex_pos)
{
	int				tex_y;
	int				tex_x;
	int				texture_num;
	unsigned int	wall_color;
	int				index;

	tex_y = calculate_tex_y(cub, tex_pos);
	tex_x = calculate_tex_x(cub);
	texture_num = get_texture_num(cub);
	index = tex_y * cub->image->tex_w + tex_x;
	if (index >= 0 && index < cub->image->tex_w * cub->image->tex_h)
	{
		wall_color = cub->image->textures[texture_num]->pixels[index];
		if (cub->ray->side == 1)
			wall_color = (wall_color >> 1) & 0x7F7F7F;
		my_put_pixel_to_image2(cub, i, j, wall_color);
	}
}

void	draw_wall2(t_cub *cub, int i, double tex_pos)
{
	int	j;

	j = 0;
	tex_pos = calculate_tex_pos(cub, tex_pos);
	while (j < HEIGHT)
	{
		if (j >= cub->ray->drawstart && j <= cub->ray->drawend)
		{
			draw_wall_pixel(cub, i, j, tex_pos);
			tex_pos += calculate_step(cub);
		}
		else if (j < cub->ray->drawstart)
			draw_sky(cub, i, j);
		else
			draw_floor(cub, i, j);
		j++;
	}
}
