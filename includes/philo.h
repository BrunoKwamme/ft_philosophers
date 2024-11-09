#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_philo
{
	pthread_t	philo;
	int		philo_id;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_lunch;
	struct s_philo	*next;
}	t_philo;

//utils
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_strcmp(const char *str, const char *cmp);

//debug
void	print_list(t_philo *list);

#endif
