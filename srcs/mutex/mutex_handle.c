/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:49:44 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/12 15:50:20 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	mutex_handle(t_mutex *mutex, t_mtxcode code)
{
	if (code == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (code == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (code == LOCK)
		pthread_mutex_lock(mutex);
	else if (code == DESTROY)
		pthread_mutex_destroy(mutex);
}
