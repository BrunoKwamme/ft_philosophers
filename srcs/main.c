/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:49:34 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/10 02:39:15 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	arg_val(char	**argv)
{
	int	i;
	int	arg_i;

	arg_i = 1;
	while (argv[arg_i])
	{
		i = 0;
		while (argv[arg_i][i])
		{
			if ((argv[arg_i][i] < 48 || argv[arg_i][i] > 57)
				|| ft_strcmp(argv[arg_i], "0") == 0)
				return (0);
			i++;
		}
		arg_i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if ((argc < 5 || argc > 6) || arg_val(argv) == 0)
	{
		ft_put_error("Bad input.\n");
		return (1);
	}
	table = populate_table(argv);
	print_list(table);
	return (0);
}
