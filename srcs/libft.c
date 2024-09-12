/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:41:27 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/12 20:48:36 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

long	ft_atol(const char *nptr)
{
	long	result;
	int		charge;
	size_t	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	charge = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			charge *= -1;
		i++;
	}
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * charge);
}

int	ft_atoi(const char *nptr)
{
	long	result;
	int		charge;
	size_t	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	charge = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			charge *= -1;
		i++;
	}
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * charge);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	char	*ptr;
	size_t	area;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	area = nmemb * size;
	tab = malloc(area);
	if (!tab)
		return (NULL);
	ptr = (char *)tab;
	while (area-- > 0)
		*ptr++ = 0;
	return (tab);
}

bool	ft_isnumber(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}
