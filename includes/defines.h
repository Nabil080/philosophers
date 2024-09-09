/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:04:03 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/09 21:26:05 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

typedef pthread_mutex_t	t_mtx;

typedef struct s_data	t_data;

typedef enum e_operation {
	CREATE,
	DESTROY,
	LOCK,
	UNLOCK,
	WAIT
}t_operation;

typedef struct s_fork{
	int		id;
	t_mtx	mutex;
}t_fork;

typedef struct s_philo{
	int			id;
	pthread_t	thread;
	t_fork		*left_fork;
	t_fork		*right_fork;
	time_t		last_meal;
	size_t		meal_count;
	bool		eating;
	bool		alive;
	t_data		*data;
}t_philo;

struct s_data{
	int			philo_count;
	int			meal_count;
	time_t		time_to_die;
	time_t		time_to_eat;
	time_t		time_to_sleep;
	time_t		start;
	bool		run_simulation;
	t_philo		*philos;
	t_fork		*forks;
	t_mtx		print_lock;
	pthread_t	supervisor;
};

#endif