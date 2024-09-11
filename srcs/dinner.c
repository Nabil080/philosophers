/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:50:54 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/11 19:09:22 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_running(t_data *data)
{
	return (get_bool(&data->read_lock, &data->run_simulation));
}

void	print_debug(t_philo philo, t_status status)
{
	if (!is_running(philo.data))
		return ;
	pthread_mutex_lock(&philo.data->print_lock);
	printf("%ld "B_WHITE"%d "RESET, get_current_time() - philo.data->start, philo.id);
	if (status == WAIT)
		printf("is waiting\n");
	else if (status == SLEEP)
		printf("is "BLUE"sleeping\n");
	else if (status == THINK)
		printf("is thinking\n");
	else if (status == FORK)
		printf("has taken a "YELLOW"fork\n");
	else if (status == EAT)
		printf("is "GREEN"eating\n");
	else if (status == DEAD)
		printf(RED"died\n");
	else if (status == FULL)
		printf("is full\n");
	printf(RESET);
	pthread_mutex_unlock(&philo.data->print_lock);
}

void	print_status(t_philo philo, t_status status)
{
	if (!is_running(philo.data))
		return ;
	pthread_mutex_lock(&philo.data->print_lock);
	printf("%ld %d ", get_current_time() - philo.data->start, philo.id);
	if (status == WAIT)
		printf("is waiting\n");
	else if (status == SLEEP)
		printf("is sleeping\n");
	else if (status == THINK)
		printf("is thinking\n");
	else if (status == FORK)
		printf("has taken a fork\n");
	else if (status == EAT)
		printf("is eating\n");
	else if (status == DEAD)
		printf("died\n");
	else if (status == FULL)
		printf("is full\n");
	pthread_mutex_unlock(&philo.data->print_lock);
}

static void	try_to_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->mutex);
	print_status(*philo, FORK);
	pthread_mutex_lock(&philo->right_fork->mutex);
	print_status(*philo, FORK);
	set_bool(&philo->mutex, &philo->eating, true);
	set_long(&philo->mutex, &philo->last_meal, get_current_time() - philo->data->start);
	print_status(*philo, EAT);
	ft_usleep(philo->data->time_to_eat * 1000);
	philo->meal_count++;
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
	while (get_bool(&data->read_lock, &data->synchro) == false)
		ft_usleep(100);
	if (philo->id % 2 == 0)
	{
		print_status(*philo, THINK);
		ft_usleep(data->time_to_eat);
	}
	while (is_running(data) && philo->meal_count != data->meal_count)
	{
		if (is_running(data))
			try_to_eat(philo);
		print_status(*philo, SLEEP);
		if (is_running(data))
			ft_usleep(data->time_to_sleep * 1000);
		print_status(*philo, THINK);
	}
	print_status(*philo, FULL);
	return (NULL);
}

void	*supervise(void *args)
{
	t_data *data;
	t_philo	philo;
	size_t	i;

	data = (t_data *)args;
	data->start = get_current_time();
	set_bool(&data->read_lock, &data->synchro, true);
	while (is_running(data))
	{
		i = 0;
		while (is_running(data) && i < data->philo_count)
		{
			pthread_mutex_lock(&data->print_lock);
			// printf("Monitoring philo[%zu]\n", i);
			pthread_mutex_unlock(&data->print_lock);
			philo = data->philos[i];
			if (get_bool(&philo.mutex, &philo.eating) == false
				&& get_current_time() - data->start - get_long(&philo.mutex, &philo.last_meal) >= data->time_to_die)
			{
				print_status(philo, DEAD);
				set_bool(&data->read_lock, &data->run_simulation, false);
			}
			i++;
		}
	}
	return (NULL);
}