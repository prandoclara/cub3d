/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_map_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:17:19 by claprand          #+#    #+#             */
/*   Updated: 2025/01/02 13:17:21 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	files_to_map(t_cub *cub)
{
	int	i;

	i = 0;
	cub->parse->map = calloc(sizeof(char *),
			(cub->parse->nb_line - cub->parse->start_m) + 1);
	while (cub->parse->start_m < cub->parse->nb_line)
	{
		cub->parse->map[i] = ft_strdup(cub->parse->files[cub->parse->start_m]);
		cub->parse->start_m++;
		i++;
	}
}

char	*trim_path(char *texture, char *texture_name, t_cub *cub)
{
	char	*str;
	int		i;
	int		j;
	int		h;

	i = 0;
	j = 0;
	h = 0;
	str = ft_calloc(sizeof(char), cub->parse->long_line);
	while (texture[i])
	{
		while (texture[i] == texture_name[j])
		{
			i++;
			j++;
		}
		if (texture_name[j] == '\0')
			break ;
		i++;
	}
	while (texture[i] == ' ')
		i++;
	while (texture[i] && texture[i] != ' ')
	{
		str[h] = texture[i];
		i++;
		h++;
	}
	return (str);
}

void	get_nice_texture_path(t_cub *cub)
{
	cub->parse->north_path = trim_path(cub->parse->texture_north, "NO", cub);
	cub->parse->south_path = trim_path(cub->parse->texture_south, "SO", cub);
	cub->parse->east_path = trim_path(cub->parse->texture_east, "EA", cub);
	cub->parse->west_path = trim_path(cub->parse->texture_west, "WE", cub);
}

int	cast_map(char *map, t_cub *cub)
{
	get_size_of_the_file(map, cub);
	cub->parse->files = ft_calloc(sizeof(char *), cub->parse->nb_line + 1);
	find_the_longest_line(map, cub);
	if (cast_char_to_string(map, cub) == 1)
		return (1);
	get_texture(cub);
	get_nice_texture_path(cub);
	files_to_map(cub);
	return (0);
}
