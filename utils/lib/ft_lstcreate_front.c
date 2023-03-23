/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 05:09:25 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/21 21:36:45 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_lstcreate_front(t_list **lst, int content)
{
	t_list	*front;

	front = ft_lstnew(content);
	ft_lstadd_front(lst, front);
}
