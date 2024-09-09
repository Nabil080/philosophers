/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:31:27 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/09 19:04:03 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sep(void)
{
	ft_putstr("---------------\n");
}

void	ft_putstr(const char *s)
{
	ft_putstr_fd(s, 1);
}

int	ft_putstr_fd(const char *s, int fd)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}
