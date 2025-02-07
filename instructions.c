/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:40:13 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/02/07 18:31:09 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_a **s1)
{
	t_a	*top;
	t_a	*parcours;

	top = *s1;
	*s1 = (*s1)->next;
	parcours = *s1;
	while (parcours->next)
		parcours = parcours->next;
	parcours->next = top;
	top->next = NULL;
	write(1, "ra\n", 3);
}

void	pb(t_a **s1, t_b **s2)
{
	t_a	*top;
	t_b	*temp;

	top = *s1;
	*s1 = (*s1)->next;
	temp = *s2;
	*s2 = (t_b *)top;
	top->next = (t_a *)temp;
	write(1, "pb\n", 3);
}
	//top->value = top->value_normalized;
	//printf("pb");

void	rra(t_a **s1)
{
	t_a	*last;
	t_a	*second_last;

	if (!*s1 || !(*s1)->next)
		return ;
	second_last = NULL;
	last = *s1;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *s1;
	*s1 = last;
	write(1, "rra\n", 4);
}

void	pa(t_a **s1, t_b **s2)
{
	t_b	*top;
	t_a	*temp;

	top = *s2;
	*s2 = (*s2)->next;
	temp = *s1;
	*s1 = (t_a *)top;
	top->next = (t_b *)temp;
	write(1, "pa\n", 3);
}
	//printf("pa");
	//top->value = top->value_normalized;