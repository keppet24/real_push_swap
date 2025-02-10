/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taqi <taqi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:45:49 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/02/10 18:02:33 by taqi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_of_stack_a(t_a **s1)
{
	t_a	*parcours;
	int	i;

	i = 0;
	parcours = *s1;
	while (parcours)
	{
		parcours = parcours->next;
		i++;
	}
	return (i);
}

int	size_of_stack_b(t_b **s1)
{
	t_b	*parcours;
	int	i;

	i = 0;
	parcours = *s1;
	while (parcours)
	{
		parcours = parcours->next;
		i++;
	}
	return (i);
}

void	push_min(t_a **s1, t_b **s2, int i)
{
	int	min_pos;
	int	min_val;
	t_a	*temp;

	temp = *s1;
	min_pos = 0;
	min_val = (*s1)->value;
	while (temp)
	{
		if (temp->value < min_val)
		{
			min_val = temp->value;
			min_pos = i;
		}
		temp = temp->next;
		i++;
	}
	while ((*s1)->value != min_val)
	{
		if (min_pos > 2)
			rra(s1);
		else
			ra(s1);
	}
	pb(s1, s2);
}

int	is_sorted_radix(t_a **s1)
{
	t_a	*temp;	

	temp = *s1;
	while (temp && temp->next)
	{
		if (temp->value_normalized > temp->next->value_normalized)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_sorted(t_a **s1)
{
	t_a	*temp;	

	temp = *s1;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
