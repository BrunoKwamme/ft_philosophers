/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spoon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:00:48 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/12 15:56:29 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	getl_spoon(t_philo *philo)
{
	mutex_handle(&philo->l_spoon->spoon, LOCK);
	if (philo->l_spoon->is_free == true)
	{
		print_actions(philo, FORK);
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
		print_actions(philo, FORK);
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
