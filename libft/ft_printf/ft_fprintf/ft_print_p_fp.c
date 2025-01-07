/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_fp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:45:45 by claprand          #+#    #+#             */
/*   Updated: 2024/11/19 12:10:15 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_print_p_fp(void *ptr, int *len, int fd)
{
	unsigned long long	address;
	char				*digits;

	address = (unsigned long long)ptr;
	digits = "0123456789abcdef";
	if (address >= 16)
	{
		ft_print_p_fp((void *)(address / 16), len, fd);
		ft_print_p_fp((void *)(address % 16), len, fd);
	}
	else
	{
		ft_putchar_fd(digits[address], fd);
		(*len)++;
	}
	return (*len);
}

int	ft_print_pp_fp(void *ptr, int *len, int fd)
{
	unsigned long long	address;

	address = (unsigned long long)ptr;
	if (address == 0)
		return (write(fd, "(nil)", 5));
	write(fd, "0x", 2);
	return (ft_print_p_fp(ptr, len, fd) + 2);
}
