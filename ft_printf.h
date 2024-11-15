/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:18:40 by igilbert          #+#    #+#             */
/*   Updated: 2024/11/14 14:09:04 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_putchar(char c);
int	process_s(va_list args);
int	process_p(va_list args);
int	process_d(va_list args);
int	process_i(va_list args);
int	process_u(va_list args);
int	process_x(va_list args);
int	process_capx(va_list args);
int	ft_putnbr(int nb);
int	ft_putstr(char *str);
int	ft_putnbr_base(unsigned long long nb, char *base);
int	in_charset(char c);

#endif