/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:56:51 by smayrand          #+#    #+#             */
/*   Updated: 2022/04/29 14:00:58 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static const char	*ft_str(va_list arg, const char *fmt, t_print *src)
{
	char			*s;

	s = va_arg(arg, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		src->len += 6;
	}
	else
	{
		ft_putstr(s);
		src->len += ft_strlen(s);
	}
	return (fmt);
}

static const char	*ft_hex(va_list arg, const char *fmt, t_print *src)
{
	unsigned int	x;

	if (*fmt == 'x')
	{
		x = va_arg(arg, unsigned int);
		ft_phex((unsigned long)x);
		src->len += ft_intlen((unsigned long)x, *fmt);
	}
	else
	{
		x = va_arg(arg, unsigned int);
		ft_puhex((unsigned long)x);
		src->len += ft_intlen((unsigned long)x, *fmt);
	}
	return (fmt);
}

static const char	*ft_ptr(va_list arg, const char *fmt, t_print *src)
{
	unsigned long	x;

	x = va_arg(arg, unsigned long);
	ft_ptrhex((unsigned long)x);
	src->len += ft_intlen_p((unsigned long)x, *fmt) + 2;
	return (fmt);
}

static const char	*ft_nbr(va_list arg, const char *fmt, t_print *src)
{
	int		d;

	if (*fmt == 'd' || *fmt == 'i')
	{
		d = va_arg(arg, int);
		ft_putnbr(d);
		src->len += ft_intlen(d, *fmt);
	}
	else if (*fmt == 'u')
	{
		d = va_arg(arg, int);
		ft_putnbr_u(d);
		src->len += ft_intlen_u(d, *fmt);
	}
	return (fmt);
}

const char	*ft_mod(va_list arg, const char *fmt, t_print *src)
{
	if (*fmt == 'd' || *fmt == 'i')
		ft_nbr(arg, fmt, src);
	else if (*fmt == 'x' || *fmt == 'X')
		ft_hex(arg, fmt, src);
	else if (*fmt == 'p')
		ft_ptr(arg, fmt, src);
	else if (*fmt == 'u')
		ft_nbr(arg, fmt, src);
	else if (*fmt == 's')
		ft_str(arg, fmt, src);
	else if (*fmt == 'c')
	{
		ft_putchar(va_arg(arg, int));
		src->len += 1;
	}
	else if (*fmt == '%')
	{
		ft_putchar('%');
		src->len += 1;
	}
	else
		return (NULL);
	fmt++;
	return (fmt);
}
