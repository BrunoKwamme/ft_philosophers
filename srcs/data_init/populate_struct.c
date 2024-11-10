/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:14:44 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/10 01:40:18 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	link_spoon(t_philo philo, t_spoon *spoon, int i)
{
	philo.l_spoon = &spoon[(i + i) % philo.table->philo_num];
	philo.r_spoon = &spoon[i];
	if (philo.id % 2 == 0)
	{
		philo.l_spoon = &spoon[i];
		philo.r_spoon = &spoon[(i + i) % philo.table->philo_num];
	}
}

void	populate_philo(t_table *table, t_philo *philo)
{
	int		i;

	i = -1;
	while (++i < table->philo_num)
	{
		philo[i].is_hungry = 1;
		philo[i].table = table;
		philo[i].lunch_counter = 0;
		philo[i].id = i + 1;
		link_spoon(philo[i], table->spoon, i);
	}
}

t_table	*populate_table(char **argv)
{
	t_table		*table;
	int			i;

	table = ft_calloc(sizeof(t_table), 1);
	i = -1;
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	table->num_of_lunch = -1;
	if (argv[5])
		table->num_of_lunch = ft_atol(argv[5]);
	table->philo_num = ft_atol(argv[1]);
	table->spoon = ft_calloc(sizeof(t_spoon), table->philo_num);
	table->philo = ft_calloc(sizeof(t_philo), table->philo_num);
	while (++i < table->philo_num)
	{
		table->spoon[i].spoon_id = i + 1;
		mutex_handle(&table->spoon[i].spoon, INIT);
	}
	populate_philo(table, table->philo);
	return (table);
}
