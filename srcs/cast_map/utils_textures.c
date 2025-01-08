/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:58:45 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 12:02:47 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_north_texture(t_cub *cub, int i, int j)
{
	return (cub->parse->files[i][j] == 'N' &&
			cub->parse->files[i][j + 1] == 'O' &&
			cub->parse->files[i][j + 2] == ' ');
}

int	is_south_texture(t_cub *cub, int i, int j)
{
	return (cub->parse->files[i][j] == 'S' &&
			cub->parse->files[i][j + 1] == 'O' &&
			cub->parse->files[i][j + 2] == ' ');
}

int	is_west_texture(t_cub *cub, int i, int j)
{
	return (cub->parse->files[i][j] == 'W' &&
			cub->parse->files[i][j + 1] == 'E' &&
			cub->parse->files[i][j + 2] == ' ');
}

int	is_east_texture(t_cub *cub, int i, int j)
{
	return (cub->parse->files[i][j] == 'E' &&
			cub->parse->files[i][j + 1] == 'A' &&
			cub->parse->files[i][j + 2] == ' ');
}

int	read_map_lines(int fd, t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->parse->nb_line)
	{
		if (read_map_line(fd, cub, i))
			return (1);
		i++;
	}
	return (0);
}
