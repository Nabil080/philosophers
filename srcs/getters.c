/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:23:30 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/11 19:53:04 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_bool(t_mtx *mutex, bool *var)
{
	bool	res;

	pthread_mutex_lock(mutex);
	res = *var;
	pthread_mutex_unlock(mutex);
	return (res);
}

void	set_bool(t_mtx *mutex, bool *var, bool res)
{
	pthread_mutex_lock(mutex);
	*var = res;
	pthread_mutex_unlock(mutex);
}

t_time	get_ulong(t_mtx *mutex, t_time *var)
{
	t_time	res;

	pthread_mutex_lock(mutex);
	res = *var;
	pthread_mutex_unlock(mutex);
	return (res);
}

void	set_ulong(t_mtx *mutex, t_time *var, t_time res)
{
	pthread_mutex_lock(mutex);
	*var = res;
	pthread_mutex_unlock(mutex);
}

bool	is_running(t_data *data)
{
	return (get_bool(&data->read_lock, &data->run_simulation));
}
