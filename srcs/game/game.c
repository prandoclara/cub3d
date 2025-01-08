/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:56:26 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 10:42:47 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_dir_cam_vector(t_cub *cub)
{
	float	radian;

	radian = cub->player->angle;
	cub->player->dir.x = cos(radian);
	cub->player->dir.y = sin(radian);
	cub->player->plane.x = FOV * sin(radian);
	cub->player->plane.y = FOV * -cos(radian);
	return (0);
}

int	init_game(t_cub *cub)
{
	init_player_position(cub);
	init_dir_cam_vector(cub);
	raycasting(cub);
	draw_2d_map(cub);
	mlx_put_image_to_window(cub->game->mlx_ptr, cub->game->mlx_win_ptr,
		cub->image->img_ptr, 0, 0);
	mlx_put_image_to_window(cub->game->mlx_ptr, cub->game->mlx_win_ptr,
		cub->minimap->map_img, 0, 0);
	return (0);
}

int	launch_mlx(t_cub *cub)
{
	if (load_textures(cub) == -1)
		return (error_handler(18), 1);
	init_game(cub);
	mlx_hook(cub->game->mlx_win_ptr, 2, 1L << 0, key_hook, cub);
	mlx_hook(cub->game->mlx_win_ptr, 17, 1L << 17, end_game, cub);
	mlx_loop_hook(cub->game->mlx_ptr, init_game, cub);
	mlx_loop(cub->game->mlx_ptr);
	return (0);
}

int	launch_game(t_cub *cub)
{
	int	error;

	error = launch_mlx(cub);
	if (error != 0)
	{
		if (error == 1)
			error_handler(14);
		return (1);
	}
	return (0);
}
