/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:02:06 by igilbert          #+#    #+#             */
/*   Updated: 2024/11/14 14:12:18 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_d(va_list args)
{
	return (ft_putnbr((int)va_arg(args, int)));
}
