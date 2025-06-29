/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:28:27 by vafavard          #+#    #+#             */
/*   Updated: 2025/05/13 16:40:00 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

void	ft_putchar(char c);
int		print_c(unsigned int args);
int		print_s(char *args);
int		print_d_and_i(int args);
int		print_u(unsigned int args);
int		print_hex_low(int args);
int		print_hex_top(int args);
int		print_p(uintptr_t addr);
int		display_specials(const char *str, va_list *args);
int		ft_printf(const char *str, ...);
int		t_percent(void);
int		check_value(uintptr_t temp);

#endif