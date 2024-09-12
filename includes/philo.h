/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:37:08 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/12 17:35:56 by nbellila         ###   ########.fr       */
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
/*main*/
void	free_data(t_data *data);
void	exit_error(char *str, t_data *data);
/*printer*/
void	print_status(t_philo philo, t_status status);
void	show_data(t_data data);
void	show_philos(t_data data);
/*utils*/
time_t	get_current_time(void);
void	wait_threads(t_data data);
void	ft_usleep(time_t time);
bool	get_bool(t_mtx *mutex, bool *var);
void	set_bool(t_mtx *mutex, bool *var, bool res);
t_time	get_ulong(t_mtx *mutex, t_time *var);
void	set_ulong(t_mtx *mutex, t_time *var, t_time res);
/*dinner*/
bool	is_running(t_data *data);
void	*routine(void *args);
void	*supervise(void *args);

#endif