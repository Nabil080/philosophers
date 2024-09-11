/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:50:54 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/11 21:39:27 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_think(t_philo *philo)
{
	print_status(*philo, THINK);
}

static void	philo_sleep(t_philo *philo)
{
	print_status(*philo, SLEEP);
	ft_usleep(philo->data->time_to_sleep);
}

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->mutex);
	print_status(*philo, L_FORK);
	pthread_mutex_lock(&philo->right_fork->mutex);
	print_status(*philo, R_FORK);
	set_bool(&philo->mutex, &philo->eating, true);
	philo->meal_count++;
	set_ulong(&philo->mutex, &philo->last_meal, get_current_time() - philo->data->start);
	print_status(*philo, EAT);
	ft_usleep(philo->data->time_to_eat);
	set_bool(&philo->mutex, &philo->eating, false);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
}

void	*routine(void *args)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)args;
	data = philo->data;
	//? synchro all philos with themselves and supervisor
	pthread_mutex_lock(&data->read_lock);
	data->running_threads_count++;
	pthread_mutex_unlock(&data->read_lock);
	while (get_bool(&data->read_lock, &data->synchro) == false)
		usleep(10);
	//? every odd philo's start by thinking
	philo_think(philo);
	if (philo->id % 2 == 0)
		ft_usleep(data->time_to_eat);
	//? loop until one philo is dead or this one is full
	while (is_running(data) || philo->meal_count == data->meal_count)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	print_status(*philo, FULL);
	return (NULL);
}

void	*supervise(void *args)
{
	t_data *data;
	t_philo	*philo;
	size_t	i;

	data = (t_data *)args;
	while (get_bool(&data->read_lock, &data->synchro) == false)
		usleep(10);
	
	//todo: loop until the simulation is over, looking for dead philos
	while (is_running(data))
	{
		i = 0;
		while (is_running(data) && i < data->philo_count)
		{
			philo = &data->philos[i];
			if (philo->eating == false && data->time_to_die <=
				(get_current_time() - data->start - get_ulong(&philo->mutex, &philo->last_meal)))
			{
				set_bool(&philo->mutex, &philo->alive, false);
				set_bool(&data->read_lock, &data->run_simulation, false);
				print_status(*philo, DEAD);
			}
			i++;
		}
	}
	return (NULL);
}
