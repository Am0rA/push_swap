/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   table_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:59:53 by itopchu       #+#    #+#                 */
/*   Updated: 2023/01/09 14:59:53 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_circular	*new_node(int value)
{
	t_circular	*new;

	new = (t_circular *)malloc(sizeof(t_circular));
	if (!new)
		return (NULL);
	new->next = new;
	new->prev = new;
	new->value = value;
	new->dist = 0;
	new->dist_a = 0;
	new->dist_b = 0;
	return (new);
}

t_circular	*extract(t_circular **l)
{
	t_circular	*tmp;

	if (!*l)
		return (NULL);
	if ((*l)->next == (*l))
	{
		(*l)->prev = NULL;
		(*l)->next = NULL;
		return (*l);
	}
	tmp = (*l);
	((*l)->prev)->next = (*l)->next;
	((*l)->next)->prev = (*l)->prev;
	*l = (*l)->next;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

t_circular	*insert(t_circular **l, t_circular **new)
{
	int			len;
	t_circular	*rtn;

	len = list_len(*new);
	rtn = extract(new);
	if (!(*l))
	{
		rtn->prev = rtn;
		rtn->next = rtn;
		*l = rtn;
	}
	else
	{
		rtn->next = *l;
		rtn->prev = (*l)->prev;
		(*l)->prev->next = rtn;
		(*l)->prev = rtn;
		*l = rtn;
	}
	if (len == 1)
		*new = NULL;
	return (*l);
}

t_table	*table_init(int ac, char **av)
{
	t_table		*table;
	t_circular	*add;
	int			i;

	table = malloc(sizeof(t_table));
	if (!table)
		write_error(NULL);
	table->a = NULL;
	table->b = NULL;
	table->v = fill_vector(av, ac);
	if (!(table->v))
		write_error(&table);
	check(table);
	i = len_vector(table->v) - 1;
	while (i >= 0)
	{
		add = new_node(ft_atoi(table->v[i]));
		if (!add)
			write_error(&table);
		table->a = insert(&(table->a), &add);
		i--;
	}
	return (table);
}
