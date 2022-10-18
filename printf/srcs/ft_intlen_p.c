/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:47:36 by smayrand          #+#    #+#             */
/*   Updated: 2022/04/29 14:00:45 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_intlen_p(unsigned long nb, char z)
{
	unsigned long	i;
	unsigned long	nbr;

	i = 0;
	if (!nb)
		return (1);
	nbr = nb;
	if (z == 'p')
	{
		while (nbr)
		{
			nbr /= 16;
			i++;
		}
		return (i);
	}
	return (0);
}
