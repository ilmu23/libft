/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 06:51:32 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 13:55:45 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/ft_file_internal.h"

static inline t_file	*_err(int32_t err);
static inline uint8_t	_loadfile(t_file *f, uint8_t ptrap_st);
static inline int32_t	_parsemode(const char *mode);
static inline char	*_getopenmode(const char *mode, int32_t *md);

t_file	*ft_fopen(const char *path, const char *mode)
{
	t_file	*f;
	uint8_t	ptrap_st;
	char	*dpath;

	ptrap_st = ft_pushtrap_status();
	ft_pushtrap(PTRAP_DISABLE);
	f = ft_push(ft_calloc(1, sizeof(*f)));
	dpath = ft_push(ft_strdup(path));
	if (ptrap_st & PTRAP_ENABLE)
		ft_pushtrap(PTRAP_ENABLE);
	if (!f || !dpath)
		return (NULL);
	f->path = dpath;
	f->mode = _parsemode(mode);
	if (f->mode == EOF)
		return (_err(EINVAL));
	f->fd = open(path, f->mode);
	if (f->fd == -1)
		return (NULL);
	if (!_loadfile(f, ptrap_st))
	{
		close(f->fd);
		return (NULL);
	}
	return (f);
}

static inline t_file	*_err(int32_t err)
{
	errno = err;
	return (NULL);
}

static inline uint8_t	_loadfile(t_file *f, uint8_t ptrap_st)
{
	int32_t	rv;
	uint8_t	buf[_FILE_BUFFER_SIZE];
	uint8_t	*tmp;

	if (f->mode & O_WRONLY)
		return (1);
	ft_pushtrap(PTRAP_DISABLE);
	rv = read(f->fd, buf, _FILE_BUFFER_SIZE);
	while (rv > 0)
	{
		tmp = ft_alloc((f->size + rv) * sizeof(*tmp));
		if (!tmp)
			return (0);
		ft_memcpy(tmp, f->sof, f->size);
		ft_memcpy(tmp + f->size, buf, rv);
		f->size += rv;
		f->sof = tmp;
	}
	ft_push(f->sof);
	if (ptrap_st & PTRAP_ENABLE)
		ft_pushtrap(PTRAP_ENABLE);
	if (rv == -1)
		return (0);
	f->cur = f->sof;
	return (1);
}

static inline int32_t	_parsemode(const char *mode)
{
	int32_t	md;

	md = 0;
	mode = _getopenmode(mode, &md);
	if (!mode)
		return (EOF);
	md |= S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
	while (*mode)
	{
		if (*mode == 'e' && !(md & O_CLOEXEC))
			md |= O_CLOEXEC;
		else if (*mode == 'x' && !(md & O_EXCL))
			md |= O_EXCL;
		else
			return (EOF);
		mode++;
	}
	return (md);
}

static inline char	*_getopenmode(const char *mode, int32_t *md)
{
	if (*mode == 'r')
		*md |= O_RDONLY;
	else if (*mode == 'w')
		*md |= O_WRONLY | O_CREAT | O_TRUNC;
	else if (*mode == 'a')
		*md |= O_WRONLY | O_CREAT | O_APPEND;
	else
		return (NULL);
	if (*++mode == '+')
		*md ^= O_RDWR | O_RDONLY | O_WRONLY;
	return ((char *)mode);
}
