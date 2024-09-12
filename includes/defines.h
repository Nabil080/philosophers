/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:04:03 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/12 19:26:28 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define DEBUG	1

# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define WHITE "\033[0;37m"
# define B_WHITE "\033[1;37m"
# define RESET "\033[0m"

typedef pthread_mutex_t	t_mtx;

typedef uint64_t		t_time;

typedef struct s_data	t_data;

typedef enum e_status {
	EAT,
	SLEEP,
	THINK,
	DIE,
	L_FORK,
	R_FORK,
	FORK,
	FULL,
	DEAD,
	WAIT
}t_status;

typedef enum e_timecode {
	SECONDS,
	MILLISECONDS,
	MICROSECONDS
}t_timecode;

typedef struct s_fork{
	int		id;
	t_mtx	mutex;
}t_fork;

typedef struct s_philo{
	int			id;
	pthread_t	th;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_time		last_meal;
	size_t		meal_count;
	bool		eating;
	bool		alive;
	t_mtx		mutex;
	t_data		*data;
}t_philo;

struct s_data{
	int			philo_count;
	int			meal_count;
	t_time		time_to_die;
	t_time		time_to_eat;
	t_time		time_to_sleep;
	t_time		start;
	t_time		running_threads_count;
	bool		run_simulation;
	bool		synchro;
	t_philo		*philos;
	t_fork		*forks;
	t_mtx		print_lock;
	t_mtx		read_lock;
	pthread_t	supervisor;
};

#endif
