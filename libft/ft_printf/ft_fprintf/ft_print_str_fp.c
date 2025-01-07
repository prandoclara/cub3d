/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_fp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:24:39 by claprand          #+#    #+#             */
/*   Updated: 2024/11/21 14:22:22 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_print_str_fp(char *str, int fd)
{
	int	len;

	len = 0;
	if (!str)
	{
		write(fd, "(null)", 6);
		len = 6;
		return (len);
	}
	ft_putstr_fd(str, fd);
	return (ft_strlen((char *)str));
}
