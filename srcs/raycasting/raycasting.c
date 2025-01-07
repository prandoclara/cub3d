/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:06:57 by claprand          #+#    #+#             */
/*   Updated: 2025/01/07 13:48:30 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int raycasting(t_cub *cub)
{
    int x = 0;

    while (x < WIDTH)
    {
        cub->ray->hit = 0;
        cub->ray->map_x = (int)cub->player->pos.x;
        cub->ray->map_y = (int)cub->player->pos.y;
        init_ray(cub, x);
        calculate_step_and_sidedist(cub);
        perform_dda(cub, cub->parse->map);
        calculate_wall_distance(cub);
        calculate_wall_drawing_params(cub);
        draw_wall2(cub, x, cub->image->tex_pos);
        x++;
    }
    return (0);
}
