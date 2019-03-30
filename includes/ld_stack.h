#ifndef LD_STACK_H
# define LD_STACK_H
# include <stdlib.h>

typedef struct  s_ld_stack t_ld_stack;

struct  s_ld_stack
{
	int		size;
	int		top;
	int		*arr;
	int		*en;

	int		(*push)(t_ld_stack *, int);
	int		(*get_ti)(t_ld_stack *);
};

t_ld_stack    		*ld_stack_init(int num);

#endif