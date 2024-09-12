/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:50:01 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/12 19:24:56 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_threads(t_data data)
{
	size_t	i;

	i = 0;
	while (i < data.philo_count)
	{
		pthread_join(data.philos[i].th, NULL);
		i++;
	}
	set_bool(&data.read_lock, &data.run_simulation, false);
	pthread_join(data.supervisor, NULL);
}

time_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(time_t time_in_ms)
{
	time_t	start;
	time_t	remaining;

	start = get_current_time();
	remaining = time_in_ms;
	while (remaining > 10)
	{
		usleep(remaining / 2 * 1000);
		remaining = time_in_ms - (get_current_time() - start);
	}
	while (remaining > 0)
	{
		usleep(10);
		remaining = time_in_ms - (get_current_time() - start);
	}
}

time_t	get_philo_relative_lastmeal(t_philo *philo)
{
	time_t	last_meal;
	time_t	now;
	time_t	start;

	last_meal = get_ulong(&philo->mutex, &philo->last_meal);
	now = get_current_time();
	start = philo->data->start;
	return (now - start - last_meal);
}
