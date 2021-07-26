/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:25:56 by gpetit            #+#    #+#             */
/*   Updated: 2021/07/26 18:25:57 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*create_median_tab(int nb_elem, int *arr)
{
	int	*median;
	int	i;
	int	modulo;

	i = 0;
	modulo = nb_elem % 60;
	if (nb_elem / 60 == 0)
		median = malloc(sizeof(int));
	else
	{
		if (modulo != 0)
			modulo = 1;
		median = malloc(sizeof(int) * (nb_elem / 60 + modulo - 1));
	}
	if (!median)
		return (NULL);
	if (nb_elem / 60 < 2)
		*median = arr[nb_elem / 2];
	else
	{
		while (i != nb_elem / 60 + modulo - 1)
		{
			median[i] = arr[60 * (i + 1)];
			i++;
		}
	}
	return (median);
}

int	*search_median(t_stack *stack)
{
	t_list	*lst;
	int		size;
	int		*arr;
	int		*median;
	int		i;

	i = 0;
	lst = *(stack->a);
	size = ft_lstsize(lst);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (lst)
	{
		arr[i++] = *((int *)lst->content);
		lst = lst->next;
	}
	ft_simplesort(arr, i);
	median = create_median_tab(size, arr);
	if (!median)
	{
		free(arr);
		return (NULL);
	}
	free(arr);
	return (median);
}

void	first_under_median_goes_b(int oldmedian, int median, t_stack *stack)
{
	int		last_number;
	t_list	*lst;

	lst = *(stack->a);
	last_number = *((int *)(ft_lstlast(lst)->content));
	while (*((int *)lst->content) != last_number)
	{
		if (*((int *)lst->content) <= median
			&& *((int *)lst->content) > oldmedian)
			pb(stack);
		else
			ra(stack);
		lst = *(stack->a);
	}
	if (*((int *)lst->content) <= median
		&& *((int *)lst->content) > oldmedian)
		pb(stack);
}

void	under_median_goes_b(int oldmedian, int median, t_stack *stack)
{
	int		count;
	t_list	*lst;

	count = 0;
	lst = *(stack->a);
	while (*((int *)lst->content) != stack->a_min && count <= 60)
	{
		if (*((int *)lst->content) <= median
			&& *((int *)lst->content) > oldmedian)
		{
			count++;
			pb(stack);
		}
		else
			ra(stack);
		lst = *(stack->a);
	}
	if (*((int *)lst->content) <= median
		&& *((int *)lst->content) > oldmedian)
		pb(stack);
}

void	higher_median_goes_b(int median, t_stack *stack)
{
	t_list	*lst;

	lst = *(stack->a);
	while (*((int *)lst->content) != stack->a_min)
	{
		if (*((int *)lst->content) > median)
			pb(stack);
		else
			ra(stack);
		lst = *(stack->a);
	}
	if (*((int *)lst->content) > median)
		pb(stack);
}
