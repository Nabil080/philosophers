/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:50:01 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/09 18:58:43 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_threads(t_data data)
{
	size_t	i;

	i = 0;
	printf("---------------\n");
	while (i < data.philo_count)
	{
		printf("Waiting thread : %zu\n", i);
		thread_operation(&data.philos[i].thread, WAIT);
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

int	thread_operation(pthread_t *thread, t_operation operation)
{
	if (operation == CREATE)
		return (pthread_create(thread, NULL, routine, NULL));
	if (operation == WAIT)
		return (pthread_join(*thread, NULL));
	return (1);
}

void	show_data(t_data data)
{
	printf("---------------\n");
	printf("Number of philosophers : %d\n", data.philo_count);
	printf("Time to die : %ld\n", data.time_to_die);
	printf("Time to eat : %ld\n", data.time_to_eat);
	printf("Time to sleep : %ld\n", data.time_to_sleep);
	printf("Number of meals : %d\n", data.meal_count);
	printf("---------------\n");
}
