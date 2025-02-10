/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taqi <taqi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:42:24 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/02/10 17:59:36 by taqi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_2(t_a **s1)
{
	if ((*s1)->value > (((*s1)->next->value)))
		ra(s1);
	else
		return ;
}

void	sort_stack_3(t_a **s1)
{
	int	a;
	int	b;
	int	c;

	a = (*s1)->value;
	b = (*s1)->next->value;
	c = (*s1)->next->next->value;
	if (a < b && b < c)
		return ;
	else if (a > b && a < c)
		sa(s1);
	else if (a > c && b < c)
		ra(s1);
	else if (a < b && a > c)
		rra(s1);
	else if (a > b && b > c)
	{
		sa(s1);
		rra(s1);
	}
	else if (a < b && b > c)
	{
		sa(s1);
		ra(s1);
	}
}

void	sort_stack_4(t_a **s1, t_b **s2)
{
	int	i;

	i = 0;
	push_min(s1, s2, i);
	sort_stack_3(s1);
	pa(s1, s2);
}

void	sort_stack_5(t_a **s1, t_b **s2)
{
	int	i;

	i = 0;
	push_min(s1, s2, i);
	sort_stack_4(s1, s2);
	pa(s1, s2);
}

void	small_sort(t_a **s1, t_b **s2)
{
	int	size;

	size = size_of_stack_a(s1);
	if (size == 1)
		return ;
	if (size == 2)
		sort_stack_2(s1);
	if (size == 3)
		sort_stack_3(s1);
	if (size == 4)
		sort_stack_4(s1, s2);
	if (size == 5)
		sort_stack_5(s1, s2);
	return ;
}
