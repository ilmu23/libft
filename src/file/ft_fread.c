/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:15:57 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 14:11:43 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/ft_file_internal.h"

static inline size_t	_err(int32_t err);
static inline size_t	_fread(void *buf, size_t size, size_t n, t_file *f);
static inline int8_t	_read(void *buf, size_t n, t_file *f);
static inline int8_t	_bread(t_file *f);

size_t	ft_fread(void *buf, size_t size, size_t n, t_file *f)
{
	t_fbuf	*fbuf;
	size_t	bread;
	uint8_t	ptrap_st;

	if (!f)
		return (_err(EBADF));
	fbuf = ft_mapget(getbuffers(), f->path);
	if (!fbuf)
		return (_err(EBADF));
	ptrap_st = ft_pushtrap_status();
	ft_pushtrap(PTRAP_DISABLE);
	bread = _fread(buf, size, n, f);
	ft_pushtrap(ptrap_st);
	return (bread);
}

static inline size_t	_err(int32_t err)
{
	errno = err;
	return (0);
}

static inline size_t	_fread(void *buf, size_t size, size_t n, t_file *f)
{
	size_t	bread;
	size_t	btrgt;
	int8_t	rval;

	btrgt = size * n;
	while (bread < btrgt)
	{
		if (btrgt - bread >= 8)
			rval = _read(buf, 8, f);
		else
			rval = _read(buf, 1, f);
		if (rval == EOF)
			return (EOF);
		
	}
	return (bread);
}

static inline int8_t	_read(void *buf, size_t n, t_file *f)
{
	int8_t	bread;

	if (f->cur == f->sof + f->size && _bread(f) < 1)
		return (EOF);
	bread = 0;
	if ((f->sof + f->size) - f->cur < n)
	{
		while (n--)
		{
			_read(buf, 1, f);
			bread++;
		}
	}
	else if (n == 8)
		*(uint64_t *)buf = (uint64_t)*f->cur;
	else
		*(uint8_t *)buf = (uint8_t)*f->cur;
	f->cur += n;
	return ((int8_t)n);
}

static inline int8_t	_bread(t_file *f)
{
	t_fbuf	*buf;
	uint8_t	*tmp;
	int32_t	rval;

	buf = ft_mapget(getbuffers(), f->path);
	if (!buf)
		return (_err(EBADF));
	if (buf->rd_cursize)
	{
		tmp = ft_alloc(f->size + buf->rd_cursize);
		ft_memcpy(tmp, f->sof, f->size);
		ft_memcpy(tmp + f->size, buf->rd_buf, buf->rd_cursize);
		f->size += buf->rd_cursize * (tmp != NULL);
		f->cur = tmp + (f->cur - f->sof);
		buf->rd_cursize = 0;
		if (!tmp)
			return (0);
		f->sof = tmp;
	}
	else
	{
		rval = read(buf->fd, buf->rd_buf, _FILE_BUFFER_SIZE);
		if (rval == -1)
			return (EOF);
		buf->rd_cursize = rval;
		return (_bread(f));
	}
	return (1);
}
