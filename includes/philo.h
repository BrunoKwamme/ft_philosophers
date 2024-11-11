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
void	simulate_print(t_philo *philo, s_code code);

//routine
void	start_lunch(t_table *table);
void	set_starving(t_philo *philo);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
bool	starved_to_death(t_philo *philo);

//mutex
void	mutex_handle(mutex_t *mutex, m_code code);

#endif
