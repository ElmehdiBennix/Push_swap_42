/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:13:37 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/14 19:18:50 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void init_position(t_list *stack)
{
    t_list *arrow = stack;
	t_list	*p;
    int i = 0;
    while (arrow)
    {
        arrow -> index = i++;
        arrow -> position = 0;
        arrow = arrow -> next;
    }    

	arrow = stack;
	while (arrow)
	{
        // arrow -> position = 0;
		p = stack;
		while (p)
		{
			if (arrow -> content < p -> content)
				p -> position += 1;
			p = p -> next;
		}
		arrow = arrow -> next;
	}
    // arrow = stack_a;
    // while (arrow)
    // {
    //     printf("%d :",arrow ->content);
    //     printf(" position -> %d\n",arrow ->position);
    //     arrow = arrow ->next;
    // } 
}

void sort_under_five(int size, t_list **stack_a, t_list **stack_b)
{
    // int x ;
    t_list *arrow = *stack_a;
    (void) *stack_b;
    
    if (size == 1)
        return;
    else if (size == 2 && arrow -> content > arrow -> next -> content)
        swap(stack_a, 'a');
    else if (size == 3)
    {
        if(arrow -> position == 1 && arrow -> next -> position == 0)
            swap(stack_a, 'a');
        else if (arrow -> position == 2 && arrow -> next -> position == 1)
        {
            swap(stack_a,'a');
            reverse_rotate(stack_a,'a');
        }
        else if (arrow -> position == 2 && arrow -> next -> position == 0)
            rotate(stack_a,'a');
        else if(arrow -> position == 0 && arrow -> next -> position == 2)
        {
            swap(stack_a,'a');
            rotate(stack_a,'a');
        }
        else if(arrow -> position == 1 && arrow -> next -> position == 2)
            reverse_rotate(stack_a,'a'); // print the a'' in function recusive too
    }
    else if (size == 4)
    {
        while(arrow -> position != 0)
            arrow = arrow -> next;
        if (arrow -> index == 0 || arrow -> index == 1)
        {
            if(arrow -> index == 1)
                rotate(stack_a,'a');
            push(stack_a,stack_b,'b');
            init_position(*stack_a); // make it dont last just a copy of positon
            sort_under_five(size - 1,stack_a,stack_b);
            push(stack_a,stack_b,'a');
            init_position(*stack_a);
        }
        else
        {
            while ((*stack_a) -> position != 0)
                reverse_rotate(stack_a,'a');
            push(stack_a,stack_b,'b');
            init_position(*stack_a); // make it dont last just a copy of positon
            sort_under_five(size - 1,stack_a,stack_b);
            push(stack_a,stack_b,'a');
            init_position(*stack_a);
        }
    }
    else if (size == 5)
    {
        t_list *tmp = *stack_a;
        while(arrow -> position != 0)
        {
            while(tmp -> position != 1)
                tmp = tmp -> next;
            arrow = arrow -> next;
        }
        if (arrow -> index == 0 || arrow -> index == 1)
        {
            while ((*stack_a) -> position != 0)
                rotate(stack_a,'a');
            push(stack_a,stack_b,'b');
            while ((*stack_a) -> position != 1)
                rotate(stack_a,'a');
            push(stack_a,stack_b,'b');
            init_position(*stack_a); // make it dont last just a copy of positon
            sort_under_five(size - 2,stack_a,stack_b);
            push(stack_a,stack_b,'a');
            push(stack_a,stack_b,'a');
            init_position(*stack_a);
        }
        else
        {
            while ((*stack_a) -> position != 0)
                reverse_rotate(stack_a,'a');
            push(stack_a,stack_b,'b');
            while ((*stack_a) -> position != 1)
                reverse_rotate(stack_a,'a');
            push(stack_a,stack_b,'b');    
            init_position(*stack_a); // make it dont last just a copy of positon
            sort_under_five(size - 2,stack_a,stack_b);
            push(stack_a,stack_b,'a');
            push(stack_a,stack_b,'a');
            init_position(*stack_a);
        }
    }
}

void sort(t_list **stack_a, t_list **stack_b , int chunk, int last_pos)
{
    int mid;
    int i;

    mid = chunk / 2;
    i  = chunk;
    // int x = 0;

    while (*stack_a && i > 0)
    {
        if((*stack_a) -> position <= last_pos)
        {
            if((*stack_a) -> position <= last_pos - mid)
                push(stack_a,stack_b,'b');
            else 
            {
                push(stack_a,stack_b,'b');
                rotate(stack_b,'b');
            }
            i--;
        }
        else
        {
            rotate(stack_a,'a');
        }

    }
    // while (*stack_a && i > 0)
    // {
    //     if ((*stack_a)->position <= last_el)
    //     {
             
    //     }
    //     else
    //         ra(*stack_a);
    // }

}

void sort_under_2hundred(int size, t_list **stack_a, t_list **stack_b, int divide)
{
    int chunk = size / divide; // ./. 5 or ./. 10
    int reset = chunk;

    while (ft_lstsize(*stack_a))
    {
        sort(stack_a,stack_b,chunk ,reset);
        reset += chunk;
    }
}

int push_swap(int ac, char **av)
{
    t_list *stack_a;
    t_list *stack_b;
    int size;

    check_valid (av); // if it passed means arguments are valid
    stack_a = split_args(ac, av); //joinning for the split
    stack_b = NULL;

    size = ft_lstsize(stack_a);
    init_position(stack_a);

    if (size <= 5)
        sort_under_five(size,&stack_a,&stack_b);
    else if (size <= 200)
        sort_under_2hundred(size,&stack_a,&stack_b,5);
    // else // split into 10

    
    printf("\n");
    while(stack_a)
    {
        printf("|| stack : a = %d      with the position %d\n",stack_a -> content,stack_a -> position);
        stack_a = stack_a -> next;
    }

    printf("\n");
    while(stack_b)
    {
        printf("|| stack : b = %d      with the position %d\n",stack_b -> content,stack_b -> position);
        stack_b = stack_b -> next;
    }

    return (0);
}

int main (int ac, char **av)
{
    int err;
    
    if (ac == 1)
        exit(1);
    err = push_swap(ac,av);
    return (err);
}
/*
./push_swap -4 -45 45 57 0
ra
pb
ra
ra
ra
pb
rra
pa
pa
could be optimized
*/