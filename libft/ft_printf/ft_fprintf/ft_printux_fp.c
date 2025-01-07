/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printux_fp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:35:59 by claprand          #+#    #+#             */
/*   Updated: 2024/11/19 12:10:26 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_printux_fp(unsigned int x, char c, int *len, int fd)
{
	if (x >= 16)
	{
		ft_printux_fp(x / 16, c, len, fd);
		ft_printux_fp(x % 16, c, len, fd);
	}
	else
	{
		if (x <= 9)
		{
			ft_putchar_fd(x + 48, fd);
			*len += ft_hex_len(x);
		}
		else
		{
			ft_putchar_fd(ft_toupper(x - 10 + 97), fd);
			*len += ft_hex_len(x);
		}
	}
	return (*len);
}
