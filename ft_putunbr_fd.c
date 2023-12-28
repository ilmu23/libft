/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:01:59 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/28 14:19:48 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	char	*nbr;
	int		ret;

	nbr = ft_uitoa(n);
	if (!nbr)
		return (-1);
	ret = ft_putstr_fd(nbr, fd);
	return (ret);
}
