/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:59:30 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 12:02:15 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	skip_texture_name(char *texture, int *i, int *j, char *texture_name)
{
	while (texture[++(*i)])
	{
		while (texture[*i] == texture_name[*j])
		{
			(*i)++;
			(*j)++;
		}
		if (texture_name[*j] == '\0')
			break ;
	}
}

void	skip_spaces(char *texture, int *i)
{
	while (texture[*i] == ' ')
		(*i)++;
}

char	*copy_path(char *texture, int i, char *str)
{
	int	h;

	h = 0;
	while (texture[i] && texture[i] != ' ')
	{
		str[h] = texture[i];
		i++;
		h++;
	}
	return (str);
}
