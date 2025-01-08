/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:13:10 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 11:38:09 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_texture_path(t_cub *cub, int i)
{
	if (i == 0)
		return (cub->parse->north_path);
	else if (i == 1)
		return (cub->parse->south_path);
	else if (i == 2)
		return (cub->parse->east_path);
	else
		return (cub->parse->west_path);
}

static int	load_single_texture(t_cub *cub, int i)
{
	char	*path;

	path = get_texture_path(cub, i);
	if (!path)
		return (error_handler(20), 1);
	cub->image->textures[i]->xpm = mlx_xpm_file_to_image(cub->game->mlx_ptr,
			path, &cub->image->tex_w, &cub->image->tex_h);
	if (!cub->image->textures[i]->xpm)
		return (error_handler(18), 1);
	cub->image->textures[i]->addr
		= mlx_get_data_addr(cub->image->textures[i]->xpm,
			&cub->image->textures[i]->bits_per_pixel,
			&cub->image->textures[i]->line_length,
			&cub->image->textures[i]->endian);
	if (!cub->image->textures[i]->addr)
		return (error_handler(19), 1);
	cub->image->textures[i]->pixels
		= (unsigned int *)cub->image->textures[i]->addr;
	return (0);
}

int	load_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (load_single_texture(cub, i))
			return (1);
		i++;
	}
	return (0);
}

int	get_texture_num(t_cub *cub)
{
	if (cub->ray->side == 1)
	{
		if (cub->ray->raydir.y > 0)
			return (2);
		else
			return (3);
	}
	else
	{
		if (cub->ray->raydir.x > 0)
			return (1);
		else
			return (0);
	}
}
