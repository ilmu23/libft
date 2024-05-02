/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:44:36 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 02:39:49 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"

ssize_t	ft_printf(const char *f, ...);
ssize_t	ft_dprintf(int32_t fd, const char *f, ...);
ssize_t	ft_sprintf(char *s, const char *f, ...);
ssize_t	ft_snprintf(char *s, size_t size, const char *f, ...);

ssize_t	ft_vprintf(const char *f, va_list args);
ssize_t	ft_vdprintf(int32_t fd, const char *f, va_list args);
ssize_t	ft_vsprintf(char *s, const char *f, va_list args);
ssize_t	ft_vsnprintf(char *s, size_t size, const char *f, va_list args);

#endif
