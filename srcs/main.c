/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:36:12 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/10 19:22:23 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	show_data(t_data data)
{
	pthread_mutex_lock(&data.print_lock);
	sep();
	printf("Number of philosophers : %d\n", data.philo_count);
	printf("Time to die : %ld\n", data.time_to_die);
	printf("Time to eat : %ld\n", data.time_to_eat);
	printf("Time to sleep : %ld\n", data.time_to_sleep);
	printf("Number of meals : %d\n", data.meal_count);
	printf("Starting time : %ld\n", data.start);
	sep();
	pthread_mutex_unlock(&data.print_lock);
}

static void	show_philos(t_data data)
{
	size_t	i;

	pthread_mutex_lock(&data.print_lock);
	sep();
	i = 0;
	while (i < data.philo_count)
	{
		printf("Philosopher ID : %d\n", data.philos[i].id);
		printf("Left fork :\t%p\n", data.philos[i].left_fork);
		printf("Right fork :\t\t%p\n", data.philos[i].right_fork);
		i++;
	}
	sep();
	pthread_mutex_unlock(&data.print_lock);
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_args(argc, argv);
	init_data(&data, argc, argv);
	// show_data(data);
	init_forks(&data);
	init_philos(&data);
	// show_philos(data);
	pthread_create(&data.supervisor, NULL, supervise, &data);
	wait_threads(data);
	free_data(&data);
	return (0);
}
