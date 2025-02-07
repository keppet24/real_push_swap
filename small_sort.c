/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:42:24 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/02/07 18:30:26 by oettaqi          ###   ########.fr       */
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

void	sort_stack_3(t_a **s1, t_b **s2)
{
	t_a	*temp;
	int	min_val;

	min_val = (*s1)->value;
	temp = (*s1)->next;
	while (temp)
	{
		if (temp->value < min_val)
			min_val = temp->value;
		temp = temp->next;
	}
	while ((*s1)->value != min_val)
		ra(s1);
	pb(s1, s2);
	sort_stack_2(s1);
	pa(s1, s2);
}

void	sort_stack_4(t_a **s1, t_b **s2)
{
	int	i;

	i = 0;
	push_min(s1, s2, i);
	sort_stack_3(s1, s2);
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
		sort_stack_3(s1, s2);
	if (size == 4)
		sort_stack_4(s1, s2);
	if (size == 5)
		sort_stack_5(s1, s2);
	return ;
}
