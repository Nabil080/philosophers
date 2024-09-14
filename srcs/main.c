/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:36:12 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/14 22:43:41 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	check_args(argc, argv);
	init_data(&data, argc, argv);
	init_forks(&data);
	init_philos(&data);
	while (get_ulong(&data.read_lock, &data.running_threads_count)
		!= data.philo_count)
		usleep(10);
	set_ulong(&data.read_lock, &data.start, get_current_time());
	set_bool(&data.read_lock, &data.synchro, true);
	wait_threads(&data);
	free_data(&data);
	return (0);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
}

void	exit_error(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		free_data(data);
	exit(EXIT_FAILURE);
}

void	wait_threads(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_join(data->philos[i].th, NULL);
		i++;
	}
	set_bool(&data->read_lock, &data->run_simulation, false);
}
