/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:52:59 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 15:59:17 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*ft_pfgetfdp(void)
{
	static int	fd = 1;

	return (&fd);
}

void	ft_pfsetfd(int fd)
{
	int	*fdp;

	fdp = ft_pfgetfdp();
	*fdp = fd;
}

int	ft_pfgetfd(void)
{
	return (*ft_pfgetfdp());
}

static int	putprefix(int spaces, int *sign, int *flags)
{
	if (*sign < 0 && spaces > 0)
	{
		*sign = *sign * -1;
		return (ft_putchar_fd('-', ft_pfgetfd()));
	}
	if (flags[4] == 1)
	{
		flags[4] = 0;
		return (ft_putstr_fd("0x", ft_pfgetfd()));
	}
	if (flags[4] == 2)
	{
		flags[4] = 0;
		return (ft_putstr_fd("0X", ft_pfgetfd()));
	}
	if (flags[5] == 1 && *sign >= 0)
		return (ft_putchar_fd('+', ft_pfgetfd()));
	if (flags[5] == 2 && *sign >= 0)
		return (ft_putchar_fd(' ', ft_pfgetfd()));
	return (0);
}

int	putpadding(int spaces, char c, int *sign, int *flags)
{
	int	ret;
	int	out;

	out = 0;
	ret = 0;
	if (flags[2] == 0 && spaces >= 0 && c == '0' && flags[5] > 0)
		spaces++;
	if (*sign >= 0 && c == '0' && flags[2] == 0 && flags[3] == -1)
		spaces--;
	else if (flags[2] > flags[3] && c == ' ' && flags[5] > 0 && *sign < 0)
		spaces++;
	if (c == '0' && (*sign < 0 || flags[4] > 0 || flags[5] > 0))
	{
		ret = putprefix(spaces, sign, flags);
		out += ret;
	}
	while (spaces > 0 && ret >= 0)
	{
		ret = ft_putchar_fd(c, ft_pfgetfd());
		out += ret;
		spaces--;
	}
	if (ret < 0)
		return (-1);
	return (out);
}
