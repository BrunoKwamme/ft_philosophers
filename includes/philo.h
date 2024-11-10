#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "philo_data.h"

//data
t_table	*populate_table(char **argv);
void	populate_philo(t_table *table, t_philo *philo);
void	link_spoon(t_philo philo, t_spoon *spoon, int i);

//utils
long	ft_atol(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strcmp(const char *str, const char *cmp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_put_error(char	*error);

//debug
void	print_list(t_table *list);

//routine

//mutex
void	mutex_handle(mutex_t *mutex, m_code code);

#endif
