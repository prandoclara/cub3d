/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_fp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:46:17 by claprand          #+#    #+#             */
/*   Updated: 2024/11/19 12:10:22 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_print_u_fp(unsigned int n, int fd)
{
	if (n == 0 || (n > 0 && n <= 9))
	{
		ft_putchar_fd(n + '0', fd);
		return (ft_ui_len(n));
	}
	else if (n >= 10)
	{
		ft_print_u_fp(n / 10, fd);
	}
	ft_putchar_fd(n % 10 + '0', fd);
	return (ft_ui_len(n));
}
