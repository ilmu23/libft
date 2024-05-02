/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileno.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:27:17 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 09:32:36 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/ft_file_internal.h"

static inline int32_t	_err(int32_t err);

int32_t	ft_fileno(t_file *f)
{
	if (!f || !ft_mapget(getbuffers(), f->path))
		return (_err(EBADF));
	return (f->fd);
}

static inline int32_t	_err(int32_t err)
{
	errno = err;
	return (-1);
}
