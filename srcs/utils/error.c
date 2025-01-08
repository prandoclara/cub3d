/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:59:50 by nicjousl          #+#    #+#             */
/*   Updated: 2025/01/08 11:12:08 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	error_handler2(int n)
{
	if (n == 12)
		ft_fprintf(2, RESET RED"Couldn't create the window\n"RESET);
	else if (n == 13)
		ft_fprintf(2, RESET RED"PLAYER PROBLEM\n"RESET);
	else if (n == 14)
		ft_fprintf(2, RESET RED"MLX PROBLEM\n"RESET);
	else if (n == 15)
		ft_fprintf(2, RESET RED"Couldn't init ray structure properly\n"RESET);
	else if (n == 16)
		ft_fprintf(2, RESET RED"Couldn't create the image\n"RESET);
	else if (n == 17)
		ft_fprintf(2, RESET RED"Error while allocating memory\n"RESET);
	else if (n == 18)
		ft_fprintf(2, RESET RED"Error while downloading textures\n"RESET);
	else if (n == 19)
		ft_fprintf(2, RESET RED"Unable to retrieve the texture address\n"RESET);
	else if (n == 20)
		ft_fprintf(2, RESET RED"Missing textures path\n"RESET);
}

void	error_handler(int n)
{
	ft_fprintf(2, RED BIG FLASH"ERROR\n"RESET);
	if (n == 1)
		ft_fprintf(2, RESET RED"This program need one map\n"RESET);
	else if (n == 2)
		ft_fprintf(2, RESET RED"The extention need to be a '.cub'\n"RESET);
	else if (n == 3)
		ft_fprintf(2, RESET RED"Error while open map\n"RESET);
	else if (n == 4)
		ft_fprintf(2, RESET RED"The map must be a file\n"RESET);
	else if (n == 5)
		ft_fprintf(2, RESET RED"The map have invalid char\n"RESET);
	else if (n == 6)
		ft_fprintf(2, RESET RED"Only one player allowed\n"RESET);
	else if (n == 7)
		ft_fprintf(2, RESET RED"The map is not close\n"RESET);
	else if (n == 8)
		ft_fprintf(2, RESET RED"All the textures path are needed\n"RESET);
	else if (n == 9)
		ft_fprintf(2, RESET RED"RGB PROBLEM\n"RESET);
	else if (n == 10)
		ft_fprintf(2, RESET RED"TEXTURE PROBLEM\n"RESET);
	else if (n == 11)
		ft_fprintf(2, RESET RED"Can't find mlx pointer\n"RESET);
	else if (n > 11)
		error_handler2(n);
}
