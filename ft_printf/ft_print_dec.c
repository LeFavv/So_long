/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:23:38 by vafavard          #+#    #+#             */
/*   Updated: 2025/05/07 19:36:46 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_d_and_i(int args)
{
	long	nb;
	int		count;

	count = 0;
	nb = args;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		count += 1;
	}
	if (nb >= 10)
	{
		count += print_d_and_i(nb / 10);
		ft_putchar(nb % 10 + '0');
		count++;
	}
	else
	{
		ft_putchar(nb + '0');
		count++;
	}
	return (count);
}

int	print_u(unsigned int args)
{
	int		count;

	count = 0;
	if (args >= 10)
	{
		count += print_u(args / 10);
		ft_putchar(args % 10 + '0');
		count++;
	}
	else
	{
		ft_putchar(args + '0');
		count++;
	}
	return (count);
}
