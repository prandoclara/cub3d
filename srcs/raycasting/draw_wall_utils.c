/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:31:34 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 11:38:03 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calculate_step(t_cub *cub)
{
	return ((double)cub->image->tex_h
		/ (cub->ray->drawend - cub->ray->drawstart));
}

double	calculate_tex_pos(t_cub *cub, double tex_pos)
{
	double	step;

	step = calculate_step(cub);
	tex_pos = (cub->ray->drawstart - HEIGHT / 2
			+ (cub->ray->drawend - cub->ray->drawstart) / 2) * step;
	return (tex_pos);
}

int	calculate_tex_y(t_cub *cub, double tex_pos)
{
	int	tex_y;

	tex_y = (int)tex_pos % cub->image->tex_h;
	if (tex_y < 0)
		tex_y += cub->image->tex_h;
	return (tex_y);
}

int	calculate_tex_x(t_cub *cub)
{
	int	tex_x;

	tex_x = (int)(cub->ray->wallx * cub->image->tex_w);
	if (tex_x < 0)
		tex_x = 0;
	else if (tex_x >= cub->image->tex_w)
		tex_x = cub->image->tex_w - 1;
	return (tex_x);
}

void	calculate_wallx(t_cub *cub)
{
	if (cub->ray->side == 0)
		cub->ray->wallx = cub->player->pos.y + cub->ray->perpwalldist
			* cub->ray->raydir.y;
	else
		cub->ray->wallx = cub->player->pos.x + cub->ray->perpwalldist
			* cub->ray->raydir.x;
	cub->ray->wallx -= floor(cub->ray->wallx);
}
