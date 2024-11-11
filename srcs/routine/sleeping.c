/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:46:41 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/11 11:17:09 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	sleeping(t_philo *philo)
{
	mutex_handle(&philo->starving_mtx, LOCK);
	simulate_print(philo, SLEEPING);
	ft_usleep(philo->time_to_sleep);
	set_starving(philo);
	mutex_handle(&philo->starving_mtx, UNLOCK);
	return (1);
}
