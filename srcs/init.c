/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:10:04 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/03 20:21:23 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_args(int argc, char **argv)
{
	size_t	i;

	if (argc < 5 || argc > 6)
		exit_error("Wrong number of arguments", NULL);
	i = 1;
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]))
			exit_error("Non numeric argument", NULL);
		i++;
	}
}

void	init_data(t_data *data)
{
	//todo
}