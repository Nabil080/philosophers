/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:24:14 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/12 19:01:36 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_status_debug(t_philo philo, t_status status)
{
	pthread_mutex_lock(&philo.data->print_lock);
	printf("%ld "B_WHITE"%d "RESET, get_current_time() - philo.data->start, philo.id);
	if (status == WAIT)
		printf("is waiting\n");
	else if (status == SLEEP)
		printf("is "BLUE"sleeping\n");
	else if (status == THINK)
		printf("is "B_WHITE"thinking\n");
	else if (status == FORK)
		printf("has taken a "YELLOW"fork\n");
	else if (status == L_FORK)
		printf("has taken the "YELLOW"left fork [ID: %d]\n", philo.left_fork->id);
	else if (status == R_FORK)
		printf("has taken the "YELLOW"right fork [ID: %d]\n", philo.right_fork->id);
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
	if (!is_running(philo.data) && status != DEAD)
		return ;
	if (DEBUG)
		return (print_status_debug(philo, status));
	pthread_mutex_lock(&philo.data->print_lock);
	printf("%ld %d ", get_current_time() - philo.data->start, philo.id);
	if (status == WAIT)
		printf("is waiting\n");
	else if (status == SLEEP)
		printf("is sleeping\n");
	else if (status == THINK)
		printf("is thinking\n");
	else if (status == FORK || status == L_FORK || status == R_FORK)
		printf("has taken a fork\n");
	else if (status == EAT)
		printf("is eating\n");
	else if (status == DEAD)
		printf("died\n");
	else if (status == FULL)
		printf("is full\n");
	pthread_mutex_unlock(&philo.data->print_lock);
}

void	show_data(t_data data)
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

void	show_philos(t_data data)
{
	size_t	i;

	pthread_mutex_lock(&data.print_lock);
	sep();
	i = 0;
	while (i < data.philo_count)
	{
		printf("Philosopher ID : %d\n", data.philos[i].id);
		printf("Left fork :\t%d\n", data.philos[i].left_fork->id);
		printf("Right fork :\t\t%d\n", data.philos[i].right_fork->id);
		i++;
	}
	sep();
	pthread_mutex_unlock(&data.print_lock);
}