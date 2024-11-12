/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:56:29 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/12 15:50:55 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	print_actions(t_philo *philo, t_actcode code)
{
	long	time;

	mutex_handle(&philo->table->print_mtx, LOCK);
	time = get_time() - philo->table->start_lunch;
	if (code == EATING)
		printf("%li %d is eating\n", time, philo->id);
	if (code == FORK)
		printf("%li %d has taken a fork\n", time, philo->id);
	if (code == SLEEPING)
		printf("%li %d is sleeping\n", time, philo->id);
	if (code == THINKING)
		printf("%li %d is thinking\n", time, philo->id);
	if (code == DIED)
		printf("%li %d died\n", time, philo->id);
	mutex_handle(&philo->table->print_mtx, UNLOCK);
}

int	thinking(t_philo *philo)
{
	if (watson(philo) == 0)
		return (0);
	print_actions(philo, THINKING);
	return (1);
}

int	eating(t_philo *philo)
{
	int	i;

	i = 0;
	while (watson(philo) == 1 && i != 2)
	{
		if (i == 0)
			i += getr_spoon(philo);
		else
			i += getl_spoon(philo);
	}
	if (i == 2)
	{
		print_actions(philo, EATING);
		mutex_handle(&philo->lunch_counter_mtx, LOCK);
		philo->lunch_counter++;
		mutex_handle(&philo->lunch_counter_mtx, UNLOCK);
		set_starving(philo);
		ft_usleep(philo->time_to_eat);
		return_spoons(philo);
		return (1);
	}
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (watson(philo) == 0)
		return (0);
	print_actions(philo, SLEEPING);
	ft_usleep(philo->time_to_sleep);
	return (1);
}
