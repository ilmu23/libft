/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:04:35 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/28 19:02:23 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(void *ptr)
{
	t_obj	*obj;

	obj = ft_getvm()->head;
	while (obj)
	{
		if (obj->blk == ptr)
			break ;
		obj = obj->next;
	}
	if (obj)
		obj->blk = NULL;
	free(ptr);
}
