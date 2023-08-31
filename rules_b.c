/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:12:04 by yyasar            #+#    #+#             */
/*   Updated: 2023/06/21 13:10:33 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *stack, int print)
{
	int	index;

	index = 0;
	if (stack->size_a)
	{
		stack->size_b++;
		index = stack->size_b;
		while (--index > 0)
			stack->b[index] = stack->b[index - 1];
		stack->b[0] = stack->a[0];
		index = -1;
		stack->size_a--;
		while (++index < stack->size_a)
			stack->a[index] = stack->a[index + 1];
		if (!print)
			write(1, "pb\n", 3);
	}
}

void	sb(t_stack	*stack, int print)
{
	int	tmp;

	tmp = 0;
	if (stack->size_b < 2)
		return ;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (!print)
		write(1, "sb\n", 3);
}

void	rb(t_stack	*stack, int print)
{
	register int	tmp;
	register int	index;

	index = 0;
	tmp = stack->b[index];
	index++;
	while (index < stack->size_b)
	{
		stack->b[index - 1] = stack->b[index];
		index++;
	}
	stack->b[index - 1] = tmp;
	if (!print)
		write(1, "rb\n", 3);
}

void	rrb(t_stack *stack, int print)
{
	int	tmp;
	int	index;

	index = stack->size_b - 1;
	tmp = stack->b[index];
	while (index)
	{
		stack->b[index] = stack->b[index - 1];
		index--;
	}
	stack->b[index] = tmp;
	if (!print)
		write(1, "rrb\n", 4);
}
