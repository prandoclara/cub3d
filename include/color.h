/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:23:23 by nicjousl          #+#    #+#             */
/*   Updated: 2025/01/02 13:35:57 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "cub3d.h"

# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define BIG "\033[1m"
# define ITA "\033[3m"
# define FLASH "\033[5m"
# define LOW "\033[2m"
# define INVERT "\033[7m"
# define BAR "\033[9m"
# define BRIGHT_RED "\033[91m"
# define BRIGHT_GREEN "\033[92m"
# define BRIGHT_YELLOW "\033[93m"
# define BRIGHT_BLUE "\033[94m"
# define BRIGHT_MAGENTA "\033[95m"
# define BRIGHT_CYAN "\033[96m"
# define BRIGHT_WHITE "\033[97m"
# define BRIGHT_BLACK "\033[90m"
# define CLEAR_SCREEN "\033[2J"
# define MOVE_CURSOR_TOP_LEFT "\033[H"
# define GREEN_PIXEL 0xFF00
# define MINI_MAP_WALL 0xF003366
# define MINI_MAP_FLOOR 0xFFB8B8B8
# define MM_P 0xFF64FF
# define MINI_MAP_RAY 0xFFFFFFF

#endif