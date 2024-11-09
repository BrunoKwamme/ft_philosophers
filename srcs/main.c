/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:49:34 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/09 20:01:47 by bkwamme          ###   ########.fr       */
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

t_philo	*populate_using_argv(int id, char **argv, int argc)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo), 1);
	philo->philo_id = id;
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->num_of_lunch = -1;
	if (argc == 6)
		philo->num_of_lunch = ft_atoi(argv[5]);
	philo->next = NULL;
	return (philo);
}

t_philo	*populate_list(char **argv, int argc)
{
	t_philo	*philo;
	t_philo	*head;
	int		philo_num;
	int		i;

	i = 1;
	philo = populate_using_argv(i, argv, argc);
	philo_num = ft_atoi(argv[1]);
	head = philo;
	i++;
	while (i <= philo_num)
	{
		philo->next = populate_using_argv(i, argv, argc);
		philo = philo->next;
		i++;
	}
	philo = head;
	return (philo);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = NULL;
	if ((argc < 5 || argc > 6) || arg_val(argv) == 0)
	{
		write(2, "Bad input\n", 10);
		return (0);
	}
	philo = populate_list(argv, argc);
	print_list(philo);
	return (0);
}
