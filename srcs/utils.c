/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:50:01 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/09 21:39:39 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_threads(t_data data)
{
	size_t	i;

	i = 0;
	while (i < data.philo_count)
	{
		thread_operation(&data.philos[i], WAIT);
		i++;
	}
}

int	mutex_operation(t_mtx *mutex, t_operation operation)
{
	if (operation == CREATE)
		return (pthread_mutex_init(mutex, NULL));
	if (operation == DESTROY)
		return (pthread_mutex_destroy(mutex));
	if (operation == LOCK)
		return (pthread_mutex_lock(mutex));
	if (operation == UNLOCK)
		return (pthread_mutex_unlock(mutex));
	return (1);
}

int	thread_operation(t_philo *philo, t_operation operation)
{
	if (operation == CREATE)
		return (pthread_create(&philo->thread, NULL, routine, philo));
	if (operation == WAIT)
		return (pthread_join(philo->thread, NULL));
	return (1);
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
	while (time > (get_current_time() - start))
		usleep(10);
}