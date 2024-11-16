/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:49:38 by igilbert          #+#    #+#             */
/*   Updated: 2024/11/16 13:49:43 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ft_printf.h"

void test_timing(const char *test_name, int (*f1)(), int (*f2)(), const char *format, ...) {
    clock_t start, end;
    double time1, time2;
    int ret1, ret2;
    va_list args1, args2;
    
    va_start(args1, format);
    va_copy(args2, args1);
    
    // Test printf
    start = clock();
    ret1 = vprintf(format, args1);
    end = clock();
    time1 = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("\n");
    
    // Test ft_printf
    start = clock();
    ret2 = ft_printf(format, args2);
    end = clock();
    time2 = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("\n");
    printf("Test %s:\n", test_name);
    printf("printf: retour=%d, temps=%fs\n", ret1, time1);
    printf("ft_printf: retour=%d, temps=%fs\n", ret2, time2);
    printf("Résultat: %s\n\n", (ret1 == ret2) ? "OK ✅" : "KO ❌");
    
    va_end(args1);
    va_end(args2);
}

int main(void)
{
    printf("=== DÉBUT DES TESTS ===\n\n");

    // Test caractères
    test_timing("Caractère simple", printf, ft_printf, "Test char: %c\n", 'A');
    test_timing("Plusieurs caractères", printf, ft_printf, "%c %c %c\n", 'X', 'Y', 'Z');

    // Test chaînes
    test_timing("Chaîne simple", printf, ft_printf, "Test string: %s\n", "Hello");
    test_timing("Chaîne vide", printf, ft_printf, "Empty: %s\n", "");
    test_timing("Chaîne NULL", printf, ft_printf, "NULL: %s\n", NULL);

    // Test nombres
    test_timing("Nombre positif", printf, ft_printf, "Nombre: %d\n", 42);
    test_timing("Nombre négatif", printf, ft_printf, "Négatif: %d\n", -42);
    test_timing("Zéro", printf, ft_printf, "Zéro: %d\n", 0);
    test_timing("Grand nombre", printf, ft_printf, "Max int: %d\n", 2147483647);
    test_timing("Petit nombre", printf, ft_printf, "Min int: %d\n", -2147483648);

    // Test unsigned
    test_timing("Unsigned", printf, ft_printf, "Unsigned: %u\n", 4294967295);

    // Test hexadécimal
    test_timing("Hexa min", printf, ft_printf, "Hexa: %x\n", 255);
    test_timing("Hexa maj", printf, ft_printf, "HEXA: %X\n", 255);

    // Test pointeur
    int n = 42;
    test_timing("Pointeur", printf, ft_printf, "Ptr: %p\n", (void*)&n);

    // Test pourcentage
    test_timing("Pourcentage", printf, ft_printf, "100%%\n");

    // Test mixte
    test_timing("Test mixte", printf, ft_printf, "Mix: %d %s %c %x %% %p\n", 
                42, "test", 'A', 255, (void*)&n);

    printf("=== FIN DES TESTS ===\n");
    return (0);
}