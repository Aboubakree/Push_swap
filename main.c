/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:27:44 by akrid             #+#    #+#             */
/*   Updated: 2024/02/20 17:44:51 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_stack{
    int val;
    struct s_stack *next;
}   t_stack;

typedef struct s_p_swap{
    t_stack a;
    t_stack b;
}   t_p_swap;

t_stack    *node(int data)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (new = NULL)
        return (NULL);
    new->next = NULL;
    new->val = data;
    return (new);
}

void    add_back(t_stack **list, t_stack *node)
{
    t_stack *temp;

    if (list && *list == NULL)
        *list == node;
    else
    {
        temp = *list;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }
}

int    fill_stack(char *str, t_stack *a)
{
    
}

void    fill_stack_v2(char **splited, t_stack *a)
{
    int	j;
    int	fill;

    j = 0;
    while(splited != NULL && splited[j])
    {
        fill = fill_stack(splited[j], a);
        free(splited[j ++]);
    }
    if (splited != NULL)
        free(splited);
}

void    parse_args(int argc, char **argv, t_stack *a)
{
    char    **splited;
    int     i;


    i = 1;
    while(i < argc)
    {
        if (count_words(argv[i]) > 1)
        {
            splited = ft_split_v2(argv[i], " \t\n");
            fill_stack_v2(splited, a);
        }
        else
            fill_stack(argv[i], a);
        i ++;
    }
}

int main(int argc, char **argv)
{
    t_p_swap    stacks;

    parse_args(argc, argv, &stacks.a);
    return (0);
}