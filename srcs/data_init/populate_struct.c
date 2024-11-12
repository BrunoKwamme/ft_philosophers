/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:14:44 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/12 15:59:20 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	populate_philo(t_table *table, t_philo *philo)
{
	int		i;

	i = -1;
	while (++i < table->philo_num)
	{
		philo[i].is_hungry = true;
		philo[i].table = table;
		philo[i].lunch_counter = 0;
		philo[i].id = i + 1;
		philo[i].time_to_die = table->time_to_die;
		philo[i].time_to_eat = table->time_to_eat;
		philo[i].time_to_sleep = table->time_to_sleep;
		philo[i].num_of_lunch = table->num_of_lunch;
		philo[i].r_spoon = &table->spoon[philo[i].id - 1];
		philo[i].l_spoon = &table->spoon[philo[i].id % table->philo_num];
		mutex_handle(&philo[i].starving_mtx, INIT);
		mutex_handle(&philo[i].lunch_counter_mtx, INIT);
	}
}

void	populate_spoon(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_num)
	{
		table->spoon[i].spoon_id = i + 1;
		table->spoon[i].is_free = true;
		mutex_handle(&table->spoon[i].spoon, INIT);
	}
}

t_table	*populate_table(char **argv)
{
	t_table		*table;

	table = malloc(sizeof(t_table) * 1);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	table->num_of_lunch = -1;
	if (argv[5])
		table->num_of_lunch = ft_atol(argv[5]);
	table->start_lunch = 0;
	table->is_over = false;
	table->philo_num = ft_atol(argv[1]);
	table->spoon = malloc(sizeof(t_spoon) * table->philo_num);
	table->philo = malloc(sizeof(t_philo) * table->philo_num);
	mutex_handle(&table->print_mtx, INIT);
	mutex_handle(&table->is_over_mtx, INIT);
	populate_spoon(table);
	populate_philo(table, table->philo);
	return (table);
}
