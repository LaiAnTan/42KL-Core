#include "philo.h"

void	create_all_threads(t_data *p, void *(*f)(), void *args)
{
	int		i;

	i = 0;
	p->threads = (pthread_t *) malloc (sizeof(pthread_t) * p->no_of_philosophers);
	while (i < p->no_of_philosophers)
	{
		pthread_create(&p->threads[i], NULL, f, args);
		i++;
	}
}

void	join_all_threads(t_data *p)
{
	int		i;

	i = 0;
	while (i < p->no_of_philosophers)
		pthread_join(p->threads[i++], NULL);
}

void	init_mutex(t_data *p)
{
	int	i;

	i = 0;
	while (i < p->no_of_philosophers)
		pthread_mutex_init(&p->forks[i++], NULL);
	pthread_mutex_init(&p->eat_mtx, NULL);
	pthread_mutex_init(&p->time_mtx, NULL);
	pthread_mutex_init(&p->write_mtx, NULL);
	pthread_mutex_init(&p->start_mtx, NULL);
	pthread_mutex_init(&p->stop_mtx, NULL);
	pthread_mutex_init(&p->death_mtx, NULL);
}

void	destroy_mutex(t_data *p)
{
	int	i;

	i = 0;
	while (i < p->no_of_philosophers)
		pthread_mutex_destroy(&p->forks[i++]);
	pthread_mutex_destroy(&p->eat_mtx);
	pthread_mutex_destroy(&p->time_mtx);
	pthread_mutex_destroy(&p->write_mtx);
	pthread_mutex_destroy(&p->start_mtx);
	pthread_mutex_destroy(&p->stop_mtx);
	pthread_mutex_destroy(&p->death_mtx);
}

void	unlock_all_mutex(t_data *data, int thread_index)
{
	if (thread_index + 1 == data->no_of_philosophers)
		pthread_mutex_unlock(&data->forks[0]);
	else
		pthread_mutex_unlock(&data->forks[thread_index + 1]);
	pthread_mutex_unlock(&data->forks[thread_index]);
	// pthread_mutex_unlock(&data->eat_mtx);
	// pthread_mutex_unlock(&data->time_mtx);
	// pthread_mutex_unlock(&data->write_mtx);
	// pthread_mutex_unlock(&data->death_mtx);
	// pthread_mutex_unlock(&data->stop_mtx);
}