/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_map_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:17:19 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 12:01:55 by claprand         ###   ########.fr       */
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
	int		i;
	int		j;
	int		h;
	char	*str;

	i = -1;
	j = 0;
	h = 0;
	str = ft_calloc(sizeof(char), cub->parse->long_line);
	skip_texture_name(texture, &i, &j, texture_name);
	skip_spaces(texture, &i);
	return (copy_path(texture, i, str));
}

void	get_nice_texture_path(t_cub *cub)
{
	if (cub->parse->texture_north != NULL)
		cub->parse->north_path = trim_path(cub->parse->texture_north,
				"NO", cub);
	if (cub->parse->texture_south != NULL)
		cub->parse->south_path = trim_path(cub->parse->texture_south,
				"SO", cub);
	if (cub->parse->texture_east != NULL)
		cub->parse->east_path = trim_path(cub->parse->texture_east,
				"EA", cub);
	if (cub->parse->texture_west != NULL)
		cub->parse->west_path = trim_path(cub->parse->texture_west,
				"WE", cub);
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
