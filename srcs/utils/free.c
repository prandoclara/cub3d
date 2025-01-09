/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:39:10 by nicjousl          #+#    #+#             */
/*   Updated: 2025/01/09 10:34:05 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	end_game5(t_cub *cub)
{
	if (cub->game->mlx_win_ptr != NULL)
		mlx_destroy_window(cub->game->mlx_ptr, cub->game->mlx_win_ptr);
	if (cub->game->north_texture != NULL)
		mlx_destroy_image(cub->game->mlx_ptr, cub->game->north_texture);
	if (cub->game->south_texture != NULL)
		mlx_destroy_image(cub->game->mlx_ptr, cub->game->south_texture);
	if (cub->game->east_texture != NULL)
		mlx_destroy_image(cub->game->mlx_ptr, cub->game->east_texture);
	if (cub->game->west_texture != NULL)
		mlx_destroy_image(cub->game->mlx_ptr, cub->game->west_texture);
	if (cub->minimap->map_img != NULL)
		mlx_destroy_image(cub->game->mlx_ptr, cub->minimap->map_img);
	if (cub->image->img_ptr != NULL)
		mlx_destroy_image(cub->game->mlx_ptr, cub->image->img_ptr);
	if (cub->game->mlx_ptr != NULL)
	{
		mlx_destroy_display(cub->game->mlx_ptr);
		free(cub->game->mlx_ptr);
	}
	end_game6(cub);
}

void	end_game4(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub->image->textures[i] != NULL)
		{
			if (cub->image->textures[i]->xpm != NULL)
				mlx_destroy_image(cub->game->mlx_ptr,
					cub->image->textures[i]->xpm);
			free(cub->image->textures[i]);
		}
		i++;
	}
	end_game5(cub);
}

void	end_game3(t_cub *cub)
{
	int	i;

	i = -1;
	if (cub->parse->copy_map != NULL)
	{
		while (cub->parse->copy_map[++i])
			free(cub->parse->copy_map[i]);
		free(cub->parse->copy_map);
	}
	if (cub->parse->north_path != NULL)
		free(cub->parse->north_path);
	if (cub->parse->south_path != NULL)
		free(cub->parse->south_path);
	if (cub->parse->west_path != NULL)
		free(cub->parse->west_path);
	if (cub->parse->east_path != NULL)
		free(cub->parse->east_path);
	if (cub->image->pixels != NULL)
		free(cub->image->pixels);
	end_game4(cub);
}

void	end_game2(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->parse->files != NULL)
	{
		while (cub->parse->files[i])
		{
			free(cub->parse->files[i]);
			i++;
		}
		free(cub->parse->files);
	}
	i = -1;
	if (cub->parse->map != NULL)
	{
		while (cub->parse->map[++i])
			free(cub->parse->map[i]);
		free(cub->parse->map);
	}
	end_game3(cub);
}

int	end_game(t_cub *cub)
{
	if (cub->parse->texture_north != NULL)
		free(cub->parse->texture_north);
	if (cub->parse->texture_south != NULL)
		free(cub->parse->texture_south);
	if (cub->parse->texture_west != NULL)
		free(cub->parse->texture_west);
	if (cub->parse->texture_east != NULL)
		free(cub->parse->texture_east);
	if (cub->parse->rgb_sky != NULL)
		free(cub->parse->rgb_sky);
	if (cub->parse->rgb_floor != NULL)
		free(cub->parse->rgb_floor);
	if (cub->parse->str_r != NULL)
		free(cub->parse->str_r);
	if (cub->parse->str_g != NULL)
		free(cub->parse->str_g);
	if (cub->parse->str_b != NULL)
		free(cub->parse->str_b);
	end_game2(cub);
	return (0);
}
