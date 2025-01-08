/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:41:14 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 11:41:37 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	end_game6(t_cub *cub)
{
	if (cub->game)
		free(cub->game);
	if (cub->parse)
		free(cub->parse);
	if (cub->player)
		free(cub->player);
	if (cub->ray)
		free(cub->ray);
	if (cub->vector)
		free(cub->vector);
	if (cub->minimap)
		free(cub->minimap);
	if (cub->rvb)
		free(cub->rvb);
	if (cub->image)
		free(cub->image);
	exit(0);
}
