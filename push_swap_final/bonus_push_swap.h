/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_push_swap.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:29:22 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/14 20:29:26 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PUSH_SWAP_H
# define BONUS_PUSH_SWAP_H

# include <fcntl.h>
# include "push_swap.h"

void	b_rotate(t_nlist **list_a, t_nlist **list_b, char c);
void	b_rev_rotate(t_nlist **list_a, t_nlist **list_b, char c);
void	b_swap(t_nlist **list_a, t_nlist **list_b, char c);
void	b_push(t_nlist **list_a, t_nlist **list_b, char c);

#endif