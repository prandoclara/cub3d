/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:56:53 by claprand          #+#    #+#             */
/*   Updated: 2025/01/07 16:17:32 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	move_player(t_cub *cub, int keysym, float move_speed)
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
	// if (cub->parse->map[(int)new_y][(int)new_x] == '0')
	// {
		cub->player->pos.x = new_x;
		cub->player->pos.y = new_y;
	// }
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
	// if (cub->parse->map[(int)new_y][(int)new_x] == '0')
	// {
		cub->player->pos.x = new_x;
		cub->player->pos.y = new_y;
	//}
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
	move_player(cub, keysym, move_speed);
	left_right_player(cub, keysym, move_speed);
	return (0);
}


// int key_hook(int keysym, t_cub *cub)
// {
// 	// int new_x;
//     // int new_y;
// 	//printf("keyhooo\n");
//     if (keysym == XK_Escape || keysym == XK_q)
//         end_game(cub);
//     if (keysym == XK_Left)
//     {
//         cub->player->angle += 0.05;
//         if (cub->player->angle < 0)
//         {
//             cub->player->angle += 2 * M_PI;
//         }
//     }
//     if (keysym == XK_Right)
//     {
//       cub->player->angle -= 0.05;
//         if (cub->player->angle < 0)
//         {
//             cub->player->angle += 2 * M_PI;
//         }
//     }
//     if (keysym == XK_d) 
//         cub->player->pos.y += 0.1;
//     if (keysym == XK_a)
//         cub->player->pos.y -= 0.1;
//     if (keysym == XK_Up || keysym == XK_w)
//     {
// 		cub->player->pos.x -= 0.1;
//     }
//     if (keysym == XK_Down || keysym == XK_s)
//     {	
// 		cub->player->pos.x += 0.1;
//     }
//     return (0);
// }