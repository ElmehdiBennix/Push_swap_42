/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:59:16 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/22 04:38:15 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	char	**split_args(int ac, char **av)
{
	int		i;
	char	*str;
	char	**res;
	char	*tmp;

	i = 1;
	while (*(++av) && ac > i)
	{
		if (i == 1)
			str = ft_strdup(*av);
		else
		{
			tmp = ft_strjoin(str, " ");
			free(str);
			str = ft_strjoin(tmp, *av);
			free(tmp);
		}
		i++;
	}
	res = ft_split(str, ' ');
	if (!res)
		free(res);
	free(str);
	return (res);
}

t_list	*get_node(int ac, char **av)
{
	t_list	*p;
	t_list	*root;
	t_list	*arrow;
	char	**res;

	res = split_args(ac, av);
	if (res == NULL)
		exit(10);
	root = ft_lstnew(ft_atoi(*res));
	arrow = root;
	while (*(++res))
		ft_lstcreate_back(&root, ft_atoi(*res));
	while (arrow)
	{
		p = arrow->next;
		while (p)
		{
			if (arrow->content == p->content)
				failure(2);
			p = p->next;
		}
		arrow = arrow->next;
	}
	return (root);
}