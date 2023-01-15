/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 15:00:29 by itopchu       #+#    #+#                 */
/*   Updated: 2023/01/09 15:00:29 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_list(t_circular *l)
{
	t_circular	*tmp;
	int			i;

	i = 0;
	tmp = l;
	while (tmp != l || i == 0)
	{
		ft_printf("%d ", tmp->value);
		tmp = tmp->next;
		i++;
	}
	ft_printf("\n");
}

char	**fill_vector(char **v, int ac)
{
	char	**vector;
	int		i;

	if (ac == 1)
		return (ft_split(v[0], ' '));
	vector = (char **)ft_calloc(ac + 1, sizeof(char *));
	if (vector == NULL)
		return (NULL);
	i = 0;
	while (v[i])
	{
		vector[i] = ft_strdup(v[i]);
		if (!vector[i])
			return (free_vector(vector), NULL);
		i++;
	}
	return (vector);
}

int	main(int ac, char **av)
{
	t_table	*table;

	if (ac <= 1)
		return (EXIT_FAILURE);
	av++;
	ac--;
	table = table_init(ac, av);
	if (sorted(table->a, 'a'))
		return (free_table(table), EXIT_SUCCESS);
	push_swap(table);
	free_table(table);
	return (EXIT_SUCCESS);
}
