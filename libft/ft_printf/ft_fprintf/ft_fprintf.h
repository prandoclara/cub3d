/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:14:54 by claprand          #+#    #+#             */
/*   Updated: 2024/11/21 14:25:30 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_int_len(int n);
int	ft_hex_len(int n);
int	ft_ui_len(unsigned int n);
int	ft_print_char_fp(int fd, char c);
int	ft_print_int_fp(int n, int fd);
int	ft_print_pp_fp(void *ptr, int *len, int fd);
int	ft_print_p_fp(void *ptr, int *len, int fd);
int	ft_print_percent_fp(char c, int fd);
int	ft_print_str_fp(char *str, int fd);
int	ft_print_u_fp(unsigned int n, int fd);
int	ft_print_x_fp(unsigned int x, char c, int *len, int fd);
int	ft_printux_fp(unsigned int x, char c, int *len, int fd);
int	ft_print_conversion_fp(va_list *arg, char *s, int i, int fd);
int	ft_fprintf(int fd, const char *str, ...);

#endif