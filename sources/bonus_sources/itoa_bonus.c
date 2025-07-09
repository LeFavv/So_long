/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 03:35:16 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/09 03:55:52 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char *ft_itoa_bonus(int nb)
{
    int i;

    i = 0;
    char *result;
    result = malloc(sizeof(char) * 5);
    if (!result)
        return (NULL);
    result[0] = '0';
    result[1] = '0';
    result[2] = '0';
    result[3] = '0';
    result[4] = '\0';
    while (nb)
    {
        result[3 - i] = nb % 10 + '0';
        nb /= 10;
        i++;
    }
    return (result);
}
