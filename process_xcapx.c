/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_xcapx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:57:40 by igilbert          #+#    #+#             */
/*   Updated: 2024/11/14 10:58:12 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_x(va_list args)
{
	unsigned long long	nb;
	int					len;

	nb = va_arg(args, unsigned long long);
	len = ft_putnbr_base(nb, "0123456789abcdef");
	return (len);
}

int	process_capx(va_list args)
{
	unsigned long long	nb;
	int					len;

	nb = va_arg(args, unsigned long long);
	len = ft_putnbr_base(nb, "0123456789ABCDEF");
	return (len);
}
