/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taqi <taqi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:24:26 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/02/10 18:02:39 by taqi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize(t_a **s1)
{
	t_a	*parcours;
	t_a	*parcours_reste;
	int	i;

	i = 0;
	parcours = *s1;
	while (parcours)
	{
		i = 0;
		parcours_reste = *s1;
		while (parcours_reste)
		{
			if (parcours->value > parcours_reste->value)
				i++;
			parcours_reste = parcours_reste->next;
		}
		parcours->value_normalized = i;
		parcours = parcours->next;
	}
}

int	find_bit_max(t_a **s1)
{
	t_a	*temp;
	int	max_val;
	int	bit_max;

	bit_max = 0;
	max_val = (*s1)->value_normalized;
	temp = (*s1)->next;
	while (temp)
	{
		if (temp->value > max_val)
			max_val = temp->value;
		temp = temp->next;
	}
	while (max_val >> bit_max != 0)
		bit_max++;
	return (bit_max);
}

void	radix_sort(t_a **s1, t_b **s2)
{
	int	i;
	int	j;
	int	size;

	normalize(s1);
	size = size_of_stack_a(s1);
	i = 0;
	while (!is_sorted_radix(s1))
	{
		j = 0;
		while (j < size)
		{
			if (((*s1)->value_normalized >> i & 1) == 0)
				pb(s1, s2);
			else
				ra(s1);
			j++;
		}
		while (*s2)
			pa(s1, s2);
		i++;
	}
}

void	sort(t_a **s1, t_b **s2)
{
	int	size;

	size = size_of_stack_a(s1);
	if (size <= 5 && !is_sorted(s1))
	{	
		small_sort(s1, s2);
	}
	else
		radix_sort(s1, s2);
}

// int main(int ac, char **av)
// {
// 	t_a *s1 = NULL;
// 	t_b *s2 = NULL;
// 	parsing(ac, av, &s1);
// 	t_a *temp = s1;
// 	//t_a *temp2 = s1;
// 	while (s1)
// 	{
// 		printf("%d\n", s1->value);
// 		s1 = s1->next;
// 	}
// 	printf("======== La stack trie ============== \n");
// 	sort(&temp, &s2);
// 	while (temp)
// 	{
// 		printf("%d\n", temp->value);
// 		temp = temp->next;
// 	}
// 	return (0);
// }
