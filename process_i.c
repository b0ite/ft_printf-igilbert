/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:38:52 by igilbert          #+#    #+#             */
/*   Updated: 2024/11/14 10:39:35 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_i(va_list args)
{
	long	nb;
	int		len;

	nb = va_arg(args, int);
	len = ft_putnbr(nb);
	return (len);
}