/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:27:44 by akrid             #+#    #+#             */
/*   Updated: 2024/03/11 16:52:29 by akrid            ###   ########.fr       */
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

void	sort_three(t_stack **a, t_p_swap *stacks)
{
	long	t[stacks->size_a];
	int		min;
	int		max;

	fill_tab(t, *a);
	min = get_min(t, stacks->size_a);
	max = get_max(t, stacks->size_a);
	// int	i = 0;
	// while(i < stacks->size_a){
	// 	printf("a[%d] = %ld | ",i, t[i]);
	// 	i ++;
	// }
	// printf("\nmin : %d --> %ld\n,max : %d --> %ld\n", min, t[min], max, t[max]);
	// printf("min : %d --> %ld\n", min, t[min]);
	// printf("max : %d --> %ld\n", max, t[max]);
	if (max == 0){
		ra(a);
		if (min == 2)
			sa(a);
	}
	else if(max == 1){
		rra(a);
		if (min == 0)
			sa(a);
	}
	else if(max == 2 && min == 1){
		sa(a);
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
		sa(a);
		pb(a, b, stacks);
	}
	else if (min == 2){
		rra(a);
		rra(a);
		pb(a, b, stacks);
	}
	else if (min == 3){
		rra(a);
		pb(a, b, stacks);
	}
	sort_three(a, stacks);
	pa(a, b, stacks);
}

void	sort_five_extand(t_stack **a, t_stack **b, t_p_swap *stacks, int min)
{
	if (min == 3){
		rra(a);
		rra(a);
		pb(a, b, stacks);
	}
	else if (min == 4){
		rra(a);
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
		sa(a);
		pb(a, b, stacks);
	}
	else if (min == 2){
		ra(a);
		ra(a);
		pb(a, b, stacks);
	}
	else
		sort_five_extand(a, b, stacks, min);
	sort_four(a, b, stacks);
	pa(a, b, stacks);
}

void	sort_two(t_stack **a)
{
	if ((*a)->val > (*a)->next->val)
		sa(a);
}

int	check_all_neg_pos(long distance[], int size)
{
	int i;
	int	dist;

	i = 0;
	dist = 0;
	while (i < size)
	{
		if (distance[i] < distance[dist])
			dist = i;
		i ++;
	}
	return (dist);
}



int	get_minimum_distance(long distance[], int size)
{
	int i;
	int	dist;

	i = 0;
	while (i < size && distance[i] > 0)
		i ++;
	if (i == size) 
		return (check_all_neg_pos(distance, size));
	i = 0;
	while (i < size && distance[i] < 0)
		i ++;
	if (i == size) 
		return (check_all_neg_pos(distance, size));
	dist = i;
	while (i < size)
	{
		if (distance[i] > 0 && distance[i] < distance[dist])
			dist = i;
		i ++;
	}
	return (dist);
}

int	check_all_neg_pos_b_a(long distance[], int size)
{
	int i;
	int	dist;

	i = 0;
	dist = 0;
	while (i < size)
	{
		if (distance[i] > distance[dist])
			dist = i;
		i ++;
	}
	return (dist);
}



int	get_minimum_distance_b_a(long distance[], int size)
{
	int i;
	int	dist;

	i = 0;
	while (i < size && distance[i] < 0)
		i ++;
	if (i == size) 
		return (check_all_neg_pos_b_a(distance, size));
	i = 0;
	while (i < size && distance[i] > 0)
		i ++;
	if (i == size) 
		return (check_all_neg_pos_b_a(distance, size));
	dist = i;
	while (i < size)
	{
		if (distance[i] < 0 && distance[i] > distance[dist])
			dist = i;
		i ++;
	}
	return (dist);
}

void	get_index_to_follow_in_b(t_p_swap *stacks, t_operation **operation)
{
	long	b[stacks->size_b];
	long	distance[stacks->size_b];
	int		i;
	int		dist;

	i = 0;
	fill_tab(b, stacks->b);
	while(i < stacks->size_b)
	{
		distance[i] = ((*operation)->element_to_push) - b[i];
		i ++;
	}
	dist = get_minimum_distance(distance, stacks->size_b);
	(*operation)->element_to_follow = b[dist];
	(*operation)->index_to_follow = dist;
}

