/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:43:51 by claprand          #+#    #+#             */
/*   Updated: 2025/01/07 16:53:01 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_map_with_extra_char(t_cub *cub)
{
	int	i;

	i = 0;
	cub->parse->copy_map = ft_calloc(sizeof(char *),
			(cub->parse->nb_line - cub->parse->start_m) + 100);
	while (cub->parse->map[i])
	{
		cub->parse->copy_map[i] = ft_calloc(sizeof(char),
				cub->parse->long_line + 1);
		add_extra_char(cub->parse->copy_map[i],
			cub->parse->map[i], cub->parse->long_line);
		i++;
	}
	cub->parse->copy_map[i] = NULL;
}

int	zero_contact_to_x(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub->parse->copy_map[++i])
	{
		j = -1;
		while (cub->parse->copy_map[i][++j])
		{
			if (cub->parse->copy_map[i][j] == '0')
			{
				if (j == 0)
					return (1);
				if (cub->parse->copy_map[i + 1][j]
					&& cub->parse->copy_map[i + 1][j] == 'X')
					return (1);
				if (cub->parse->copy_map[i - 1][j]
					&& cub->parse->copy_map[i - 1][j] == 'X')
					return (1);
				if (cub->parse->copy_map[i][j + 1]
					&& cub->parse->copy_map[i][j + 1] == 'X')
					return (1);
				if (cub->parse->copy_map[i][j - 1]
					&& cub->parse->copy_map[i][j - 1] == 'X')
					return (1);
			}
		}
	}
	return (0);
}

int	map_is_close(t_cub *cub)
{
	copy_map_with_extra_char(cub);
	if (zero_contact_to_x(cub) == 1)
		return (1);
	return (0);
}

int	have_texture(t_cub *cub)
{
	if (cub->parse->texture_east == NULL)
		return (1);
	if (cub->parse->texture_west == NULL)
		return (1);
	if (cub->parse->texture_north == NULL)
		return (1);
	if (cub->parse->texture_south == NULL)
		return (1);
	if (cub->parse->rgb_sky == NULL)
		return (1);
	if (cub->parse->rgb_floor == NULL)
		return (1);
	return (0);
}

void	split_rgb_floor(t_cub *cub)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	str = ft_strtrim(cub->parse->rgb_floor, "F ");
	while (str[i] != ',')
		i++;
	cub->parse->str_r = ft_master_strndup(str, 0, i);
	i++;
	j = i;
	while (str[i] != ',')
		i++;
	cub->parse->str_g = ft_master_strndup(str, j, i);
	i++;
	j = i;
	while (str[i] != ',' && str[i])
		i++;
	cub->parse->str_b = ft_master_strndup(str, j, i);
	cub->parse->r_floor = ft_atoi(cub->parse->str_r);
	cub->parse->g_floor = ft_atoi(cub->parse->str_g);
	cub->parse->b_floor = ft_atoi(cub->parse->str_b);
	free(str);
}
