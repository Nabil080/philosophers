/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:10:04 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/09 18:56:49 by nbellila         ###   ########.fr       */
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

static void	init_philos(t_data *data)
{
	t_philo	philo;
	size_t	i;

	i = 0;
	printf("---------------\n");
	while (i < data->philo_count)
	{
		printf("Creating philo : %zu\n", i);
		data->philos[i].id = i + 1;
		data->philos[i].alive = true;
		data->philos[i].eating = false;
		data->philos[i].last_meal = 0;
		data->philos[i].meal_count = 0;
		if (i == 0)
			data->philos[i].left_fork = data->forks[data->philo_count];
		else
			data->philos[i].left_fork = data->forks[i - 1];
		data->philos[i].right_fork = data->forks[i];
		thread_operation(&data->philos[i].thread, CREATE);
		i++;
	}
}

static void	init_forks(t_data *data)
{
	size_t	i;
	
	i = 0;
	printf("---------------\n");
	while (i < data->philo_count)
	{
		printf("Creating fork : %zu\n", i);
		if (i + 1 < data->philo_count)
			data->forks[i].id = i + 1;
		else
			data->forks[i].id = 0;
		mutex_operation(&data->forks[i].mutex, CREATE);
		i++;
	}
}

void	init_data(t_data *data, int argc, char **argv)
{
	data->philo_count = ft_atoi(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->meal_count = -1;
	if (argc == 6)
		data->meal_count = ft_atoi(argv[5]);
	data->forks = NULL;
	data->philos = ft_calloc(data->philo_count, sizeof(t_philo) + 1);
	if (!data->philos)
		exit_error("Philos allocation failed", data);
	data->forks = ft_calloc(data->philo_count, sizeof(t_fork) + 1);
	if (!data->forks)
		exit_error("Philos allocation failed", data);
	init_forks(data);
	init_philos(data);
}
