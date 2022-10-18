/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:53:20 by smayrand          #+#    #+#             */
/*   Updated: 2022/04/29 13:49:26 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_intlen_u(unsigned int nb, char z)
{
	unsigned int	i;
	unsigned int	nbr;

	i = 0;
	if (!nb)
		return (1);
	nbr = nb;
	if (z == 'u')
	{
		while (nbr)
		{
			nbr /= 10;
			i++;
		}
		return (i);
	}
	return (0);
}
