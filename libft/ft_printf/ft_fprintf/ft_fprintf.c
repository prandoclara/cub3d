/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:53:31 by claprand          #+#    #+#             */
/*   Updated: 2024/11/21 14:27:02 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_print_conversion_fp(va_list *arg, char *s, int i, int fd)
{
	int	len;

	len = 0;
	if (s[i] == 'c')
		len = ft_print_char_fp((int)va_arg(*arg, int), fd);
	else if (s[i] == 's')
		len = ft_print_str_fp((char *)va_arg(*arg, char *), fd);
	else if (s[i] == 'd' || s[i] == 'i')
		len = ft_print_int_fp((int)va_arg(*arg, int), fd);
	else if (s[i] == 'x')
		len = ft_print_x_fp((unsigned int)va_arg(*arg, unsigned int), s[i],
				&len, fd);
	else if (s[i] == 'X')
		len = ft_printux_fp((unsigned int)va_arg(*arg, unsigned int), s[i],
				&len, fd);
	else if (s[i] == 'p')
		len = ft_print_pp_fp((void *)va_arg(*arg, void *), &len, fd);
	else if (s[i] == 'u')
		len = ft_print_u_fp((unsigned int)va_arg(*arg, unsigned int), fd);
	else if (s[i] == '%')
		len = ft_print_percent_fp('%', fd);
	return (len);
}

int	ft_fprintf(int fd, const char *str, ...)
{
	va_list	args;
	int		i;
	int		printed_char_nb;

	i = -1;
	printed_char_nb = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			printed_char_nb += ft_print_conversion_fp(&args, (char *)str, i + 1,
					fd);
			i++;
		}
		else
		{
			printed_char_nb++;
			ft_putchar_fd(str[i], fd);
		}
	}
	va_end(args);
	return (printed_char_nb);
}
