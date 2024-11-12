/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:46:55 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/12 15:51:22 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DATA_H
# define PHILO_DATA_H

# include <pthread.h>
# include <stdbool.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_table	t_table;

typedef enum mutex_code
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
}	t_mtxcode;

typedef enum state_code
{
	EATING,
	FORK,
	SLEEPING,
	THINKING,
	DIED,
}	t_actcode;

typedef struct s_spoon
{
	t_mutex	spoon;
	int		spoon_id;
	bool	is_free;

}	t_spoon;

typedef struct s_philo
{
	int				id;
	bool			is_hungry;
	long			lunch_counter;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			starving;
	int				num_of_lunch;
	t_mutex			lunch_counter_mtx;
	t_mutex			starving_mtx;
	pthread_t		thread;
	t_spoon			*r_spoon;
	t_spoon			*l_spoon;
	t_table			*table;
}	t_philo;

struct	s_table
{
	long			philo_num;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				num_of_lunch;
	long			start_lunch;
	bool			is_over;
	t_mutex			print_mtx;
	t_mutex			is_over_mtx;
	t_philo			*philo;
	t_spoon			*spoon;
} ;
#endif
