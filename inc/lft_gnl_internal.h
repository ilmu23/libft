/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_gnl_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:49:44 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 23:09:34 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_GNL_INTERNAL_H
# define LFT_GNL_INTERNAL_H
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

/*   alloc   */
char	*bufcopy(char *buf, char **out);
/*   alloc   */

/*   no alloc   */
char	*bufshift(char *buf, char *src, size_t n);
/*   no alloc   */

#endif
