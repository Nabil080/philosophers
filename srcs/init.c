/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:10:04 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/09 18:17:32 by nbellila         ###   ########.fr       */
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

void	init_data(t_data *data, int argc, char **argv)
{
	data->philo_count = ft_atoi(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->meal_count = -1;
	if (argc == 6)
		data->meal_count = ft_atoi(argv[5]);
	data->philos = ft_calloc(data->philo_count, sizeof(t_philo) + 1);
	if (!data->philos)
		exit_error("Philos allocation failed", NULL);
}

void	show_data(t_data data)
{
	printf("---------------\n");
	printf("Number of philosophers : %d\n", data.philo_count);
	printf("Time to die : %ld\n", data.time_to_die);
	printf("Time to eat : %ld\n", data.time_to_eat);
	printf("Time to sleep : %ld\n", data.time_to_sleep);
	printf("Number of meals : %d\n", data.meal_count);
}

static t_philo	init_philo(size_t index)
{
	t_philo	philo;

	philo.id = index + 1;
	philo.alive = true;
	philo.eating = false;
	philo.last_meal = 0;
	philo.meal_count = 0;
	//todo: link left and right forks
	pthread_create(&philo.thread, NULL, routine, NULL);
	return (philo);
}

void	init_philos(t_data data)
{
	size_t	i;

	i = 0;
	printf("---------------\n");
	while (i < data.philo_count)
	{
		printf("Creating philo : %zu\n", i);
		data.philos[i] = init_philo(i);
		i++;
	}
}