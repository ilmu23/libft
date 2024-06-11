/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_gc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:52:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/06/11 17:09:15 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_GC_H
# define LFT_GC_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include "lft_data.h"
# include "lft_limits.h"

# define PTRAP_ENABLE 0x1U
# define PTRAP_DISABLE 0x2U
# define PTRAP_FLUSH 0xCU
# define PTRAP_CLEAN 0x4U
# define PTRAP_POP 0x8U

/*   alloc   */
void	*ft_alloc(size_t n);
void	*ft_calloc(size_t n, size_t size);
void	*ft_arrdup(const void *arr, const size_t size);
void	*ft_register(const void *blk, const size_t size);
/*   alloc   */

/*   no alloc   */
/**   blk   **/
size_t	ft_getblksize(const void *blk);
/**   blk   **/

/**   obj   **/
void	ft_unmark(const void *blk);
void	ft_mark(const void *blk);
/**   obj   **/

/**   pop   **/
void	ft_popall(void);
void	ft_popn(size_t blks);
void	ft_popblk(const void *blk);
void	ft_popblks(size_t blks, ...);
/**   pop   **/

/**   push   **/
void	*ft_push(const void *blk);
void	*ft_pusharr(const void *blk);

void	ft_pushn(size_t blks, ...);
/**   push   **/

/**   pushtrap   **/
uint8_t	ft_pushtrap_status(void);

void	ft_pushtrap(uint8_t op);
/**   pushtrap   **/

/**   utils   **/
void	ft_clean(void);
void	ft_exit(int32_t estat);

int32_t	ft_return(int32_t rval);
/**   utils   **/
/*   no alloc   */

#endif
