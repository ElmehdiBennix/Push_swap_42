/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:27:14 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/17 03:26:14 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void swap(t_list **stack, char AorB) 
{
    t_list *arrow;
    int i;

    arrow = *stack;
    if (!arrow || !arrow -> next)
        return;
    else
    {
        i = arrow -> content;
        arrow -> content = arrow -> next -> content;
        arrow -> next -> content = i;
        i = arrow -> position;
        arrow -> position = arrow -> next -> position;   // need to implement a real swap for the node and even make it recorsive for ss
        arrow -> next -> position = i;
        if(AorB == 'a')
            write(1,"sa\n",4);
        else if (AorB == 'b')
            write(1,"sb\n",4);
        else
            return;
    }
}

void ss(t_list **stack_a, t_list **stack_b)
{
    swap(stack_a,'s');
    swap(stack_b,'s');
    write(1,"ss\n",4);
}

// int main ()
// {
//     t_list *root1 = ft_lstnew(90000);
//     ft_lstcreate_back(&root1,768);
//     ft_lstcreate_back(&root1,1);
//     ft_lstcreate_back(&root1,50);
//     t_list *root2 = ft_lstnew(50000);
//     ft_lstcreate_back(&root2,5479);
//     ft_lstcreate_back(&root2,1575);
//     ft_lstcreate_back(&root2,54356);
//     ss(&root1,&root2);
//     while(root1)
//     {
//         printf("stack a :");
//         printf("%d\n",root1->content);
//         root1 = root1 -> next;
//     }
//     printf("----------------------------------\n");
//     while(root2)
//     {
//         printf("stack b :");
//         printf("%d\n",root2->content);
//         root2 = root2 -> next;
//     }
//     printf("----------------------------------\n");

// }