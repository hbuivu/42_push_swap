/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:10:56 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/16 19:43:05 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct num_list
{
	int				num;
	struct num_list	*next;
	struct num_list	*prev;
}	t_nlist;

typedef struct data_list
{
	int		min;
	int		max;
	int		len;
	int		buckets;
	t_nlist	*top;
	t_nlist	*bottom;
	int		t_index;
	int		b_index;
	int		*pivots;
	int		*subpivots;
	int		*allpivots;
	int		i;
	int		j;
}	t_data;

typedef struct moves_list
{
	int	min_move;
	int	n;
	int	index_a;
	int	index_b;
	int	cur_min;
	int	cur_max;
}	t_mlist;

typedef struct moves_calc
{
	int	mid_a;
	int	mid_b;
	int	len_a;
	int	len_b;
	int	moves;
}	t_calc;

char		**ft_split(char const *s, char c, t_nlist **head);
long long	ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			check_sort(t_nlist **list);
int			len_list(t_nlist **list);
int			in_range(int n, t_data *d, char c);
int			ft_round(double i);

void		free_list(t_nlist **list);
void		free_split_list(char **split_lst);
void		exit_on_malloc_error(t_nlist **head, char **split_list);
void		free_all_three(t_nlist **list_a, t_nlist **list_b, t_data *d);
void		free_all_four(t_nlist **list_a, t_nlist **list_b, t_data *d,
				t_mlist *m);

t_nlist		**parse_entries(char **argc);
void		detect_invalid_entry(char *str, t_nlist **head);
int			detect_duplicate(char *str, t_nlist **head);

void		push(t_nlist **list_a, t_nlist **list_b, char c);
void		rev_rotate(t_nlist **list_a, t_nlist **list_b, char c);
void		rotate(t_nlist **list_a, t_nlist **list_b, char c);
void		swap(t_nlist **list_a, t_nlist **list_b, char c);

void		simple_sort(t_nlist **list_a, t_nlist **list_b);
void		sort_three(t_nlist **list_a, t_nlist **list_b);

void		presort(t_nlist **list_a, t_nlist **list_b, t_data *d);
t_data		*init_dlist(t_nlist **list_a, t_nlist **list_b);
int			find_index(int num, t_nlist **list_a);
int			find_new_index(int num, t_nlist **list_a, t_mlist *m);
void		best_move(t_nlist **list_a, t_nlist **list_b, t_data *d,
				t_mlist *m);
void		push_move(t_nlist **list_a, t_nlist **list_b, t_mlist *m);
void		complex_sort(t_nlist **list_a, t_nlist **list_b, t_data *d);

#endif
