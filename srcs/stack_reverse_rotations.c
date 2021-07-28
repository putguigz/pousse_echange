/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:42:33 by gpetit            #+#    #+#             */
/*   Updated: 2021/06/25 15:42:34 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_penultimate(t_list *lst)
{
	if (!lst || !(lst->next))
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

int	rra(t_stack *stack)
{
	int		size;
	t_list	*penultimate;
	t_list	*last;
	t_list	*new_operation;
	void	*content;

	if (!(*(stack->a)))
		return (0);
	size = ft_lstsize(*(stack->a));
	if (size == 1)
		return (1);
	last = ft_lstlast(*(stack->a));
	penultimate = ft_lst_penultimate(*(stack->a));
	penultimate->next = NULL;
	ft_lstadd_front(stack->a, last);
	content = ft_strdup("rra");
	if (!content)
		return (0);
	new_operation = ft_lstnew(content);
	if (!new_operation)
	{
		free(content);
		return (0);
	}
	ft_lstadd_back(stack->output, new_operation);
	return (1);
}

int	rrb(t_stack *stack)
{
	int		size;
	t_list	*penultimate;
	t_list	*last;
	t_list	*new_operation;
	void	*content;

	if (!(*(stack->b)))
		return (0);
	size = ft_lstsize(*(stack->b));
	if (size == 1)
		return (1);
	last = ft_lstlast(*(stack->b));
	penultimate = ft_lst_penultimate(*(stack->b));
	penultimate->next = NULL;
	ft_lstadd_front(stack->b, last);
	content = ft_strdup("rrb");
	if (!content)
		return (0);
	new_operation = ft_lstnew(content);
	if (!new_operation)
	{
		free(content);
		return (0);
	}
	ft_lstadd_back(stack->output, new_operation);
	return (1);
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
