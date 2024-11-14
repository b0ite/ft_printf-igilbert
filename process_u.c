/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:56:04 by igilbert          #+#    #+#             */
/*   Updated: 2024/11/14 11:46:44 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_u(va_list args)
{
	unsigned long	nb;
	int				len;

	nb = va_arg(args, int);
	len = ft_putnbr(nb);
	return (len);
}
