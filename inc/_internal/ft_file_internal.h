/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 06:29:18 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 14:10:48 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_INTERNAL_H
# define FT_FILE_INTERNAL_H
# include <errno.h>
# include <fcntl.h>
# include "ft_stdio/ft_file.h"

# define _RDBUF 0x1U
# define _WRBUF 0x2U

# define _FILE_BUFFER_SIZE 4096

# define _ERR -2

typedef struct s_file
{
	int32_t	fd;
	int32_t	mode;
	uint8_t	*sof;
	uint8_t	*cur;
	size_t	size;
	char	*path;
}	t_file;

typedef struct s_fbuf
{
	int32_t		fd;
	uint8_t		rd_buf[_FILE_BUFFER_SIZE];
	uint8_t		wr_buf[_FILE_BUFFER_SIZE];
	uint16_t	rd_cursize;
	uint16_t	wr_cursize;
}	t_fbuf;

// utils.c
t_hmap	*getbuffers(void);

#endif
