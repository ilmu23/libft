/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 06:27:45 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 11:36:13 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H
# include "libft.h"

typedef struct s_file	t_file;

# ifndef EOF
#  define EOF -1
# endif

t_file	*ft_fopen(const char *path, const char *mode);
t_file	*ft_freopen(const char *path, const char *mode, t_file *f);

int8_t	ft_fclose(t_file *f);

int8_t	ft_fflush(t_file *f);
int8_t	ft_fpurge(t_file *f);

int32_t	ft_fileno(t_file *f);

int32_t	ft_fgetc(t_file *f);
ssize_t	ft_fgetdelim(char **buf, size_t *bsize, uint8_t delim, t_file *f);
ssize_t	ft_fgetline(char **buf, size_t *bsize, t_file *f);

size_t	ft_fread(void *buf, size_t size, size_t n, t_file *f);
size_t	ft_fwrite(void *buf, size_t size, size_t n, t_file *f);

#endif
