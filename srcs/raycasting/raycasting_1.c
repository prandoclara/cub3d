/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:43:37 by claprand          #+#    #+#             */
/*   Updated: 2025/01/07 15:54:15 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_cub *cub, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	cub->ray->raydir.x = cub->player->dir.x + cub->player->plane.x * camera_x;
	cub->ray->raydir.y = cub->player->dir.y + cub->player->plane.y * camera_x;
	if (cub->ray->raydir.x == 0)
		cub->ray->deltadist.x = 1e30;
	else
		cub->ray->deltadist.x = fabs(1 / cub->ray->raydir.x);
	if (cub->ray->raydir.y == 0)
		cub->ray->deltadist.y = 1e30;
	else
		cub->ray->deltadist.y = fabs(1 / cub->ray->raydir.y);
}

void	calculate_step_and_sidedist(t_cub *cub)
{
	if (cub->ray->raydir.x < 0)
	{
		cub->ray->step_x = -1;
		cub->ray->sidedist.x = (cub->player->pos.x - cub->ray->map_x)
			* cub->ray->deltadist.x;
	}
	else
	{
		cub->ray->step_x = 1;
		cub->ray->sidedist.x = (cub->ray->map_x + 1.0 - cub->player->pos.x)
			* cub->ray->deltadist.x;
	}
	if (cub->ray->raydir.y < 0)
	{
		cub->ray->step_y = -1;
		cub->ray->sidedist.y = (cub->player->pos.y - cub->ray->map_y)
			* cub->ray->deltadist.y;
	}
	else
	{
		cub->ray->step_y = 1;
		cub->ray->sidedist.y = (cub->ray->map_y + 1.0 - cub->player->pos.y)
			* cub->ray->deltadist.y;
	}
}

void calculate_wallx(t_cub *cub)
{
    if (cub->ray->side == 0)
        cub->ray->wallx = cub->player->pos.y + cub->ray->perpwalldist * cub->ray->raydir.y;
    else
        cub->ray->wallx = cub->player->pos.x + cub->ray->perpwalldist * cub->ray->raydir.x;
    cub->ray->wallx -= floor(cub->ray->wallx); 
}

void perform_dda(t_cub *cub, char **map)
{
    cub->ray->hit = 0;
    
    // Boucle de DDA, continue jusqu'à ce qu'un mur soit frappé
    while (cub->ray->hit == 0)
    {
        // Vérifie si le rayon touche un mur horizontal ou vertical
        if (cub->ray->sidedist.x < cub->ray->sidedist.y)
        {
            cub->ray->sidedist.x += cub->ray->deltadist.x;
            cub->ray->map_x += cub->ray->step_x;
            cub->ray->side = 0; // Mur vertical (côté X)
        }
        else
        {
            cub->ray->sidedist.y += cub->ray->deltadist.y;
            cub->ray->map_y += cub->ray->step_y;
            cub->ray->side = 1; // Mur horizontal (côté Y)
        }
        
        // Si le rayon est sorti du monde du jeu, on sort de la boucle
        if (cub->ray->map_x < 0 || cub->ray->map_y < 0
            || !map[cub->ray->map_x] || !map[cub->ray->map_x][cub->ray->map_y])
            break;

        // Si le rayon frappe un mur ('1' sur la carte), on sort de la boucle
        if (map[cub->ray->map_x][cub->ray->map_y] == '1')
            cub->ray->hit = 1;
    }

    // Si le rayon a frappé un mur, on calcule la position exacte de l'impact (wallx)
    if (cub->ray->hit == 1)
    {
        calculate_wallx(cub); // Fonction à ajouter pour calculer wallx
    }
}


void	calculate_wall_distance(t_cub *cub)
{
	if (cub->ray->side == 0)
		cub->ray->perpwalldist
			= (cub->ray->sidedist.x - cub->ray->deltadist.x);
	else
		cub->ray->perpwalldist
			= (cub->ray->sidedist.y - cub->ray->deltadist.y);
}

void	calculate_wall_drawing_params(t_cub *cub)
{
	// double	wall_dist;

	// wall_dist = fmax(cub->ray->perpwalldist, 0.1);
	cub->ray->wall_dist = fmax(cub->ray->perpwalldist, 0.1);
	cub->ray->lineheight = (int)(HEIGHT / cub->ray->wall_dist);
	cub->ray->drawstart = -cub->ray->lineheight / 2 + HEIGHT / 2;
	cub->ray->drawend = cub->ray->lineheight / 2 + HEIGHT / 2;
	cub->ray->drawstart = fmax(0, cub->ray->drawstart);
	cub->ray->drawend = fmin(HEIGHT - 1, cub->ray->drawend);
}
