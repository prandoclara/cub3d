/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_fp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:23:06 by claprand          #+#    #+#             */
/*   Updated: 2024/11/19 12:10:11 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_print_int_fp(int n, int fd)
{
	long int	nb;

	nb = n;
	ft_putnbr_fd(nb, fd);
	return (ft_int_len(nb));
}
