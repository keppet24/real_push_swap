/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:32:57 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/02/07 18:30:04 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_new_av_invalid(int ac, char **new_av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		if (new_av[i] == NULL)
			return (1);
		j = 0;
		if (new_av[i][0] == 32 || new_av[i][0] == 0)
			return (1);
		j++;
		while (new_av[i][j])
		{
			if (new_av[i][j] == 32 && new_av[i][j - 1] == 32)
				return (1);
			j++;
		}
		if (new_av[i][j - 1] == 32)
			return (1);
		i++;
	}
	return (0);
}

/*
Parametre : ac et av de main
But: sortir une chaine de caractere de tout les 
arguments colle et separer d un espace
ex : first_output(3, [["1 10"],["0"],["21"]]) ==> "1 10 0 21"
Retour: chaine de caractere
*/
char	*join_all(int ac, char **av)
{
	int		i;
	int		j;
	char	**new_av;
	char	*resu;

	if (ac == 1)
		return (NULL);
	j = 0;
	new_av = malloc(sizeof(char *) * (ac - 1));
	if (!new_av)
		return (NULL);
	i = 1;
	while (j < ac - 1)
	{
		new_av[j] = av[i];
		j++;
		i++;
	}
	if (is_new_av_invalid(ac - 1, new_av))
		return (write(2, "Error\n", 6), NULL);
	resu = ft_strjoin(ac - 1, new_av, " ");
	free(new_av);
	return (resu);
}

/*
test a gerer :
char *tab[] = {"----------0132", "92892", "2"}; => retourne 1
char *tab[] = {"0132-", "92892", "2"}; => retourne 1
char *tab[] = {"0132", "92892", "2"}; => retourne 1
char *tab[] = {"0-132", "92892", "2"}; => retourne 1
char *tab[] = {"-0132", "92892", "2a"}; => retourne 1
char *tab[] = {"132", "92892", "2"}; => retourne 0
*/
int	is_not_number(char **tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 45)
				j++;
			if (((tab[i][0] == '0') && (ft_strlen(tab[i]) != 1)) ||
			((tab[i][1] == '0') && (tab[i][0] == '-')))
				return (1);
			if ((tab[i][j] < 48) || (tab[i][j] > 57))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	is_doublon(char **tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(tab[i], tab[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
