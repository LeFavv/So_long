/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:02:42 by vafavard          #+#    #+#             */
/*   Updated: 2025/05/13 16:42:19 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_percent(void)
{
	ft_putchar('%');
	return (1);
}

int	display_specials(const char *str, va_list *args)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count = print_c(va_arg(*args, unsigned int));
	else if (*str == 's')
		count = print_s(va_arg(*args, char *));
	else if (*str == 'd' || *str == 'i')
		count = print_d_and_i(va_arg(*args, int));
	else if (*str == 'u')
		count = print_u(va_arg(*args, unsigned int));
	else if (*str == 'x')
		count = print_hex_low(va_arg(*args, int));
	else if (*str == 'X')
		count = print_hex_top(va_arg(*args, int));
	else if (*str == 'p')
	{
		uintptr_t	temp = va_arg(*args, uintptr_t);
		count = check_value(temp);
	}
	else if (*str == '%')
		count += ft_percent();
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		letter_count;
	va_list	args;
	int		ret;

	if (!str)
		return (-1);
	va_start(args, str);
	letter_count = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			ret = display_specials(str, &args);
			str++;
			letter_count += ret;
		}
		else
		{
			write (1, str++, 1);
			letter_count++;
		}
	}
	va_end(args);
	return (letter_count);
}