void	get_index_to_follow_in_a(t_p_swap *stacks, t_operation **operation)
{
	long	a[stacks->size_a];
	long	distance[stacks->size_a];
	int		i;
	int		dist;

	i = 0;
	fill_tab(a, stacks->a);
	while(i < stacks->size_a)
	{
		distance[i] = ((*operation)->element_to_push) - a[i];
		i ++;
	}
	dist = get_minimum_distance_b_a(distance, stacks->size_a);
	(*operation)->element_to_follow = a[dist];
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

void	get_operation_moves_b_to_a(t_p_swap *stacks, t_operation **list_operation)
{
	t_operation *temp;
	int	a_medium;
	int	b_medium;

	a_medium = stacks->size_a / 2;
	b_medium = stacks->size_b / 2;
	temp = *list_operation;
	while(temp){
		temp->total_moves = 0;
		if (temp->index_to_push <= b_medium)
			temp->total_moves += temp->index_to_push;
		else
			temp->total_moves += stacks->size_b - temp->index_to_push;
		if (temp->index_to_follow <= a_medium)
			temp->total_moves += temp->index_to_follow;
		else
			temp->total_moves += stacks->size_a - temp->index_to_follow;
		temp = temp->next;
	}
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	ft_abs(int a)
{
	if (a >= 0)
		return (a);
	return (-a);
}

void	get_rest_of_moves(t_p_swap *stacks, t_operation *temp)
{
	if (temp->index_to_push <= (stacks->size_a / 2))
		temp->total_moves += temp->index_to_push;
	else
		temp->total_moves += stacks->size_a - temp->index_to_push;
	if (temp->index_to_follow <=  (stacks->size_b / 2))
		temp->total_moves += temp->index_to_follow;
	else
		temp->total_moves += stacks->size_b - temp->index_to_follow;
	
}

void	get_operation_moves_a_to_b(t_p_swap *stacks, t_operation **list_operation)
{
	t_operation *temp;

	temp = *list_operation;
	while(temp)
	{
		temp->total_moves = 0;
		if (temp->index_to_push <= (stacks->size_a / 2) 
		&& temp->index_to_follow <=  (stacks->size_b / 2))
			temp->total_moves = ft_min(temp->index_to_push, temp->index_to_follow) 
			+ ft_abs(temp->index_to_push - temp->index_to_follow);
		else if (temp->index_to_push >= (stacks->size_a / 2) 
		&& temp->index_to_follow >=  (stacks->size_b / 2))
			temp->total_moves = ft_min((stacks->size_a - temp->index_to_push),
			(stacks->size_b - temp->index_to_follow)) 
			+ ft_abs((stacks->size_a - temp->index_to_push) 
			- (stacks->size_b - temp->index_to_follow));
		else
			get_rest_of_moves(stacks, temp);
		temp = temp->next;
	}
}

void	rotate_b_a_to_b(t_stack **b, t_p_swap *stacks, t_operation *element)
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

void	rotate_a_b_to_a(t_stack **a, t_p_swap *stacks, t_operation *element)
{
	if (element->index_to_follow > (stacks->size_a / 2))
	{
		element->index_to_follow = stacks->size_a - element->index_to_follow;
		while(element->index_to_follow)
		{
			rra(a);
			element->index_to_follow --;
		}
	}
	else 
	{
		while(element->index_to_follow)
		{
			ra(a);
			element->index_to_follow --;
		}
	}
}

void	rotate_a_a_to_b(t_stack **a, t_p_swap *stacks, t_operation *element)
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
// -------------------------------------------

void	rotate_ab_up_a_to_b(t_stack **a, t_stack **b, t_p_swap *stacks, t_operation *element)
{
	element->index_to_follow = stacks->size_b - element->index_to_follow;
	element->index_to_push = stacks->size_a - element->index_to_push;
	while (element->index_to_push && element->index_to_follow)
	{
		rrr(a, b);
		element->index_to_push --;
		element->index_to_follow --;
	}
	while(element->index_to_push)
	{
		rra(a);
		element->index_to_push --;
	}
	while(element->index_to_follow)
	{
		rrb(b);
		element->index_to_follow --;
	}
}

void	rotate_ab_down_a_to_b(t_stack **a, t_stack **b, t_operation *element)
{
	while(element->index_to_push && element->index_to_follow)
	{
		rr(a, b);
		element->index_to_push --;
		element->index_to_follow --;
	}
	while(element->index_to_follow)
	{
		rb(b);
		element->index_to_follow --;
	}
	while(element->index_to_push)
	{
		ra(a);
		element->index_to_push --;
	}
}

void	rotate_ab_a_to_b(t_stack **a, t_stack **b, t_p_swap *stacks, t_operation *element)
{
	if (element->index_to_push > (stacks->size_a / 2) && element->index_to_follow > (stacks->size_b / 2))
		rotate_ab_up_a_to_b(a, b, stacks, element);
	else if (element->index_to_push <= (stacks->size_a / 2) && element->index_to_follow <= (stacks->size_b / 2))
		rotate_ab_down_a_to_b(a, b, element);
	else 
	{
		rotate_a_a_to_b(a, stacks, element);
		rotate_b_a_to_b(b, stacks, element);
	}
}

void	push_b(t_stack **a, t_stack **b, t_p_swap *stacks, t_operation *list_operation)
{
	t_operation	*temp;
	t_operation	*minimum_moves;

	temp = list_operation;
	minimum_moves = list_operation;
	while(temp)
	{
		// printf("a[%d]:%ld --> b[%d]:%ld in %d moves\n", temp->index_to_push, temp->element_to_push,
		// temp->index_to_follow, temp->element_to_follow, temp->total_moves);
		if (temp->total_moves < minimum_moves->total_moves)
			minimum_moves = temp;
		temp = temp->next;
	}
	rotate_ab_a_to_b(a, b, stacks, minimum_moves);
	pb(a, b, stacks);
}

void	push_a(t_stack **a, t_stack **b, t_p_swap *stacks, t_operation *list_operation)
{
	rotate_a_b_to_a(a, stacks, list_operation);
	pa(a, b, stacks);
}

void	ascinding_sort(t_stack **a, t_p_swap *stacks)
{
	long	t[stacks->size_a];
	int		min;

	fill_tab(t, *a);
	min = get_min(t, stacks->size_a);
	if (min > (stacks->size_a / 2))
	{
		min = stacks->size_a - min;
		while(min){
			rra(a);
			min --;
		}
	}
	else 
	{
		while(min){
			ra(a);
			min --;
		}
	}
}

void	sort_to_b(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	t_operation	*operation;
	t_operation	*list_operation;
	int			i;
	t_stack		*temp;

	while (stacks->size_a > 3)
	{
		i = 0;
		temp = *a;
		list_operation = NULL;
		while (temp)
		{
			operation = new_operation();
			operation->index_to_push = i;
			operation->element_to_push = temp->val;
			get_index_to_follow_in_b(stacks, &operation);
			operation_add_back(&list_operation, operation);
			i ++;
			temp = temp->next;
		}
		get_operation_moves_a_to_b(stacks, &list_operation);
		push_b(a, b, stacks, list_operation);
		clean_operation(list_operation);
	}
}

void	sort_to_a(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	t_operation	*operation;

	while (stacks->size_b > 0)
	{
		operation = new_operation();
		operation->index_to_push = 0;
		operation->element_to_push = (*b)->val;
		get_index_to_follow_in_a(stacks, &operation);
		push_a(a, b, stacks, operation);
		clean_operation(operation);
	}
}


void	final_sort(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	sort_to_b(a, b, stacks);
	sort_three(a, stacks);
	sort_to_a(a, b, stacks);
	ascinding_sort(a, stacks);
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
		sort_two(a);
	else if (stacks->size_a == 3)
		sort_three(a, stacks);
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
	// t_stack *x = NULL;
	// x = stacks.a;
	// while (x)
	// {
	// 	printf(" %ld \n", x->val);
	// 	x = x->next;
	// }
	// clean_stack(stacks.a);
	// // // // // // // ---------------------------------
	// printf("**********************************\n");
	// x = stacks.b;
	// while (x)
	// {
	// 	printf(" %ld \n", x->val);
	// 	x = x->next;
	// }
	// clean_stack(stacks.b);
    return (0);
}
