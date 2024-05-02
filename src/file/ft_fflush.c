/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fflush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:38:50 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 09:50:43 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/ft_file_internal.h"

static inline int8_t	_err(int32_t err);
static inline int8_t	_fflush_all(t_hmap *map);
static inline int8_t	_fflush(t_fbuf *buf, uint8_t btype);

int8_t	ft_fflush(t_file *f)
{
	t_hmap	*map;
	t_fbuf	*buf;
	int8_t	rv;

	map = getbuffers();
	if (f)
	{
		buf = ft_mapget(map, f->path);
		if (!buf)
			return (_err(EBADF));
		if (f->mode & (O_RDWR | O_RDONLY))
			rv = _fflush(buf, _RDBUF);
		if (f->mode & (O_RDWR | O_WRONLY))
			rv = _fflush(buf, _WRBUF);
		return (rv);
	}
	return (_fflush_all(map));
}

static inline int8_t	_err(int32_t err)
{
	errno = err;
	return (EOF);
}

static inline int8_t	_fflush_all(t_hmap *map)
{
	int8_t	rv;
	size_t	i;

	i = 0;
	rv = 0;
	while (i < map->size)
	{
		if (map->items[i] && map->items[i] != (void *)HMAP_DEL
				&& !_fflush(map->items[i]->value, _WRBUF))
			rv = _err(EBADF);
		i++;
	}
	return (rv);
}

static inline int8_t	_fflush(t_fbuf *buf, uint8_t btype)
{
	int32_t	rv;

	if (!buf)
		return (0);
	if (btype & _WRBUF)
	{
		rv = write(buf->fd, buf->wr_buf, buf->wr_cursize) == -1;
		buf->wr_cursize = 0;
		return (rv != -1);
	}
	buf->rd_cursize = 0;
	return (1);
}
