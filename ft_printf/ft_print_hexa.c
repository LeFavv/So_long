/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:20:38 by vafavard          #+#    #+#             */
/*   Updated: 2025/05/08 10:21:02 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_low(int args)
{
	int				count;
	unsigned int	transfer;

	transfer = (unsigned int)args;
	count = 0;
	if (transfer >= 16)
		count += print_hex_low(transfer / 16);
	write(1, &"0123456789abcdef"[transfer % 16], 1);
	count++;
	return (count);
}

int	print_hex_top(int args)
{
	int				count;
	unsigned int	transfer;

	transfer = (unsigned int)args;
	count = 0;
	if (transfer >= 16)
		count += print_hex_top(transfer / 16);
	write(1, &"0123456789ABCDEF"[transfer % 16], 1);
	count++;
	return (count);
}
