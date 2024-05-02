/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgetdelim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:33:54 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 13:15:48 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/ft_file_internal.h"

static inline int8_t	_err(int32_t err);
static inline int32_t	_join(char **buf, size_t *size, int32_t c, ssize_t *n);
static inline uint8_t	_getnewbuf(char **buf, size_t *size);

ssize_t	ft_fgetdelim(char **buf, size_t *size, uint8_t delim, t_file *f)
{
	int32_t	c;
	ssize_t	n;

	if (!size)
	{
		errno = EINVAL;
		return (-1);
	}
	n = 0;
	c = ft_fgetc(f);
	while (c != EOF)
	{
		c = _join(buf, size, c, &n);
		if (c == delim)
			break ;
		c = ft_fgetc(f);
	}
	if (c == _ERR)
		return (-1);
	return (n);
}

static inline int8_t	_err(int32_t err)
{
	errno = err;
	return (_ERR);
}

static inline int32_t	_join(char **buf, size_t *size, int32_t c, ssize_t *n)
{
	if (*n == SSIZE_MAX)
		return _err(EOVERFLOW);
	if (!*buf || *size == (size_t)*n - 1)
	{
		if (!_getnewbuf(buf, size))
			return (EOF);
	}
	(*buf)[(*n)++] = c;
	return (c);
}

static inline uint8_t	_getnewbuf(char **buf, size_t *size)
{
	char	*nbuf;
	uint8_t	ptrap_st;

	if (*size + *size / 2 + 1 < *size)
		return (0);
	ptrap_st = ft_pushtrap_status();
	ft_pushtrap(PTRAP_DISABLE);
	nbuf = ft_calloc(*size + *size / 2 + 1, sizeof(*nbuf));
	ft_pushtrap(ptrap_st);
	if (!nbuf)
		return (0);
	ft_memcpy(nbuf, *buf, *size);
	*size = *size + *size / 2 + 1;
	ft_popblk(*buf);
	*buf = ft_push(nbuf);
	return (1);
}
