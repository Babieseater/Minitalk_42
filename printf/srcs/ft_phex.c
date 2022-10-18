/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:11:33 by smayrand          #+#    #+#             */
/*   Updated: 2022/04/29 14:01:46 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_phex(unsigned int x)
{
	char	*hex;
	int		result[100];
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	while (x >= 16)
	{
		result[i] = hex[x % 16];
		x = x / 16;
		i++;
	}
	result[i] = hex[x];
	while (i >= 0)
	{
		ft_putchar(result[i]);
		i--;
	}
}

void	ft_puhex(unsigned int x)
{
	char	*hex;
	int		result[100];
	int		i;

	hex = "0123456789ABCDEF";
	i = 0;
	while (x >= 16)
	{
		result[i] = hex[x % 16];
		x = x / 16;
		i++;
	}
	result[i] = hex[x];
	while (i >= 0)
	{
		ft_putchar(result[i]);
		i--;
	}
}

void	ft_ptrhex(unsigned long x)
{
	char			*hex;
	unsigned long	result[100];
	int				i;

	hex = "0123456789abcdef";
	i = 0;
	if (x == 0)
		ft_putstr("0x0");
	else
	{
		ft_putstr("0x");
		while (x >= 16)
		{
			result[i] = hex[x % 16];
			x = x / 16;
			i++;
		}
		result[i] = hex[x];
		while (i >= 0)
		{
			ft_putchar(result[i]);
			i--;
		}
	}
}
