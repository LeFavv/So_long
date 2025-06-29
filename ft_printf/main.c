#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	// //test %u
	printf("printf= %u  %u  %u  \n", 42, 0, 132);
	ft_printf("ft_printf = %u  %u  %u  \n", 42, 0, 132);
    printf("printf = %u\n", 0);
	ft_printf("ft_printf = %u\n", 0);
	int nb;
    nb = printf("printf = %u\n", INT_MAX);
	printf("Count printf = %d\n", nb);
	nb = ft_printf("printf = %u\n", INT_MAX);
	ft_printf("Count ft_printf = %d\n", nb);
    printf("printf = %u\n", INT_MIN);
	ft_printf("ft_printf = %u\n", INT_MIN);
    printf("printf = %u\n", -5);
	ft_printf("ft_printf = %u\n", -5);
    printf("printf = %u\n", 132);
	ft_printf("ft_printf = %u\n", 132);
	
	// //test %x
	// // int nb;
	printf("printf = \n%x\n%x\n%x\n\n", 42, 0, 132);
	ft_printf("ft_printf = \n%x\n%x\n%x\n\n", 42, 0, 132);
	printf("printf = %x\n", -1);
	ft_printf("ft_printf = %x\n", -1);
    printf("printf = %x\n", 0);
	ft_printf("ft_printf = %x\n", 0);
	nb = printf("printf = %x\n", INT_MAX);
	printf("Count printf = %d\n", nb);
	nb = ft_printf("printf = %x\n", INT_MAX);
	ft_printf("Count ft_printf = %d\n", nb);
    printf("printf = %x\n", INT_MIN);
	ft_printf("ft_printf = %x\n", INT_MIN);
    printf("printf = %x\n", -5);
	ft_printf("ft_printf = %x\n", -5);
    printf("printf = %x\n", 56);
	ft_printf("ft_printf = %x\n", 56);
	
	// //test %X
	// // int	nb;
	printf("printf = \n%X\n%X\n%X\n\n", 42, 0, 132);
	ft_printf("ft_printf = \n%X\n%X\n%X\n\n", 42, 0, 132);
	printf("printf = %X\n", -1);
	ft_printf("ft_printf = %X\n", -1);
    printf("printf = %X\n", 0);
	ft_printf("ft_printf = %X\n\n", 0);
	nb = printf("printf = %X\n", INT_MAX);
	printf("Count printf = %d\n", nb);
	nb = ft_printf("printf = %X\n", INT_MAX);
	ft_printf("Count ft_printf = %d\n", nb);
    printf("printf = %X\n", INT_MIN);
	ft_printf("ft_printf = %X\n", INT_MIN);
    printf("printf = %X\n", -5);
	ft_printf("ft_printf = %X\n", -5);
    printf("printf = %X\n", 56);
	ft_printf("ft_printf = %X\n", 56);
	
	// //test %p
	char *b = NULL;
	int	a;
	int ***c;
    printf("%p\n%p\n%p\n", &b, &a, &c);
	ft_printf("%p\n%p\n%p\n", &b, &a, &c);
	
	// // int nb;
	char *s = NULL;
	nb = printf("%s", s);
	printf("%d\n\n", nb);
	
	nb = ft_printf("%s", s);
	printf("%d\n\n", nb);
	printf(" %i \n", -1);
	ft_printf(" %i \n", -1);

	//ultimate test
	//int	a;
	int nb1;
	int nb2;
	nb1 = printf("Le %s ultime %d est la%%%%%% meilleur %c%c%c%c%c %p, %x %X\n\n", "test", 42, 'e', 'c', 'o', 'l', 'e', &a,42, 42);
	nb2 = ft_printf("Le %s ultime %d est%%%%%% la meilleur %c%c%c%c%c %p, %x %X\n\n", "test", 42, 'e', 'c', 'o', 'l', 'e', &a,42, 42);
	printf("printf = %d\n", nb1);
	ft_printf("ft_printf = %d\n", nb2);

	printf(" %p  %p  ", NULL, NULL);
	printf("\n");
	ft_printf(" %p  %p  ", NULL, NULL);
	printf("\n");
    return (0);
}
