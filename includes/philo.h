/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:37:08 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/09 21:39:34 by nbellila         ###   ########.fr       */
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
/*errors*/
void	free_data(t_data *data);
void	exit_error(char *str, t_data *data);
/*utils*/
time_t	get_current_time(void);
void	wait_threads(t_data data);
int		mutex_operation(t_mtx *mutex, t_operation operation);
int		thread_operation(t_philo *philo, t_operation operation);
void	ft_usleep(time_t time);
/*dinner*/
void	*routine(void *args);
void	*supervise(void *args);

#endif