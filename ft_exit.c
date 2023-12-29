/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:46:19 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/28 22:48:22 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(int estat)
{
	t_vm	*vm;

	vm = ft_getvm();
	ft_popall(vm);
	ft_clean(vm);
	exit(estat);
}
