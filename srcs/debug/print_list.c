/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:52:59 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/09 19:53:06 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	print_list(t_philo *list)
{
	t_philo *philo = list;
	int	x = 0;
	while (philo)
	{
		printf("philo id -> %d\n", philo->philo_id);
		printf("time to die ->%d\n", philo->time_to_die);
		printf("time to eat ->%d\n", philo->time_to_eat);
		printf("time to sleep ->%d\n", philo->time_to_sleep);
		printf("num of lunchs%d\n", philo->num_of_lunch);
		philo = philo->next;
		x++;
		printf("\n");
	}
	printf("num of forks ->%d\n", x);
}
