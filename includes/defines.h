/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:04:03 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/09 18:42:41 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

typedef pthread_mutex_t t_mtx;

typedef enum e_operation {
	CREATE,
	DESTROY,
	LOCK,
	UNLOCK
}t_operation;

typedef struct s_fork{
	int		id;
	t_mtx	mutex;
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
	t_fork		*forks;
}t_data;

#endif