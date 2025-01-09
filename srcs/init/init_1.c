/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:17:13 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 16:42:54 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_vector(t_cub *cub)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector) * 1);
	if (!vector)
		return (error_handler(17), 1);
	cub->vector = vector;
	return (0);
}

int	init_player(t_cub *cub)
{
	t_player	*player;

	player = malloc(sizeof(t_player) * 1);
	if (!player)
		return (error_handler(17), 1);
	cub->player = player;
	cub->player->angle = 0;
	cub->player->pos.x = 0;
	cub->player->pos.y = 0;
	cub->player->dir.x = -1.0;
	cub->player->dir.y = 0;
	cub->player->plane.x = 0;
	cub->player->plane.y = 0.66;
	return (0);
}

int	init_ray_s(t_cub *cub)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray) * 1);
	if (!ray)
		return (error_handler(17), 1);
	cub->ray = ray;
	cub->ray->raydir.x = 0;
	cub->ray->raydir.y = 0;
	cub->ray->sidedist.x = 0;
	cub->ray->sidedist.y = 0;
	cub->ray->deltadist.x = 0;
	cub->ray->deltadist.y = 0;
	cub->ray->perpwalldist = 0;
	cub->ray->step_x = 0;
	cub->ray->step_y = 0;
	cub->ray->map_x = 0;
	cub->ray->map_y = 0;
	cub->ray->hit = 0;
	cub->ray->side = 0;
	cub->ray->drawstart = 0;
	cub->ray->drawend = 0;
	cub->ray->wallx = 0;
	cub->ray->wall_dist = 0;
	return (0);
}
