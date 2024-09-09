/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:36:12 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/09 19:24:12 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	check_args(argc, argv);
	init_data(&data, argc, argv);
	show_data(data);
	show_philos(data);
	wait_threads(data);
	free_data(&data);
	return (0);
}
