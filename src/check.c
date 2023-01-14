/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 15:01:35 by itopchu       #+#    #+#                 */
/*   Updated: 2023/01/09 15:01:35 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_limits(char **v)
{
	int			i;
	int			j;
	long		check;

	i = 0;
	while (v[i])
	{
		check = 0;
		j = 0;
		if (v[i][j] == '-')
			j++;
		while (v[i][j])
		{
			check = check * 10 + v[i][j] - '0';
			j++;
		}
		i++;
		if (check < -2147483648 || check > 2147483647)
			write_error(NULL, v);
	}
}

static void	check_singularity(char **v)
{
	int	i;
	int	j;

	i = 0;
	while (v[i])
	{
		j = i + 1;
		while (v[j])
		{
			if (ft_atoi(v[i]) == ft_atoi(v[j]))
				write_error(NULL, v);
			j++;
		}
		i++;
	}
}

static void	check_ints(char **v)
{
	int			i;
	int			j;

	i = 0;
	while (v[i])
	{
		j = 0;
		if (v[i][j] == '-')
			j++;
		while (v[i][j])
		{
			if (!ft_isdigit(v[i][j]))
				write_error(NULL, v);
			j++;
		}
		i++;
	}
}

void	check(char **v)
{
	check_ints(v);
	check_limits(v);
	check_singularity(v);
}

void	write_error(t_table **t, char **v)
{
	write(1, "Error\n", 6);
	free_vector(v);
	if (!t)
		exit(EXIT_FAILURE);
	free_table(*t);

	exit(EXIT_FAILURE);
}
