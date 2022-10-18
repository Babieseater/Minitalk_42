/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:47:24 by smayrand          #+#    #+#             */
/*   Updated: 2022/04/29 13:50:05 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_print
{
	int	len;
	int	width;
}		t_print;

int			ft_printf(const char *fmt, ...);
int			ft_intlen_u(unsigned int nb, char z);
int			ft_intlen_p(unsigned long nb, char z);
int			ft_intlen(long int nb, char z);
char		*ft_modchr(const char *s);
void		ft_phex(unsigned int x);
void		ft_puhex(unsigned int x);
void		ft_ptrhex(unsigned long x);
void		ft_putchar(char c);
void		ft_putnbr_u(unsigned int nb);
void		ft_putnbr(int nb);
void		ft_putstr(char *str);
int			ft_strlen(const char *str);
const char	*ft_read(t_print *src, const char *fmt);
const char	*ft_mod(va_list arg, const char *fmt, t_print *src);

#endif