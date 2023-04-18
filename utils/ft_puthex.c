/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:03:56 by maroy             #+#    #+#             */
/*   Updated: 2023/04/18 18:27:49 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_puthex(unsigned long n, int *count)
{
	if (n > 9)
	{
		if (n < 16)
			ft_putchar((n + 87), count);
		else
		{
			ft_puthex((n / 16), count);
			ft_puthex((n % 16), count);
		}
	}
	else
		ft_putchar((n + 48), count);
}
