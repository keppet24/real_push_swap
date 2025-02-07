/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:25:35 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/02/07 18:31:16 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	size_of_resu(int size, char **strs)
{
	int		i;
	int		j;
	int		size_of_resu;

	size_of_resu = 0;
	i = 0;
	j = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			size_of_resu++;
			j++;
		}
		j = 0;
		i++;
	}
	return (size_of_resu);
}

char	*ft_strjoin_sub(int size, char *sep, char **strs, char *resu)
{
	int	i;
	int	j;
	int	comp;
	int	sep_count;

	i = 0;
	comp = 0;
	while (i < size)
	{
		j = 0;
		sep_count = 0;
		while (strs[i][j])
		{
			resu[comp] = strs[i][j];
			j++;
			comp++;
		}
		while (sep[sep_count] && i != size - 1)
			resu[comp++] = sep[sep_count++];
		i++;
	}
	resu[comp] = '\0';
	return (resu);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		taille_resu;
	char	*resu;
	int		taille;

	if (size == 0)
	{
		resu = malloc(1 * sizeof(char));
		resu[0] = '\0';
		return (resu);
	}
	taille = (ft_strlen(sep) * (size - 1));
	taille_resu = size_of_resu(size, strs);
	resu = malloc(sizeof(char) * (taille_resu + taille + 1));
	resu = ft_strjoin_sub(size, sep, strs, resu);
	return (resu);
}

// int main(int ac, char **av)
// {
// 	printf("%s", ft_strjoin(ac, av, " "));
// 	return 0;
// }