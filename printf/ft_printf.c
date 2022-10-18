/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:45:36 by smayrand          #+#    #+#             */
/*   Updated: 2022/04/29 14:21:44 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*ft_read(t_print *src, const char *fmt)
{
	char	*next;

	next = ft_modchr(fmt);
	if (next)
		src->width = next - fmt;
	else
		src->width = ft_strlen(fmt);
	write(1, fmt, src->width);
	src->len += src->width;
	while (*fmt && *fmt != '%')
		fmt++;
	return (fmt);
}

int	ft_printf(const char *fmt, ...)
{
	t_print	src;
	va_list	arg;

	va_start(arg, fmt);
	src.len = 0;
	src.width = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			fmt = ft_mod(arg, fmt + 1, &src);
		else
			fmt = ft_read(&src, fmt);
		if (!fmt)
		{
			write(1, "(null)", 6);
			va_end(arg);
			return (src.len);
		}
	}
	va_end(arg);
	return (src.len);
}
