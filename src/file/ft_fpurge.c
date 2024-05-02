/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fpurge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:21:08 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 09:42:38 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/ft_file_internal.h"

static inline int8_t	_err(int32_t err);

int8_t	ft_fpurge(t_file *f)
{
	t_fbuf	*buf;

	if (!f)
		return (_err(EBADF));
	buf = ft_mapget(getbuffers(), f->path);
	if (!buf)
		return (_err(EBADF));
	buf->rd_cursize = 0;
	buf->wr_cursize = 0;
	return (0);
}

static inline int8_t	_err(int32_t err)
{
	errno = err;
	return (-1);
}
