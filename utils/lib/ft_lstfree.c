/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:22:22 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/26 02:19:26 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_lstfree(void *stack)
{
	t_list	*arrow;

	arrow = stack;
	while (arrow)
	{
		free(arrow);
		arrow = arrow -> next;
	}
}
