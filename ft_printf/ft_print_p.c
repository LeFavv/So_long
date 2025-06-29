/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:36:04 by vafavard          #+#    #+#             */
/*   Updated: 2025/05/13 16:39:07 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(uintptr_t addr)
{
	int		count;

	count = 0;
	if (addr >= 16)
		count += print_p(addr / 16);
	write(1, &"0123456789abcdef"[addr % 16], 1);
	count++;
	return (count);
}

int check_value(uintptr_t temp)
{
    int count;

    count = 0;
    if (temp != 0)
		{
			write (1, "0x", 2);
			count += 2;
            count += print_p(temp);
        }
    else
    {
        write(1, "(nil)", 5);
		count += 5;
    }
    return (count);
}
