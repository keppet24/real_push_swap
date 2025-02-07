/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:36:58 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/02/07 18:30:42 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Parametre : chaine de caractere de la forme "10" ou "1" ou "929292". 
Les fonctions avant filtrent pour faire en sorte que ce soit toujours 
des input de ce style.
But : Convertir la chaine de caractere en long.
Valeur de retour : Un long. Si le parametre est + grand que LONGMAX, 
renvoyer LONGMAX.
*/
long	my_push_swap_strtol(const char *str)
{
	int		i;
	int		signe;
	long	resu;

	signe = 1;
	i = 0;
	resu = 0;
	if (str[0] == '-')
	{
		signe *= -1;
		i++;
	}
	while (str[i])
	{
		if (resu > (9223372036854775807 - (str[i] - 48)) / 10)
		{
			resu = 9223372036854775807;
			return (resu);
		}
		resu = (str[i] - 48) + resu * 10;
		i++;
	}
	return (signe * resu);
}

int	is_overflow(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (my_push_swap_strtol(tab[i]) > 2147483647
			|| my_push_swap_strtol(tab[i]) < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

void	add_to_end(t_a **stash, t_a *new_node)
{
	t_a	*last;

	last = *stash;
	while (last->next)
		last = last->next;
	last->next = new_node;
}

void	add_to_stack(t_a **s1, char *tab)
{
	t_a	*new_node;

	new_node = malloc(sizeof(t_a));
	if (!new_node)
		return ;
	new_node->value = my_push_swap_strtol(tab);
	new_node->value_normalized = 0;
	new_node->next = NULL;
	if (*s1 == NULL)
		*s1 = new_node;
	else
		add_to_end(s1, new_node);
}

int	parsing(int ac, char **av, t_a **s1)
{
	char	**tab;
	char	*join;
	int		i;
	int		size;

	i = 0;
	join = join_all(ac, av);
	if (join == NULL)
		return (0);
	size = countwords(join, ' ');
	tab = ft_split(join, ' ');
	if (is_not_number(tab, size) == 1 || is_doublon(tab, size) == 1
		|| is_overflow(tab, size) == 1)
	{
		free_tab(tab, size);
		free(join);
		write(2, "Error\n", 6);
		return (0);
	}
	while (i < size)
		add_to_stack(s1, tab[i++]);
	free_tab(tab, size);
	free(join);
	return (1);
}
