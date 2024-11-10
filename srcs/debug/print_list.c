/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:52:59 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/10 01:51:12 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	print_list(t_table *list)
{
	printf("\n--------- table ---------\n");
	printf("philo num ->%li\n", list->philo_num);
	printf("time to die ->%li\n", list->time_to_die);
	printf("time to eat ->%li\n", list->time_to_eat);
	printf("time to slepp ->%li\n", list->time_to_sleep);
	printf("num of lunch ->%i\n", list->num_of_lunch);
	printf("\n--------- philo ---------\n");
	for (int x = 0; x < list->philo_num; x++)
	{
		printf("philo id ->%d\n", list->philo[x].id);
		printf("is hungry? ->%d\n", list->philo[x].is_hungry);
		printf("lunch counter ->%ld\n", list->philo[x].lunch_counter);
	}
	printf("\n--------- spoon ---------\n");
	for (int y = 0; y < list->philo_num; y++)
		printf("spoon id ->%d\n", list->spoon[y].spoon_id);
}
