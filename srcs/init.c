/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:10:04 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/03 20:28:36 by nbellila         ###   ########.fr       */
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
		if (!ft_isnumber(argv[i]))
			exit_error("Non numeric argument", NULL);
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
	data->philos = NULL;
}

void	show_data(t_data data)
{
	printf("Number of philosophers : %d\n", data.philo_count);
	printf("Time to die : %ld\n", data.time_to_die);
	printf("Time to eat : %ld\n", data.time_to_eat);
	printf("Time to sleep : %ld\n", data.time_to_sleep);
	printf("Number of meals : %d\n", data.meal_count);
}