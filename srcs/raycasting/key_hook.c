/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:56:53 by claprand          #+#    #+#             */
/*   Updated: 2025/01/09 11:57:37 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_width_map(char **map)
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

int	find_height_map(char **map)
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

int is_walkable(t_cub *cub, float x, float y)
{
    int map_x;
    int map_y;
    int width;
    int height;
    float margin = 0.1;

    map_x = (int)(x + margin);
    map_y = (int)(y + margin);
    width = find_width_map(cub->parse->map);
    height = find_height_map(cub->parse->map);

    if (map_x >= 0 && map_x < width && map_y >= 0 && map_y < height)
    {
        if (cub->parse->map[map_y][map_x] == '1')
            return (0);
        return (1);
    }
    return (0);
}


void	rotate_player(t_cub *cub, int keysym, float rot_speed)
{
	if (keysym == XK_Right)
		cub->player->angle -= rot_speed;
	if (keysym == XK_Left)
		cub->player->angle += rot_speed;
	if (cub->player->angle < 0)
		cub->player->angle += 2 * M_PI;
	if (cub->player->angle > 2 * M_PI)
		cub->player->angle -= 2 * M_PI;
	cub->player->dir.x = cos(cub->player->angle);
	cub->player->dir.y = sin(cub->player->angle);
	cub->player->plane.x = FOV * sin(cub->player->angle);
	cub->player->plane.y = FOV * -cos(cub->player->angle);
}

void	up_back_player(t_cub *cub, int keysym, float move_speed)
{
	float	new_x;
	float	new_y;

	new_x = cub->player->pos.x;
	new_y = cub->player->pos.y;
	if (keysym == XK_w || keysym == XK_W)
	{
		new_x += cub->player->dir.x * move_speed;
		new_y += cub->player->dir.y * move_speed;
	}
	if (keysym == XK_s || keysym == XK_S)
	{
		new_x -= cub->player->dir.x * move_speed;
		new_y -= cub->player->dir.y * move_speed;
	}
	if (is_walkable(cub, new_x, cub->player->pos.y))
		cub->player->pos.x = new_x;
	if (is_walkable(cub, cub->player->pos.x, new_y))
		cub->player->pos.y = new_y;
}

void	left_right_player(t_cub *cub, int keysym, float move_speed)
{
	float	new_x;
	float	new_y;

	new_x = cub->player->pos.x;
	new_y = cub->player->pos.y;
	if (keysym == XK_a || keysym == XK_A)
	{
		new_x -= cub->player->plane.x * move_speed;
		new_y -= cub->player->plane.y * move_speed;
	}
	if (keysym == XK_d || keysym == XK_D)
	{
		new_x += cub->player->plane.x * move_speed;
		new_y += cub->player->plane.y * move_speed;
	}
	if (is_walkable(cub, new_x, cub->player->pos.y))
		cub->player->pos.x = new_x;
	if (is_walkable(cub, cub->player->pos.x, new_y))
		cub->player->pos.y = new_y;
}

int	key_hook(int keysym, t_cub *cub)
{
	float	move_speed;
	float	rot_speed;

	move_speed = 0.1;
	rot_speed = 0.05;
	if (keysym == XK_Escape || keysym == XK_q)
		end_game(cub);
	rotate_player(cub, keysym, rot_speed);
	up_back_player(cub, keysym, move_speed);
	left_right_player(cub, keysym, move_speed);
	return (0);
}
