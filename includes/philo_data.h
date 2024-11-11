#ifndef	PHILO_DATA_H
# define PHILO_DATA_H

# include <pthread.h>
# include <stdbool.h>

typedef pthread_mutex_t mutex_t;

typedef struct s_table t_table;

typedef enum mutex_code
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
} m_code;

typedef enum pthread_code
{
	CREATE,
	JOIN,
	DETACH,
} p_code;

typedef enum state_code
{
	EATING,
	FORK,
	SLEEPING,
	THINKING,
	DIED,
} s_code;

typedef struct	s_spoon
{
	mutex_t	spoon;
	int		spoon_id;
	bool	is_free;

}	t_spoon;

typedef struct	s_philo
{
	int				id;
	bool			is_hungry;
	long			lunch_counter;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			starving;
	int				num_of_lunch;
	mutex_t			lunch_counter_mtx;
	mutex_t			starving_mtx;
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
	mutex_t			print_mtx;
	mutex_t			is_over_mtx;
	t_philo			*philo;
	t_spoon			*spoon;
} ;
#endif
