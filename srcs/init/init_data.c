/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:42:57 by claprand          #+#    #+#             */
/*   Updated: 2025/01/02 10:42:57 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_mlx(t_cub *cub)
{
	int	pixel_bits;
	int	line_len;
	int	endian;

	cub->game->mlx_ptr = mlx_init();
	if (!cub->game->mlx_ptr)
		return (error_handler(11), 1);
	cub->game->mlx_win_ptr = mlx_new_window(cub->game->mlx_ptr,
			192 * 8, 108 * 8, "cub3D");
	if (!cub->game->mlx_win_ptr)
		return (error_handler(12), 1);
	cub->image->img_ptr = mlx_new_image(cub->game->mlx_ptr, WIDTH, HEIGHT);
	if (!cub->image->img_ptr)
		return (error_handler(16), 1);
	cub->image->addr = mlx_get_data_addr(cub->image->img_ptr,
			&pixel_bits, &line_len, &endian);
	cub->image->bits_per_pixel = pixel_bits;
	cub->image->line_length = line_len;
	return (0);
}

void	init_data(t_cub *cub)
{
	if (init_parse(cub) == 1)
		end_game(cub);
	if (init_game_s(cub) == 1)
		end_game(cub);
	if (init_player(cub) == 1)
		end_game(cub);
	if (init_minimap(cub) == 1)
		end_game(cub);
	if (init_ray_s(cub) == 1)
		end_game(cub);
	if (init_vector(cub) == 1)
		end_game(cub);
	if (init_image(cub) == 1)
		end_game(cub);
	if (init_mlx(cub) == 1)
		end_game(cub);
	if (init_textures(cub) == 1)
		end_game(cub);
}
