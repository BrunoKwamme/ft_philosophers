#ifndef	PHILO_DATA_H
# define PHILO_DATA_H

# include <pthread.h>

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

typedef struct	s_spoon
{
	mutex_t	spoon;
	int		spoon_id;

}	t_spoon;

typedef struct	s_philo
{
	int				id;
	int				is_hungry;
	long			lunch_counter;
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
	t_philo			*philo;
	t_spoon			*spoon;
} ;
#endif
