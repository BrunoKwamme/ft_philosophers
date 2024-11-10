/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:49:44 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/10 00:52:48 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	mutex_handle(mutex_t *mutex, m_code code)
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
