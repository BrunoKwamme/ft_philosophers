/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:00:48 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/11 11:03:48 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

bool	starved_to_death(t_philo *philo)
{
	mutex_handle(&philo->starving_mtx, LOCK);
	if (philo->starving <= get_time())
	{
		mutex_handle(&philo->starving_mtx, UNLOCK);
		return (true);
	}
	mutex_handle(&philo->starving_mtx, UNLOCK);
	return (false);
}

int	getl_spoon(t_philo *philo)
{
	mutex_handle(&philo->l_spoon->spoon, LOCK);
	if (philo->l_spoon->is_free == true)
	{
		simulate_print(philo, FORK);
		philo->l_spoon->is_free = false;
		mutex_handle(&philo->l_spoon->spoon, UNLOCK);
		return (1);
	}
	mutex_handle(&philo->l_spoon->spoon, UNLOCK);
	return (0);
}

int	getr_spoon(t_philo *philo)
{
	mutex_handle(&philo->r_spoon->spoon, LOCK);
	if (philo->r_spoon->is_free == true)
	{
		simulate_print(philo, FORK);
		philo->r_spoon->is_free = false;
		mutex_handle(&philo->r_spoon->spoon, UNLOCK);
		return (1);
	}
	mutex_handle(&philo->r_spoon->spoon, UNLOCK);
	return (0);
}

void	return_spoons(t_philo *philo)
{
	mutex_handle(&philo->l_spoon->spoon, LOCK);
	philo->l_spoon->is_free = true;
	mutex_handle(&philo->l_spoon->spoon, UNLOCK);
	mutex_handle(&philo->r_spoon->spoon, LOCK);
	philo->r_spoon->is_free = true;
	mutex_handle(&philo->r_spoon->spoon, UNLOCK);

}

int	eating(t_philo *philo)
{
	int	i;

	i = 0;
	while (starved_to_death(philo) == false && i != 2)
	{
		if (i == 0)
			i += getr_spoon(philo);
		else
			i += getl_spoon(philo);
	}
	if (i == 2)
	{
		simulate_print(philo, EATING);
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
