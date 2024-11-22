/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:30:45 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/22 14:04:04 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	destroy_and_free(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_num)
	{
		mutex_handle(&table->philo[i].lunch_counter_mtx, DESTROY);
		mutex_handle(&table->philo[i].starving_mtx, DESTROY);
		mutex_handle(&table->spoon[i].spoon, DESTROY);
	}
	mutex_handle(&table->print_mtx, DESTROY);
	mutex_handle(&table->is_over_mtx, DESTROY);
	free(table->philo);
	free(table->spoon);
	free(table);
}
