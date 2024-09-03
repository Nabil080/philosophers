/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:12:45 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/03 20:20:39 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_data(t_data *data)
{
	//todo
}

void	exit_error(char *str, t_data *data)
{
	ft_putendl_fd(str, 2);
	if (data)
		free_data(data);
	exit(EXIT_FAILURE);
}