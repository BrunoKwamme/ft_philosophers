/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:46:51 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/12 15:50:55 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include "philo_data.h"

//data
t_table	*populate_table(char **argv);
void	populate_philo(t_table *table, t_philo *philo);
void	link_spoon(t_philo philo, t_spoon *spoon, int i);

//utils
long	ft_atol(const char *nptr);
int		ft_strcmp(const char *str, const char *cmp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_put_error(char	*error);
void	ft_usleep(long ms);
long	get_time(void);

//debug
void	print_list(t_table *list);
void	print_actions(t_philo *philo, t_actcode code);

//spoon link
void	return_spoons(t_philo *philo);
int		getr_spoon(t_philo *philo);
int		getl_spoon(t_philo *philo);

//sherlock
bool	starved_to_death(t_philo *philo);
int		tell_death(t_table *table);
int		watson(t_philo *philo);
bool	is_philo_full(t_philo *philo);

//philo
void	start_lunch(t_table *table);
void	*sherlock_routine(void	*arg);
void	set_starving(t_philo *philo);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
int		thinking(t_philo *philo);

//mutex
void	mutex_handle(t_mutex *mutex, t_mtxcode code);
void	destroy_and_free(t_table *table);

#endif
