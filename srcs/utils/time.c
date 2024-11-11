/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:27:09 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/10 14:27:20 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long	get_time(void)
{
	struct timeval		time;
	long				ms;

	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000;
	ms += time.tv_usec / 1000;
	return (ms);
}

void	ft_usleep(long ms)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(500);
}
