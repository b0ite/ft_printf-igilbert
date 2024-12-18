/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:19:46 by igilbert          #+#    #+#             */
/*   Updated: 2024/11/14 14:26:18 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_s(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_putstr(str);
	return (len);
}
