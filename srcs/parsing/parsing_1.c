/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:48:19 by nicjousl          #+#    #+#             */
/*   Updated: 2025/01/02 12:45:22 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_char(char c)
{
	int	i;

	i = 0;
	while (VALID_TOKEN[i])
	{
		if (VALID_TOKEN[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	valid_char(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->parse->map[i])
	{
		j = 0;
		while (cub->parse->map[i][j])
		{
			if (check_char(cub->parse->map[i][j]) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_player(char c)
{
	int	i;

	i = 0;
	while (PLAYER_TOKEN[i])
	{
		if (PLAYER_TOKEN[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	only_one_player(t_cub *cub)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (cub->parse->map[i])
	{
		j = 0;
		while (cub->parse->map[i][j])
		{
			if (check_player(cub->parse->map[i][j]) == 1)
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (1);
	return (0);
}

void	add_extra_char(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	(void)size;
	while (src[i] && i < size)
	{
		if (src[i] == '1')
			dest[i] = '1';
		else if (src[i] == '0')
			dest[i] = '0';
		else if (src[i] == 'N' || src[i] == 'W'
			|| src[i] == 'E' || src[i] == 'S')
			dest[i] = '0';
		else
			dest[i] = 'X';
		i++;
	}
	while (i < size)
	{
		dest[i] = 'X';
		i++;
	}
}
