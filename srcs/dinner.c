/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:50:54 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/09 21:39:01 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	safe_print(t_philo philo, char *str)
{
	mutex_operation(&philo.data->print_lock, LOCK);
	printf("%ld %d ", get_current_time() - philo.data->start, philo.id);
	printf("%s\n", str);
	mutex_operation(&philo.data->print_lock, UNLOCK);
}

static void	try_to_eat(t_philo *philo)
{
	mutex_operation(&philo->left_fork->mutex, LOCK);
	safe_print(*philo, "has taken a fork");
	mutex_operation(&philo->right_fork->mutex, LOCK);
	safe_print(*philo, "has taken a fork");
	philo->eating = true;
	philo->last_meal = get_current_time() - philo->data->start;
	safe_print(*philo, "is eating");
	usleep(philo->data->time_to_eat);
	philo->meal_count++;
	philo->eating = false;
	mutex_operation(&philo->left_fork->mutex, UNLOCK);
	mutex_operation(&philo->right_fork->mutex, UNLOCK);
}

void	*routine(void *args)
{
	t_philo	*philo;
	t_data	data;

	philo = (t_philo *)args;
	data = *philo->data;
	while (data.run_simulation && philo->meal_count != data.meal_count)
	{
		safe_print(*philo, "is thinking");
		try_to_eat(philo);
		safe_print(*philo, "is sleeping");
		usleep(data.time_to_sleep);
	}
	safe_print(*philo, "is done");
	return (NULL);
}

void	*supervise(void *args)
{
	size_t	i;
	t_data	data;

	data = *(t_data *)args;
	while (data.run_simulation)
	{
		i = 0;
		while (data.run_simulation && i < data.philo_count)
		{
			if (get_current_time() - data.start - data.philos[i].last_meal >= data.time_to_die
				&& data.philos[i].eating == false)
			{
				printf("Current time : %ld, last meal : %ld, time to die : %ld\n", get_current_time(), data.philos[i].last_meal, data.time_to_die);
				safe_print(data.philos[i], "has died");
				data.run_simulation = false;
			}
			i++;
		}
	}
	return (NULL);
}