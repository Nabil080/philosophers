/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:50:01 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/11 20:10:20 by nbellila         ###   ########.fr       */
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
