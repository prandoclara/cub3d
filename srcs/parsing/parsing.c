/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:45:09 by claprand          #+#    #+#             */
/*   Updated: 2025/01/02 12:45:17 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing(t_cub *cub)
{
	if (valid_char(cub) == 1)
		return (error_handler(5), 1);
	else if (only_one_player(cub) == 1)
		return (error_handler(6), 1);
	else if (map_is_close(cub) == 1)
		return (error_handler(7), 1);
	else if (have_texture(cub) == 1)
		return (error_handler(8), 1);
	if (check_rgb(cub) == 1)
		return (error_handler(9), 1);
	else if (valid_texture(cub) == 1)
		return (error_handler(10), 1);
	return (0);
}
