/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:37:08 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/03 20:20:15 by nbellila         ###   ########.fr       */
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
void	init_data(t_data *data);
/*errors*/
void	exit_error(char *str, t_data *data);

#endif