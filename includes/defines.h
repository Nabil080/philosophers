/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:04:03 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/03 20:58:22 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

typedef pthread_mutex_t mtx;

typedef struct s_fork{
	int		id;
	mtx		mutex;
}t_fork;

typedef struct s_philo{
	pthread_t	thread;
	int			id;
	time_t		last_meal;
	size_t		meal_count;
	bool		eating;
	bool		alive;
}t_philo;

typedef struct s_data{
	int			philo_count;
	int			meal_count;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	t_philo		*philos;
}t_data;

#endif