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

#include "../include/push_swap.h"

static int	check_limits(char **v)
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
			return (0);
	}
	return (1);
}

static int	check_singularity(char **v)
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_ints(char **v)
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check(t_table *t)
{
	if (check_ints(t->v) == 0
		|| check_limits(t->v) == 0
		|| check_singularity(t->v) == 0)
		write_error(&t);
}

void	write_error(t_table **t)
{
	write(1, "Error\n", 6);
	if (!t)
		exit(EXIT_FAILURE);
	free_table(*t);
	exit(EXIT_FAILURE);
}
