/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:27:44 by akrid             #+#    #+#             */
/*   Updated: 2024/03/05 16:36:59 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack    *node(long data)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (new == NULL)
        return (NULL);
    new->next = NULL;
    new->val = data;
    return (new);
}

void    add_back(t_stack **list, t_stack *node)
{
    t_stack *temp;

    if (list && *list == NULL)
        *list = node;
    else
    {
        temp = *list;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }
}

void	add_front(t_stack **list, t_stack *node)
{
	node->next = NULL;
	node->next = *list;
	*list = node;
}

void    parse_args(int argc, char **argv, t_stack **a)
{
	char	**temp;

    if (argc == 2)
	{
		temp = ft_split_v2(argv[1], " \t\n\r\v\f");
        if(valid_digits(length(temp), temp, 0)) {
			fill_stack(length(temp) ,temp, a, 0);
			clean(temp);
		}
		else {
			clean(temp);
			error();
		}
	}
	else {
        if(valid_digits(argc, argv, 1))
			fill_stack(argc, argv, a, 1);
		else
			error();
	}
	check_stack(*a);
}

void	fill_tab(long t[],t_stack *x)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = x;
	while(temp){
		t[i] = temp->val;
		// printf("t[%d] = %ld\n", i, t[i]);
		temp = temp->next;
		i ++;
	}
}

int	get_min(long t[], int size)
{
	int i;
	int min;

	i = 1;
	min = 0;
	while (i < size){
		if (t[min] > t[i])
			min = i;
		i ++;
	}
	return (min);
}

int	get_max(long t[], int size)
{
	int i;
	int max;

	i = 1;
	max = 0;
	while (i < size){
		if (t[max] < t[i])
			max = i;
		i ++;
	}
	return (max);
}

void	sort_three(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	long	t[stacks->size_a];
	int		min;
	int		max;

	(void)b;
	fill_tab(t, *a);
	min = get_min(t, stacks->size_a);
	max = get_max(t, stacks->size_a);
	// printf("min : %d --> %ld\n", min, t[min]);
	// printf("max : %d --> %ld\n", max, t[max]);
	if (max == 0){
		ra(&stacks->a);
		if (min == 2)
			sa(&stacks->a);
	}
	else if(max == 1){
		rra(&stacks->a);
		if (min == 0)
			sa(&stacks->a);
	}
	else if(max == 2){
		sa(&stacks->a);
	}
}

void	sort_four(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	long	t[stacks->size_a];
	int		min;
	
	fill_tab(t, *a);
	min = get_min(t, stacks->size_a);
	if (min == 0)
		pb(a, b, stacks);
	else if (min == 1){
		sa(&stacks->a);
		pb(a, b, stacks);
	}
	else if (min == 2){
		rra(&stacks->a);
		rra(&stacks->a);
		pb(a, b, stacks);
	}
	else if (min == 3){
		rra(&stacks->a);
		pb(a, b, stacks);
	}
	sort_three(a, b, stacks);
	pa(a, b, stacks);
}

void	sort_five_extand(t_stack **a, t_stack **b, t_p_swap *stacks, int min)
{
	if (min == 3){
		rra(&stacks->a);
		rra(&stacks->a);
		pb(a, b, stacks);
	}
	else if (min == 4){
		rra(&stacks->a);
		pb(a, b, stacks);
	}	
}

void	sort_five(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	long	t[stacks->size_a];
	int		min;
	
	fill_tab(t, *a);
	min = get_min(t, stacks->size_a);
	if (min == 0)
		pb(a, b, stacks);
	else if (min == 1){
		sa(&stacks->a);
		pb(a, b, stacks);
	}
	else if (min == 2){
		ra(&stacks->a);
		ra(&stacks->a);
		pb(a, b, stacks);
	}
	else
		sort_five_extand(a, b, stacks, min);
	sort_four(a, b, stacks);
	pa(a, b, stacks);
}

void	sort_two(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	(void)b;
	if ((*a)->val > (*a)->next->val)
		sa(&stacks->a);
}

int	get_minimum_distance(long distance[], int size)
{
	int i;
	int	dist;

	i = 0;
	while (i < size && distance[i] < 0)
		i ++;
	if (i == size) {
		i = 0;
		dist = 0;
		while (i < size){
			if (distance[i] < distance[dist])
				dist = i;
			i ++;
		}
		return (dist);
	}
	dist = i;
	while (i < size){
		if (distance[i] > 0 && distance[i] < distance[dist])
			dist = i;
		i ++;
	}
	return (dist);
}

void	get_index_to_follow(t_p_swap *stacks, t_operation **operation)
{
	long	b[stacks->size_b];
	long	distance[stacks->size_b];
	int		i;
	int		dist;

	i = 0;
	fill_tab(b, stacks->b);
	while(i < stacks->size_b){
		distance[i] = ((*operation)->element_to_push) - b[i];
		i ++;
	}
	dist = get_minimum_distance(distance, stacks->size_b);
	(*operation)->element_to_follow = b[dist];
	(*operation)->index_to_follow = dist;
}

t_operation	*new_operation()
{
	t_operation	*new;

	new = malloc(sizeof(t_operation));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	return (new);
}

void	operation_add_back(t_operation	**list, t_operation *operation)
{
	t_operation *temp;

	if (*list == NULL)
		*list = operation;
	else {
		temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = operation;
	}
}

void	clean_operation(t_operation *operation)
{
	t_operation *temp;

	temp = operation;
	while (temp){
		operation = operation->next;
		free(temp);
		temp = operation;
	}
}

void	get_operation_moves(t_p_swap *stacks, t_operation **list_operation)
{
	t_operation *temp;
	int	a_medium;
	int	b_medium;

	a_medium = stacks->size_a / 2;
	b_medium = stacks->size_b / 2;
	temp = *list_operation;
	while(temp){
		temp->total_moves = 0;
		if (temp->index_to_push <= a_medium)
			temp->total_moves += temp->index_to_push;
		else
			temp->total_moves += stacks->size_a - temp->index_to_push;
		if (temp->index_to_follow <= b_medium)
			temp->total_moves += temp->index_to_follow;
		else
			temp->total_moves += stacks->size_b - temp->index_to_follow;
		temp = temp->next;
	}
}

void	rotate_a(t_stack **a, t_p_swap *stacks, t_operation *element)
{
	if (element->index_to_push > (stacks->size_a / 2)){
		element->index_to_push = stacks->size_a - element->index_to_push;
		while(element->index_to_push){
			rra(a);
			element->index_to_push --;
		}
	}
	else {
		while(element->index_to_push){
			ra(a);
			element->index_to_push --;
		}
	}
}

void	rotate_b(t_stack **b, t_p_swap *stacks, t_operation *element)
{
	if (element->index_to_follow > (stacks->size_b / 2)){
		element->index_to_follow = stacks->size_b - element->index_to_follow;
		while(element->index_to_follow){
			rrb(b);
			element->index_to_follow --;
		}
	}
	else {
		while(element->index_to_follow){
			rb(b);
			element->index_to_follow --;
		}
	}
}

void	rotate_ab(t_stack **a, t_stack **b, t_p_swap *stacks, t_operation *element)
{
	if (element->index_to_push > (stacks->size_a / 2) && element->index_to_follow > (stacks->size_b / 2)){
		element->index_to_push = stacks->size_a - element->index_to_push;
		element->index_to_follow = stacks->size_b - element->index_to_follow;
		while(element->index_to_push && element->index_to_follow){
			rrr(a, b);
			element->index_to_push --;
			element->index_to_follow --;
		}
	}
	else if (element->index_to_push < (stacks->size_a / 2) && element->index_to_follow < (stacks->size_b / 2)) {
		while(element->index_to_push && element->index_to_follow){
			rr(a, b);
			element->index_to_push --;
			element->index_to_follow --;
		}
	}
	else{
		rotate_a(a, stacks, element);
		rotate_b(b, stacks, element);
	}
}

void	push_b(t_stack **a, t_stack **b, t_p_swap *stacks, t_operation *list_operation)
{
	t_operation	*temp;
	t_operation	*minimum_moves;

	temp = list_operation;
	minimum_moves = list_operation;
	t_stack *x = NULL;
	x = *b;
	printf("\n");
	while (x)
	{
		printf(" %ld ", x->val);
		x = x->next;
	}
	printf("\n");
	while(temp){
		if (temp->total_moves < minimum_moves->total_moves)
			minimum_moves = temp;
		printf("a[%d] : %ld --> b[%d] : %ld  in %d moves\n", temp->index_to_push, temp->element_to_push, temp->index_to_follow, temp->element_to_follow, temp->total_moves);
		temp = temp->next;
	}
	// rotate_ab(a, b, stacks, minimum_moves);
	rotate_a(a, stacks, minimum_moves);
	rotate_b(b, stacks, minimum_moves);
	pb(a, b, stacks);
}

void	ascinding_sort(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	long	t[stacks->size_b];
	int		max;

	fill_tab(t, *b);
	max = get_max(t, stacks->size_b);
	if (max > (stacks->size_b / 2)){
		max = stacks->size_b - max;
		while(max){
			rrb(b);
			max --;
		}
	}
	else {
		while(max){
			rb(b);
			max --;
		}
	}
	while(stacks->size_b)
		pa(a, b, stacks);
}

void	final_sort(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	t_operation	*operation;
	t_operation	*list_operation;
	int			i;
	t_stack		*temp;

	while (stacks->size_a > 0){

		i = 0;
		temp = *a;
		list_operation = NULL;
		while (temp){
			operation = new_operation();
			operation->index_to_push = i;
			operation->element_to_push = temp->val;
			get_index_to_follow(stacks, &operation);
			operation_add_back(&list_operation, operation);
			i ++;
			temp = temp->next;
		}
		get_operation_moves(stacks, &list_operation);
		push_b(a, b, stacks, list_operation);
		clean_operation(list_operation);
	}
	ascinding_sort(a, b, stacks);
}

void	stack_sort(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	stacks->b = NULL;
	stacks->size_a = ft_lstsize(stacks->a);
	if (stacks->size_a == 1){
		clean_stack(*a);
		exit(EXIT_SUCCESS);
	}
	stacks->size_b = 0;
	if (stacks->size_a == 2)
		sort_two(a, b, stacks);
	else if (stacks->size_a == 3)
		sort_three(a, b, stacks);
	else if (stacks->size_a == 4)
		sort_four(a, b, stacks);
	else if (stacks->size_a == 5)
		sort_five(a, b, stacks);
	else {
		pb(a, b, stacks);
		pb(a, b, stacks);
		final_sort(a, b, stacks);
	}
}

int main(int argc, char **argv)
{
    t_p_swap    stacks;
	int		sort;

    parse_args(argc, argv, &stacks.a);
	sort = check_sorting(stacks.a);
	if (sort == 0)
		stack_sort(&stacks.a, &stacks.b, &stacks);
	// --------------------------------
	t_stack *x = NULL;
	x = stacks.a;
	while (x)
	{
		printf(" %ld ", x->val);
		x = x->next;
	}
	clean_stack(stacks.a);
	// // // ---------------------------------
    return (0);
}
