/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:42:31 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 10:58:55 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_angle(t_player *player, char direction)
{
	if (direction == 'N')
		player->angle = M_PI;
	else if (direction == 'S')
		player->angle = 0;
	else if (direction == 'E')
		player->angle = M_PI / 2;
	else if (direction == 'W')
		player->angle = 3 * M_PI / 2;
}

static int	set_player_position(t_cub *cub, int y, int x)
{
	cub->player->pos.x = y + 0.5;
	cub->player->pos.y = x + 0.5;
	set_player_angle(cub->player, cub->parse->map[y][x]);
	cub->parse->map[y][x] = '0';
	return (0);
}

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
			if (cub->parse->map[y][x] == 'N' || cub->parse->map[y][x] == 'S'
				|| cub->parse->map[y][x] == 'E' || cub->parse->map[y][x] == 'W')
				return (set_player_position(cub, y, x));
			x++;
		}
		y++;
	}
	return (1);
}
