/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:49:53 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 10:57:37 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*join_rgb_values(int r, int g, int b)
{
	char	*hexa;
	char	*temp;
	char	*test;
	int		rgb[3];
	int		i;

	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
	hexa = ft_strdup("");
	if (!hexa)
		return (NULL);
	i = -1;
	while (++i < 3)
	{
		test = ft_itoa(rgb[i]);
		if (!test)
			return (free(hexa), NULL);
		temp = hexa;
		hexa = ft_strjoin(hexa, test);
		free(temp);
		free(test);
	}
	return (hexa);
}

void	join_rgb_sky(t_cub *cub)
{
	char	*hexa;

	hexa = join_rgb_values(cub->parse->r_sky,
			cub->parse->g_sky, cub->parse->b_sky);
	if (!hexa)
		return ;
	cub->game->rgb_sky = ft_atoi(hexa);
	free(hexa);
}

void	join_rgb_floor(t_cub *cub)
{
	char	*hexa;

	hexa = join_rgb_values(cub->parse->r_floor,
			cub->parse->g_floor, cub->parse->b_floor);
	if (!hexa)
		return ;
	cub->game->rgb_floor = ft_atoi(hexa);
	free(hexa);
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
