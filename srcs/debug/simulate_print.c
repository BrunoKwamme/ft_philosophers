/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:10:13 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/10 17:08:53 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	simulate_print(t_philo *philo, s_code code)
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
	//printf("in %li -> philo %d\n", time, philo->id);
	mutex_handle(&philo->table->print_mtx, UNLOCK);
}
