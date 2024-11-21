/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_lunch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:12:51 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/21 15:01:24 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	set_starving(t_philo *philo)
{
	mutex_handle(&philo->starving_mtx, LOCK);
	philo->starving = get_time() + philo->time_to_die;
	mutex_handle(&philo->starving_mtx, UNLOCK);
}

bool	is_philo_full(t_philo *philo)
{
	mutex_handle(&philo->lunch_counter_mtx, LOCK);
	if (philo->lunch_counter == philo->num_of_lunch)
	{
		mutex_handle(&philo->lunch_counter_mtx, UNLOCK);
		return (true);
	}
	mutex_handle(&philo->lunch_counter_mtx, UNLOCK);
	return (false);
}

int	watson(t_philo *philo)
{
	mutex_handle(&philo->table->is_over_mtx, LOCK);
	if (philo->table->is_over == true)
	{
		mutex_handle(&philo->table->is_over_mtx, UNLOCK);
		return (0);
	}
	mutex_handle(&philo->table->is_over_mtx, UNLOCK);
	if (is_philo_full(philo) == true)
		return (0);
	return (1);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	set_starving(philo);
	if (philo->id % 2 == 0)
		ft_usleep(100);
	while (watson(philo) == 1)
	{
		if (!thinking(philo))
			break ;
		if (!eating(philo))
			break ;
		if (!sleeping(philo))
			break ;
	}
	return (NULL);
}

void	start_lunch(t_table *table)
{
	pthread_t	sherlock;
	int			i;

	i = -1;
	table->start_lunch = get_time();
	while (++i < table->philo_num)
		pthread_create(&table->philo[i].thread, NULL,
			philo_routine, (void *)&table->philo[i]);
	i = -1;
	pthread_create(&sherlock, NULL, sherlock_routine, (void *) table);
	pthread_join(sherlock, NULL);
	while (++i < table->philo_num)
		pthread_join(table->philo[i].thread, NULL);
	destroy_and_free(table);
}
