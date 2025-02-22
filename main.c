/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taqi <taqi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:49:03 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/02/10 18:06:11 by taqi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all_stack(t_a **s1, t_b **s2)
{
	t_a	*tmp_a;
	t_b	*tmp_b;

	while (*s1)
	{
		tmp_a = (*s1)->next;
		free(*s1);
		*s1 = tmp_a;
	}
	while (*s2)
	{
		tmp_b = (*s2)->next;
		free(*s2);
		*s2 = tmp_b;
	}
}

int	main(int ac, char **av)
{
	t_a	*s1;
	t_b	*s2;

	s1 = NULL;
	s2 = NULL;
	if (ac == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	parsing(ac, av, &s1);
	sort(&s1, &s2);
	free_all_stack(&s1, &s2);
}
