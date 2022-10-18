/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:52:38 by smayrand          #+#    #+#             */
/*   Updated: 2022/04/29 13:36:25 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	ft_len(long int nb, char z)
{
	long int	i;

	i = 0;
	if (z == 'd' || z == 'i')
	{
		while (nb)
		{
			nb /= 10;
			i++;
		}
	}
	else
	{
		while (nb)
		{
			nb /= 16;
			i++;
		}
	}
	return (i);
}

int	ft_intlen(long int nb, char z)
{
	long int	nbr;
	long int	i;

	if (!nb)
		return (1);
	if (nb < 0)
		nbr = -nb * 10;
	else
		nbr = nb;
	if (z == 'd' || z == 'i' || z == 'x' || z == 'X')
	{
		i = ft_len(nbr, z);
		return (i);
	}
	return (0);
}
