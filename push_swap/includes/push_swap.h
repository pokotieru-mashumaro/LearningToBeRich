/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:12:25 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/04/21 21:14:39 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dst
{
	long			value;
	struct s_dst	*next;
	struct s_dst	*prev;
}					t_dst;

void				init_dst(t_dst **a, t_dst **b, int ac, char **av);

int					is_av_error(int ac, char *av[]);
int					output_error(void);
void				debug_boxes(t_dst **a, t_dst **b);
int					is_sorted_ascending(t_dst **a);
int					is_sorted_descending(t_dst **b);

void				push_swap(t_dst **a, t_dst **b);

long				ft_atol(char *str);
int					ft_strlen(char *s);
int					ft_strcmp(char *s1, char *s2);

t_dst				*ft_lstnew(long value);
t_dst				*ft_lstlast(t_dst *dst);
int					ft_lstsize(t_dst *dst);
void				ft_lstadd_back(t_dst **dst, t_dst *new);


long	get_pivot_num(char **av);
void separated_by_pivot(char **av, t_dst **a, t_dst **b, long pivot_num);


void				sa(t_dst **a);
void				sb(t_dst **b);
void				ss(t_dst **a, t_dst **b);

void				pa(t_dst **a, t_dst **b);
void				pb(t_dst **a, t_dst **b);

void				ra(t_dst **a);
void				rb(t_dst **b);
void				rr(t_dst **a, t_dst **b);

void				rra(t_dst **a);
void				rrb(t_dst **b);
void				rrr(t_dst **a, t_dst **b);

#endif
