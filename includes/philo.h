/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:37:08 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/11 19:02:57 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*libs*/
# include "libft.h"
# include <pthread.h>
# include <sys/time.h>
/*structs*/
# include "defines.h"

/*init*/
void	check_args(int argc, char **argv);
void	init_data(t_data *data, int argc, char **argv);
void	init_philos(t_data *data);
void	init_forks(t_data *data);
/*errors*/
void	free_data(t_data *data);
void	exit_error(char *str, t_data *data);
/*utils*/
time_t	get_current_time(void);
void	wait_threads(t_data data);
void	ft_usleep(time_t time);
bool	get_bool(t_mtx *mutex, bool *var);
void	set_bool(t_mtx *mutex, bool *var, bool res);
long	get_long(t_mtx *mutex, long *var);
void	set_long(t_mtx *mutex, long *var, long res);
/*dinner*/
bool	is_running(t_data *data);
void	*routine(void *args);
void	*supervise(void *args);

#endif