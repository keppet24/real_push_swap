/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:25:46 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/02/07 18:30:35 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_a
{
	int			value;
	int			value_normalized;
	struct s_a	*next;
}				t_a;

typedef struct s_b
{
	int			value;
	struct s_b	*next;
}				t_b;

char	*ft_strjoin(int size, char **strs, char *sep);
char	**ft_split(char const *s, char c);
int		countwords(char const *s, char c);
int		ft_strlen(char *str);
int		parsing(int ac, char **av, t_a **s1);
void	sort(t_a **s1, t_b **s2);
int		is_new_av_invalid(int ac, char **new_av);
char	*join_all(int ac, char **av);
int		is_not_number(char **tab, int size);
int		ft_strcmp(char *s1, char *s2);
int		is_doublon(char **tab, int size);
void	pa(t_a **s1, t_b **s2);
void	rra(t_a **s1);
void	pb(t_a **s1, t_b **s2);
void	ra(t_a **s1);
void	sort_stack_2(t_a **s1);
void	sort_stack_3(t_a **s1, t_b **s2);
void	sort_stack_4(t_a **s1, t_b **s2);
void	sort_stack_5(t_a **s1, t_b **s2);
void	small_sort(t_a **s1, t_b **s2);
void	normalize(t_a **s1);
int		find_bit_max(t_a **s1);
void	radix_sort(t_a **s1, t_b **s2);
void	sort(t_a **s1, t_b **s2);
int		size_of_stack_a(t_a **s1);
int		size_of_stack_b(t_b **s1);
void	free_tab(char **tab, int j);
void	push_min(t_a **s1, t_b **s2, int i);

#endif