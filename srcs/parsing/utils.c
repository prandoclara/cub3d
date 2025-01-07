/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:49:40 by claprand          #+#    #+#             */
/*   Updated: 2025/01/02 12:56:06 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_master_strndup(char *s, int start, int size)
{
	char	*dest;
	int		i;
	int		s_len;

	i = 0;
	s_len = size - start + 1;
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (i < s_len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	return (dest);
}
