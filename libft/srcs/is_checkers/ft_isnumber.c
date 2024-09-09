/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:15:13 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/09 19:01:46 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isint(char *str)
{
	long	result;
	int		charge;
	size_t	i;

	if (!ft_isnumber(str))
		return (false);
	i = 0;
	if (str[i] == '-')
		charge = -1;
	else
		charge = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	result = 0;
	while (str[i])
	{
		result = (result * 10) + (str[i] - '0');
		if ((result * charge) > INT_MAX || (result * charge) < INT_MIN)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_isnumber(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
