/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:50:54 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/15 23:11:14 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void sleep_and_die(t_philo *philo)
{
	ft_usleep(philo->data, philo->data->time_to_die - ((get_current_time() - philo->data->start) - philo->last_meal));
	pthread_mutex_lock(&philo->data->print_lock);
	if (is_running(philo->data))
		printf("\033[91m%ld %d died\033[0m\n", get_current_time() - philo->data->start, philo->id);
	set_bool(&philo->data->read_lock, &philo->data->run_simulation, false);
	pthread_mutex_unlock(&philo->data->print_lock);
}

static void philo_think(t_philo *philo)
{
	print_status(*philo, "\033[34mis thinking\033[0m");
	if (get_philo_relative_lastmeal(philo) + philo->data->time_to_think >= philo->data->time_to_die)
		sleep_and_die(philo);
	else
		ft_usleep(philo->data, philo->data->time_to_think);
}

static void philo_sleep(t_philo *philo)
{
	print_status(*philo, "\033[36mis sleeping\033[0m");
	if (get_philo_relative_lastmeal(philo) + philo->data->time_to_sleep >= philo->data->time_to_die)
		sleep_and_die(philo);
	else
		ft_usleep(philo->data, philo->data->time_to_sleep);
}

static void philo_eat(t_philo *philo)
{
	if (philo->data->philo_count == 1)
	{
		print_status(*philo, "\033[33mhas taken a fork\033[0m");
		ft_usleep(philo->data, philo->data->time_to_die);
		return;
	}
	pthread_mutex_lock(&philo->left_fork->mutex);
	print_status(*philo, "\033[33mhas taken a fork\033[0m");
	pthread_mutex_lock(&philo->right_fork->mutex);
	print_status(*philo, "\033[33mhas taken a fork\033[0m");
	set_bool(&philo->mutex, &philo->eating, true);
	philo->meal_count++;
	print_status(*philo, "\033[32mis eating\033[0m");
	set_ulong(&philo->mutex, &philo->last_meal, get_current_time() - philo->data->start);
	if (get_philo_relative_lastmeal(philo) + philo->data->time_to_eat >= philo->data->time_to_die)
		sleep_and_die(philo);
	else
		ft_usleep(philo->data, philo->data->time_to_eat);
	set_bool(&philo->mutex, &philo->eating, false);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
}

void *routine(void *args)
{
	t_philo *philo;
	t_data	*data;

	philo = (t_philo *)args;
	data = philo->data;
	pthread_mutex_lock(&data->read_lock);
	data->running_threads_count++;
	pthread_mutex_unlock(&data->read_lock);
	while (get_bool(&data->read_lock, &data->synchro) == false)
		usleep(10);
	print_status(*philo, "\033[34mis thinking\033[0m");
	if (philo->id % 2 == 0)
		ft_usleep(data, data->time_to_eat);
	while (is_running(data) && philo->meal_count != data->meal_count)
	{
		philo_eat(philo);
		if (is_running(data) && philo->meal_count != data->meal_count)
			philo_sleep(philo);
		if (is_running(data) && philo->meal_count != data->meal_count)
			philo_think(philo);
	}
	return (NULL);
}
