/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_gc_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 23:09:54 by ivalimak          #+#    #+#             */
/*   Updated: 2024/06/06 00:57:44 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_GC_INTERNAL_H
# define LFT_GC_INTERNAL_H
# include "lft_gc.h"

# define GCRESET "\e[0m"
# define GCGEN "\e[1mGC: "
# define GCCLEAN "\e[1;36mGC: clean: "
# define GCALLOC "\e[1;34mGC: alloc: "
# define GCOBJ "\e[1;34mGC: obj: "
# define GCSWEEP "\e[1;35mGC: sweep: "
# define GCPUSH "\e[1;32mGC: push: "
# define GCTRAP "\e[1;33mGC: pushtrap: "
# define GCPOP "\e[1;31mGC: pop: "

# define E_ALLOC "\e[1;31mGC: fatal: can't allocate memory for internal use\e[m"

# define _HEXARR "0123456789ABCDEF"

# ifndef GC_START 
#  define GC_START 256 
# endif

/*   alloc   */
t_objpair	*ft_newpair(const char *key, const t_obj *obj);

t_obj		*ft_newobj(size_t n);

char		*ft_blkkey(const void *blk);
/*   alloc   */

/*   no alloc   */
/**   obj   */
t_obj	*ft_objmap_get(const char *key);
t_obj	*ft_getobj(const void *blk);

void	ft_objmap_rm(const char *key);
void	ft_addobj(const char *key, const t_obj *obj);
void	ft_addpair(t_objpair **objs, t_objpair *pair, const uint64_t size);
void	ft_growobjmap(void);
/**   obj   */

/**   utils   **/
t_vm	*ft_getvm(void);

void	ft_sweep(void);
/**   utils   **/
/*   no alloc   */

#endif
