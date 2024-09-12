/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:37:08 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/12 20:48:57 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*libs*/
# include <pthread.h>
# include <sys/time.h>
/*usleep/printf*/
# include <unistd.h>
/*printf*/
# include <stdio.h>
/*
*	INT_MAX / SIZE_MAX / BOOL
*/
# include <limits.h>
# include <stdint.h>
# include <stdbool.h>
/*
*	malloc / size_t
*/
# include <stdlib.h>
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
/*utils*/
time_t	get_current_time(void);
void	wait_threads(t_data data);
void	ft_usleep(time_t time);
time_t	get_philo_relative_lastmeal(t_philo *philo);
/*getters*/
bool	get_bool(t_mtx *mutex, bool *var);
void	set_bool(t_mtx *mutex, bool *var, bool res);
t_time	get_ulong(t_mtx *mutex, t_time *var);
void	set_ulong(t_mtx *mutex, t_time *var, t_time res);
bool	is_running(t_data *data);
/*dinner*/
void	*routine(void *args);
void	*supervise(void *args);
/*libft*/
bool	ft_isint(char *str);
long	ft_atol(const char *nptr);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
bool	ft_isnumber(char *str);

#endif