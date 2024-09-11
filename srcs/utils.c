/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:50:01 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/11 19:00:14 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_threads(t_data data)
{
	size_t	i;

	i = 0;
	while (i < data.philo_count)
	{
		pthread_join(data.philos[i].thread, NULL);
		i++;
	}
}

time_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(time_t time)
{
	time_t	start;

	start = get_current_time();
	usleep(time);
}

bool	get_bool(t_mtx *mutex, bool *var)
{
	bool	res;

	pthread_mutex_lock(mutex);
	res = *var;
	pthread_mutex_unlock(mutex);
	return (res);
}

void	set_bool(t_mtx *mutex, bool *var, bool res)
{
	pthread_mutex_lock(mutex);
	*var = res;
	pthread_mutex_unlock(mutex);
}

long	get_long(t_mtx *mutex, long *var)
{
	long	res;

	pthread_mutex_lock(mutex);
	res = *var;
	pthread_mutex_unlock(mutex);
	return (res);
}

void	set_long(t_mtx *mutex, long *var, long res)
{
	pthread_mutex_lock(mutex);
	*var = res;
	pthread_mutex_unlock(mutex);
}