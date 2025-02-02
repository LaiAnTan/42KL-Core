/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:57:41 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/19 17:14:04 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_sleep(t_data *data, int philo_num)
{
	t_ms	curr_time;

	curr_time = get_curr_time(data);
	print_action(data, curr_time, philo_num, 1);
	usleep(data->time_to_sleep);
	curr_time = get_curr_time(data);
	print_action(data, curr_time, philo_num, 3);
}

void	p_leftfork(t_data *data, int philo_num, int *forks)
{
	t_ms	curr_time;

	curr_time = get_curr_time(data);
	pthread_mutex_lock(&data->forks[philo_num - 1]);
	print_action(data, curr_time, philo_num, 4);
	*forks = *forks + 1;
}

void	p_rightfork(t_data *data, int philo_num, int *forks)
{
	t_ms	curr_time;

	curr_time = get_curr_time(data);
	if (data->no_of_philosophers == 1)
		return ;
	if (philo_num == data->no_of_philosophers)
		pthread_mutex_lock(&data->forks[0]);
	else
		pthread_mutex_lock(&data->forks[philo_num]);
	print_action(data, curr_time, philo_num, 4);
	*forks = *forks + 1;
}

void	p_eat(t_data *data, int philo_num)
{
	int					p;
	long unsigned int	curr_time;

	curr_time = get_curr_time(data);
	p = philo_num - 1;
	print_action(data, curr_time, philo_num, 2);
	usleep(data->time_to_eat);
	if (philo_num == data->no_of_philosophers)
		pthread_mutex_unlock(&data->forks[0]);
	else
		pthread_mutex_unlock(&data->forks[philo_num]);
	pthread_mutex_unlock(&data->forks[p]);
	pthread_mutex_lock(&data->eat_mtx);
	data->last_ate[p] = curr_time;
	data->eat_count[p] += 1;
	pthread_mutex_unlock(&data->eat_mtx);
}
