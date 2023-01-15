/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 15:01:58 by itopchu       #+#    #+#                 */
/*   Updated: 2023/01/09 15:01:58 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_vector(char **v)
{
	int	i;

	if (!v)
		return ;
	i = 0;
	while (v[i])
	{
		free(v[i]);
		i++;
	}
	free(v);
}

int	len_vector(char **v)
{
	int	i;

	i = 0;
	while (v[i])
		i++;
	return (i);
}

int	sorted(t_circular *l, char c)
{
	t_circular	*tmp;
	int			i;

	if (c == 'b' && !l)
		return (1);
	if (c == 'b' && l)
		return (0);
	tmp = l;
	i = 0;
	while (tmp != l || i == 0)
	{
		if (tmp->value > tmp->next->value && tmp->next != l)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

void	free_list(t_circular *l)
{
	t_circular	*tmp;
	t_circular	*current;

	if (!l)
		return ;
	current = l;
	while (current->next != l)
	{
		tmp = current->next;
		current->next = NULL;
		current->prev = NULL;
		free(current);
		current = tmp;
	}
	current->next = NULL;
	current->prev = NULL;
	free(current);
}

void	free_table(t_table *t)
{
	if (!t)
		return ;
	free_list(t->a);
	free_list(t->b);
	free_vector(t->v);
	free(t);
}
