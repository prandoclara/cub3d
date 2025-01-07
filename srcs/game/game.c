/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:56:26 by claprand          #+#    #+#             */
/*   Updated: 2025/01/06 15:04:02 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_player_position(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	while (cub->parse->map[y])
	{
		x = 0;
		while (cub->parse->map[y][x])
		{
			if (cub->parse->map[y][x] == 'N'
				|| cub->parse->map[y][x] == 'S'
				|| cub->parse->map[y][x] == 'E'
				|| cub->parse->map[y][x] == 'W')
			{
				cub->player->pos.x = y + 0.5;
				cub->player->pos.y = x + 0.5;
				if (cub->parse->map[y][x] == 'N')
					cub->player->angle = M_PI;
				else if (cub->parse->map[y][x] == 'S')
					cub->player->angle = 0;
				else if (cub->parse->map[y][x] == 'E')
					cub->player->angle = M_PI / 2;
				else if (cub->parse->map[y][x] == 'W')
					cub->player->angle = 3 * M_PI / 2;
				if (cub->player->angle < 0)
					cub->player->angle += 2 * M_PI;
				if (cub->player->angle >= 2 * M_PI)
					cub->player->angle -= 2 * M_PI;
				cub->parse->map[y][x] = '0';
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

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
	{
		printf("Erreur: Impossible de charger les textures\n");
		return (1); // Retourne une erreur pour signaler l'échec
	}
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
