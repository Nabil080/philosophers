/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:12:45 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/09 19:02:15 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	if (data->philos)
		free_2d((void *)data->philos, 0);
	if (data->forks)
		free_2d((void *)data->forks, 0);
}

void	exit_error(char *str, t_data *data)
{
	ft_putendl_fd(str, 2);
	if (data)
		free_data(data);
	exit(EXIT_FAILURE);
}
