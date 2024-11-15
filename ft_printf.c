/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:28:06 by igilbert          #+#    #+#             */
/*   Updated: 2024/11/14 14:49:20 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	in_charset(char c)
{
	int		i;
	char	*charset;

	i = 0;
	charset = "cspdiuxX%";
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	print_correct(char const *str, va_list args, int index, int *len)
{
	char	c;

	c = str[index];
	if (c == 'c')
		*len += ft_putchar(va_arg(args, int));
	if (c == 's')
		*len += process_s(args);
	if (c == 'p')
		*len += process_p(args);
	if (c == 'd')
		*len += process_d(args);
	if (c == 'i')
		*len += process_i(args);
	if (c == 'u')
		*len += process_u(args);
	if (c == 'x')
		*len += process_x(args);
	if (c == 'X')
		*len += process_capx(args);
	if (c == '%')
		*len += ft_putchar('%');
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (in_charset(str[i + 1]))
			{
				print_correct(str, args, i + 1, &len);
				i++;
			}
			else if (str[i + 1] == ' ')
				i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}

#include <stdio.h>
#include <limits.h>

int main(void)
{
	int len1, len2;

	// Test characters
	printf("\n----- Testing characters -----\n");
	len1 = printf("Original: %c %c %c\n", 'a', 'b', 'c');
	len2 = ft_printf("Custom  : %c %c %c\n", 'a', 'b', 'c');
	printf("Lengths: %d vs %d\n", len1, len2);

	// Test strings
	printf("\n----- Testing strings -----\n");
	len1 = printf("Original: %s %s\n", "Hello", "World");
	len2 = ft_printf("Custom  : %s %s\n", "Hello", "World");
	printf("Lengths: %d vs %d\n", len1, len2);
	
	// Test NULL string
	len1 = printf("Original NULL: %s\n", NULL);
	len2 = ft_printf("Custom NULL : %s\n", NULL);
	printf("Lengths: %d vs %d\n", len1, len2);

	// Test numbers
	printf("\n----- Testing numbers -----\n");
	len1 = printf("Original: %d %i %u\n", 42, -9, 4242);
	len2 = ft_printf("Custom  : %d %i %u\n", 42, -9, 4242);
	printf("Lengths: %d vs %d\n", len1, len2);

	// Test hexadecimal
	printf("\n----- Testing hexadecimal -----\n");
	len1 = printf("Original: %x %X\n", 255, 255);
	len2 = ft_printf("Custom  : %x %X\n", 255, 255);
	printf("Lengths: %d vs %d\n", len1, len2);

	// Test pointers
	int num = 42;
	printf("\n----- Testing pointers -----\n");
	len1 = printf("Original: %p\n", &num);
	len2 = ft_printf("Custom  : %p\n", &num);
	printf("Lengths: %d vs %d\n", len1, len2);

	// Test edge cases
	printf("\n----- Testing edge cases -----\n");
	len1 = printf("Original: %d %u\n", INT_MAX, UINT_MAX);
	len2 = ft_printf("Custom  : %d %u\n", INT_MAX, UINT_MAX);
	printf("Lengths: %d vs %d\n", len1, len2);

	// Test percentage
	printf("\n----- Testing percentage -----\n");
	len1 = printf("Original: 100%%\n");
	len2 = ft_printf("Custom  : 100%%\n");
	printf("Lengths: %d vs %d\n", len1, len2);

	// Test mixed format
	printf("\n----- Testing mixed format -----\n");
	len1 = printf("Original: %s has %d %s and %c %x\n", "User", 3, "apples", '!', 123);
	len2 = ft_printf("Custom  : %s has %d %s and %c %x\n", "User", 3, "apples", '!', 123);
	printf("Lengths: %d vs %d\n", len1, len2);

	return (0);
}
