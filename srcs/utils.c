/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:50:01 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/13 01:52:50 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(t_data *data, time_t time_in_ms)
{
	time_t	start;
	time_t	remaining;

	start = get_current_time();
	remaining = time_in_ms;
	while (is_running(data) && remaining > 10)
	{
		usleep(10 * 1000);
		remaining = time_in_ms - (get_current_time() - start);
	}
	while (is_running(data) && remaining > 0)
	{
		usleep(10);
		remaining = time_in_ms - (get_current_time() - start);
	}
}

time_t	get_philo_relative_lastmeal(t_philo *philo)
{
	time_t	last_meal;
	time_t	now;
	time_t	start;

	last_meal = get_ulong(&philo->mutex, &philo->last_meal);
	now = get_current_time();
	start = philo->data->start;
	return (now - start - last_meal);
}

static void	print_status_debug(t_philo philo, t_status status)
{
	pthread_mutex_lock(&philo.data->print_lock);
	printf("%ld "B_WHITE"%d "RESET,
		get_current_time() - philo.data->start, philo.id);
	if (status == WAIT)
		printf("is waiting\n");
	else if (status == SLEEP)
		printf("is "BLUE"sleeping\n");
	else if (status == THINK)
		printf("is "B_WHITE"thinking\n");
	else if (status == FORK)
		printf("has taken a "YELLOW"fork\n");
	else if (status == L_FORK)
		printf("has taken the "YELLOW"left fork [ID: %d][%p]\n",
			philo.left_fork->id, &philo.left_fork->mutex);
	else if (status == R_FORK)
		printf("has taken the "YELLOW"right fork [ID: %d][%p]\n",
			philo.right_fork->id, &philo.right_fork->mutex);
	else if (status == EAT)
		printf("is "GREEN"eating\n");
	else if (status == DEAD)
		printf(RED"died\n");
	else if (status == FULL)
		printf(GREEN"is full !!!! Congrats\n");
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
	if (status == SLEEP)
		printf("is sleeping\n");
	else if (status == THINK)
		printf("is thinking\n");
	else if (status == FORK || status == L_FORK || status == R_FORK)
		printf("has taken a fork\n");
	else if (status == EAT)
		printf("is eating\n");
	else if (status == DEAD)
		printf("died\n");
	pthread_mutex_unlock(&philo.data->print_lock);
}
