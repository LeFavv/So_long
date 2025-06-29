/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:22:07 by vafavard          #+#    #+#             */
/*   Updated: 2025/05/07 19:36:04 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(unsigned int args)
{
	int	count;

	count = 1;
	ft_putchar(args);
	return (count);
}

int	print_s(char *args)
{
	int	count;

	count = 0;
	if (!args)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (*args)
	{
		ft_putchar(*args);
		args++;
		count++;
	}
	return (count);
}
