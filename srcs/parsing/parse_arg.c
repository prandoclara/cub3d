/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:07:26 by nicjousl          #+#    #+#             */
/*   Updated: 2025/01/02 12:27:18 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_ext(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i--;
	if (map[i] != 'b' || map[i - 1] != 'u'
		|| map[i - 2] != 'c' || map[i - 3] != '.')
		return (1);
	return (0);
}

int	is_directory(char *s)
{
	int	fd;

	fd = open(s, O_DIRECTORY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

void	parse_arg(char *map, t_cub *cub)
{
	(void)cub;
	if (check_ext(map) == 1)
	{
		error_handler(2);
		exit(1);
	}
	else if (is_directory(map) == 1)
	{
		error_handler(4);
		exit(1);
	}
}
