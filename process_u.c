/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:56:04 by igilbert          #+#    #+#             */
/*   Updated: 2024/11/14 14:02:25 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_u(va_list args)
{
	unsigned int	nb;
	int				len;

	nb = va_arg(args, unsigned int);
	len = ft_putnbr(nb);
	return (len);
}
