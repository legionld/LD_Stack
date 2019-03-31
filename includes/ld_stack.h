/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:58:18 by jschille          #+#    #+#             */
/*   Updated: 2019/03/31 15:12:56 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LD_STACK_H
# define LD_STACK_H
# include <stdlib.h>
# include "libft/libft.h"

typedef struct  s_ld_stack t_ld_stack;

struct  s_ld_stack
{
	int		size;
	int		top;
	int		*arr;
	int		*en;

	int		(*get_ti)(t_ld_stack *);
	void	(*print)(t_ld_stack *);
	int		(*del_num)(t_ld_stack *);
	int		(*del_stack)(t_ld_stack *);
	int		(*shift_up)(t_ld_stack *);
	int		(*shift_down)(t_ld_stack *);
	int		(*swap)(t_ld_stack *);
	int		(*push)(t_ld_stack *, int);
};

t_ld_stack    		*ld_stack_init(int num);
void				ld_set_destructors(t_ld_stack *stack);
void				ld_set_operations(t_ld_stack *stack);

#endif