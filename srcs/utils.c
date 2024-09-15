/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:50:01 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/15 23:08:18 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(t_data *data, time_t time_in_ms)
{
	time_t	start;
	time_t	remaining;

	start = get_current_time();
	remaining = time_in_ms;
	while (is_running(data) && remaining > 10)
	{
		usleep(10 * 1000);
		remaining = time_in_ms - (get_current_time() - start);
	}
	while (is_running(data) && remaining > 0)
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

void	print_status(t_philo philo, char *str)
{
	pthread_mutex_lock(&philo.data->print_lock);
	if (is_running(philo.data))
		printf("%ld %d %s\n",
			get_current_time() - philo.data->start, philo.id, str);
	pthread_mutex_unlock(&philo.data->print_lock);
}
