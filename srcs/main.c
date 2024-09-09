/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:36:12 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/09 21:29:51 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	show_data(t_data data)
{
	mutex_operation(&data.print_lock, LOCK);
	sep();
	printf("Number of philosophers : %d\n", data.philo_count);
	printf("Time to die : %ld\n", data.time_to_die);
	printf("Time to eat : %ld\n", data.time_to_eat);
	printf("Time to sleep : %ld\n", data.time_to_sleep);
	printf("Number of meals : %d\n", data.meal_count);
	printf("Starting time : %ld\n", data.start);
	sep();
	mutex_operation(&data.print_lock, UNLOCK);
}

static void	show_philos(t_data data)
{
	size_t	i;

	mutex_operation(&data.print_lock, LOCK);
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
	mutex_operation(&data.print_lock, LOCK);
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_args(argc, argv);
	init_data(&data, argc, argv);
	// show_data(data);
	// show_philos(data);
	wait_threads(data);
	free_data(&data);
	return (0);
}
