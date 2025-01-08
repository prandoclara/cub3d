/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_textures_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:58:39 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 11:58:42 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_floor_color(t_cub *cub, int i, int j)
{
	return (cub->parse->files[i][j] == 'F' &&
			cub->parse->files[i][j + 1] == ' ');
}

static int	is_sky_color(t_cub *cub, int i, int j)
{
	return (cub->parse->files[i][j] == 'C' &&
			cub->parse->files[i][j + 1] == ' ');
}

static void	check_texture(t_cub *cub, int i, int j)
{
	if (is_north_texture(cub, i, j))
		cub->parse->texture_north = ft_strdup(cub->parse->files[i]);
	if (is_south_texture(cub, i, j))
		cub->parse->texture_south = ft_strdup(cub->parse->files[i]);
	if (is_west_texture(cub, i, j))
		cub->parse->texture_west = ft_strdup(cub->parse->files[i]);
	if (is_east_texture(cub, i, j))
		cub->parse->texture_east = ft_strdup(cub->parse->files[i]);
	if (is_floor_color(cub, i, j))
		cub->parse->rgb_floor = ft_strdup(cub->parse->files[i]);
	if (is_sky_color(cub, i, j))
		cub->parse->rgb_sky = ft_strdup(cub->parse->files[i]);
}

static void	process_line(t_cub *cub, int i)
{
	int	j;

	j = 0;
	while (cub->parse->files[i][j + 2])
	{
		check_texture(cub, i, j);
		j++;
	}
}

void	get_texture(t_cub *cub)
{
	int	i;

	i = -1;
	cub->parse->start_m = is_the_map(cub);
	while (++i < cub->parse->nb_line && i < cub->parse->start_m)
	{
		process_line(cub, i);
	}
}
