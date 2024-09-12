/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:37:08 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/12 21:00:08 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*threads / mutex*/
# include <pthread.h>
/*usleep*/
# include <unistd.h>
/*printf*/
# include <stdio.h>
/* malloc / free*/
# include <stdlib.h>
/*structs / defines*/
# include "defines.h"
/*init*/
void	check_args(int argc, char **argv);
void	init_data(t_data *data, int argc, char **argv);
void	init_philos(t_data *data);
void	init_forks(t_data *data);
/*dinner*/
void	*routine(void *args);
void	*supervise(void *args);
/*clean exit*/
void	free_data(t_data *data);
void	exit_error(char *str, t_data *data);
void	wait_threads(t_data *data);
/*utils*/
time_t	get_current_time(void);
void	ft_usleep(time_t time);
time_t	get_philo_relative_lastmeal(t_philo *philo);
void	print_status(t_philo philo, t_status status);
/*getters*/
bool	get_bool(t_mtx *mutex, bool *var);
void	set_bool(t_mtx *mutex, bool *var, bool res);
t_time	get_ulong(t_mtx *mutex, t_time *var);
void	set_ulong(t_mtx *mutex, t_time *var, t_time res);
bool	is_running(t_data *data);
/*libft*/
bool	ft_isint(char *str);
long	ft_atol(const char *nptr);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
bool	ft_isnumber(char *str);

#endif