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

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_table	*table;
	char	**argv;

	if (ac <= 1)
		return (EXIT_FAILURE);
	av++;
	argv = av;
	if (ac == 2)
		argv = ft_split(av[0], ' ');
	if (!argv)
		return (EXIT_FAILURE);
	ac = len_vector(argv);
	check(argv);
	table = table_init(ac - 1, argv);
	if (sorted(table->a, 'a'))
		return (free_table(table), EXIT_SUCCESS);
	push_swap(table);
	if (ac == 2)
		free_vector(argv);
	free_table(table);
	return (EXIT_SUCCESS);
}
