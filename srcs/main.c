/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:28:19 by claprand          #+#    #+#             */
/*   Updated: 2025/01/09 11:28:56 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac == 2)
	{
		init_data(&cub);
		parse_arg(av[1], &cub);
		if (cast_map(av[1], &cub) == 1)
			end_game(&cub);
		if (parsing(&cub) == 1)
			end_game(&cub);
		int i;
		i = 0;
		while(cub.parse->map[i])
		{
			printf("%s\n", cub.parse->map[i]);
			i++;
		}
		i = 0;
		while (cub.parse->map[i])
		{
			printf("strlen %d\n", ft_strlen(cub.parse->map[i]));
			i++;
		}
		if (launch_game(&cub) == 1)
			end_game(&cub);
		close(cub.parse->fd);
		end_game(&cub);
	}
	else
	{
		error_handler(1);
		exit(1);
	}
	return (0);
}
