/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugmsg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:43:46 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/02 15:43:21 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printarg(char f, va_list args);

void	ft_debugmsg(char *pfx, char *f, ...)
{
	va_list	args;

	if (!DEBUG_MSG)
		return ;
	va_start(args, f);
	ft_putstr_fd(pfx, DEBUGFD);
	while (*f)
	{
		if (*f != '%')
			ft_putchar_fd(*f, DEBUGFD);
		else
			ft_printarg(f[1], args);
		f += 1 + (*f == '%');
	}
	ft_putstr_fd(GCRESET, DEBUGFD);
	ft_putchar_fd('\n', DEBUGFD);
}

void	ft_printarg(char f, va_list args)
{
	if (f == '%')
		ft_putchar_fd('%', DEBUGFD);
	else if (f == 'c')
		ft_putchar_fd(va_arg(args, int), DEBUGFD);
	else if (f == 'd' || f == 'i')
		ft_debugnbr(va_arg(args, long));
	else if (f == 'u')
		ft_debugunbr(va_arg(args, unsigned long));
	else if (f == 's')
		ft_putstr_fd(va_arg(args, char *), DEBUGFD);
	else if (f == 'x' || f == 'X' || f == 'p')
		ft_debugxnbr(va_arg(args, unsigned long), f);
}
