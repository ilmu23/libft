/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_gc_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 23:09:54 by ivalimak          #+#    #+#             */
/*   Updated: 2024/06/07 16:18:04 by ivalimak         ###   ########.fr       */
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

# ifndef _GC_START 
#  define _GC_START 256 
# endif

# ifndef _GC_MAPSIZE
#  define _GC_MAPSIZE 4096
# endif

/*   alloc   */
t_objpair	*gc_newpair(const char *key, const t_obj *obj);

t_obj		*ft_newobj(size_t n);

char		*gc_blkkey(const void *blk);

void		*gc_calloc(size_t n, size_t size);
/*   alloc   */

/*   no alloc   */
/**   obj   */
t_obj		*gc_objmap_get(const char *key);
t_obj		*gc_getobj(const void *blk);

void		gc_objmap_rm(const char *key);
void		gc_objmap_add(const char *key, const t_obj *obj);
void		gc_objmap_addpair(t_list **lst, t_objpair *pair);
/**   obj   */

/**   utils   **/
t_vm		*ft_getvm(void);

void		ft_sweep(void);
/**   utils   **/
/*   no alloc   */

#endif
