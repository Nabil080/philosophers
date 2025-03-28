/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:10:04 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/15 23:08:07 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_args(int argc, char **argv)
{
	size_t	i;

	if (argc < 5 || argc > 6)
		exit_error("Wrong number of arguments", NULL);
	i = 1;
	while (i < argc)
	{
		if (!ft_isint(argv[i]) || argv[i][0] == '-')
			exit_error("Please only give positive integers", NULL);
		i++;
	}
}

void	init_philos(t_data *data)
{
	t_philo	philo;
	size_t	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_init(&data->philos[i].mutex, NULL);
		data->philos[i].id = i + 1;
		data->philos[i].alive = true;
		data->philos[i].eating = false;
		data->philos[i].last_meal = 0;
		data->philos[i].meal_count = 0;
		data->philos[i].left_fork = &data->forks[i];
		if (i + 1 == data->philo_count)
		{
			data->philos[i].right_fork = &data->forks[i];
			data->philos[i].left_fork = &data->forks[0];
		}
		else
			data->philos[i].right_fork = &data->forks[i + 1];
		data->philos[i].data = data;
		pthread_create(&data->philos[i].th, NULL, routine, &data->philos[i]);
		i++;
	}
}

void	init_forks(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_count)
	{
		data->forks[i].id = i + 1;
		pthread_mutex_init(&data->forks[i].mutex, NULL);
		i++;
	}
}

void	init_data(t_data *data, int argc, char **argv)
{
	data->philo_count = ft_atoi(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->time_to_think = 0;
	if (data->philo_count % 2 == 0 && data->time_to_eat >= data->time_to_sleep)
		data->time_to_think = data->time_to_eat - data->time_to_sleep;
	if (data->philo_count % 2 != 0 && data->time_to_eat >= data->time_to_sleep)
		data->time_to_think = data->time_to_eat * 2 - data->time_to_sleep;
	data->start = get_current_time();
	data->run_simulation = true;
	data->synchro = false;
	data->running_threads_count = 0;
	data->meal_count = -1;
	if (argc == 6)
		data->meal_count = ft_atoi(argv[5]);
	data->philos = ft_calloc(data->philo_count, sizeof(t_philo) + 1);
	if (!data->philos)
		exit_error("Philos allocation failed", NULL);
	data->forks = ft_calloc(data->philo_count, sizeof(t_fork) + 1);
	if (!data->forks)
		exit_error("Philos allocation failed", data);
	pthread_mutex_init(&data->print_lock, NULL);
	pthread_mutex_init(&data->read_lock, NULL);
}
