/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sherlock_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:46:41 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/12 15:25:55 by bkwamme          ###   ########.fr       */
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

int	tell_death(t_table *table)
{
	mutex_handle(&table->is_over_mtx, LOCK);
	if (!table->is_over)
	{
		mutex_handle(&table->is_over_mtx, UNLOCK);
		table->is_over = true;
		return (1);
	}
	mutex_handle(&table->is_over_mtx, UNLOCK);
	return (0);
}

bool	is_all_full(t_philo *philo, int *flag)
{
	if (is_philo_full(philo))
		*flag = *flag + 1;
	if (*flag == philo->table->philo_num)
		return (true);
	return (false);
}

void	*sherlock_routine(void	*arg)
{
	t_table *table;
	int		i;
	int		flag;

	flag = 0;
	i = 0;
	table = (t_table *)arg;
	while (!is_all_full(&table->philo[i], &flag))
	{
		if (starved_to_death(&table->philo[i]))
		{
			if (tell_death(table) == 1)
			{
				print_actions(&table->philo[i], DIED);
				break ;
			}
		}
		i++;
		if (i == table->philo_num)
			i = 0;
	}
	return (NULL);
}
