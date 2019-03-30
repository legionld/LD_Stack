/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 20:16:40 by jschille          #+#    #+#             */
/*   Updated: 2019/03/30 21:41:34 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ld_stack.h"

static int		ld_push(t_ld_stack *stack, int val)
{
    int     index;

    if ((index = stack->get_ti(stack)) == 0)
        return (0);
	if (index == -1)
		index = stack->size;
    stack->arr[index - 1] = val;
	stack->en[index - 1] = 1;
	stack->top = index - 1;
	return (1);
}

static int		ld_get_ti(t_ld_stack *stack)
{
    int     i;

    i = -1;
    while (++i < stack->size)
        if (stack->en[i] == 1)
            return (i);
    return (-1);
}

static int		fill_stack(t_ld_stack *stack, int num)
{
	stack->size = num;
	stack->top = -1;
	stack->push = ld_push;
	stack->get_ti = ld_get_ti;
	return (1);
}

t_ld_stack		*ld_stack_init(int num)
{
	t_ld_stack	*stk;
	int			i;

	if (!(stk = (t_ld_stack*)malloc(sizeof(t_ld_stack))))
		return (NULL);
	if (!(stk->arr = (int*)malloc(sizeof(int) * num)))
		return (NULL);
	if (!(stk->en = (int*)malloc(sizeof(int) * num)))
		return (NULL);
	i = -1;
	while (++i < num)
        stk->en[i] = 0;
	fill_stack(stk, num);
	return (stk);
}