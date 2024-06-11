/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:49:48 by ivalimak          #+#    #+#             */
/*   Updated: 2024/06/07 15:24:28 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_DATA_H
# define LFT_DATA_H
# include <stdlib.h>
# include <stdint.h>

typedef enum e_base
{
	BINARY,
	OCTAL,
	DECIMAL,
	HEX
}	t_base;

typedef struct s_hmap_pair	t_hmap_pair;
typedef struct s_hmap		t_hmap;
typedef struct s_list		t_list;

// internal structures
typedef struct s_objpair	t_objpair;
typedef struct s_objmap		t_objmap;
typedef struct s_obj		t_obj;
typedef struct s_vm			t_vm;

struct s_hmap_pair
{
	const char	*key;
	void		*value;
};

struct s_hmap
{
	size_t		size;
	size_t		bsize;
	size_t		count;
	t_hmap_pair	**items;
};

struct s_list
{
	const void	*blk;
	size_t		*size;
	t_list		*next;
	t_list		*prev;
};

struct s_objpair
{
	const char	*key;
	const t_obj	*obj;
};

struct s_objmap
{
	size_t		size;
	size_t		bsize;
	uint64_t	count;
	t_list		**objs;
};

struct s_obj
{
	size_t		marks;
	size_t		traps;
	size_t		blksize;
	size_t		asize;
	const void	*blk;
	t_obj		*next;
	t_obj		*nfree;
	t_obj		*pfree;
};

struct s_vm
{
	t_obj		*head;
	t_obj		*free;
	uint8_t		ptrap;
	t_objmap	objmap;
	uint64_t	maxobjs;
	uint64_t	objcount;
};

#endif
