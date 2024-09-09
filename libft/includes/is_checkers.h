/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_checkers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:15:15 by nbellila          #+#    #+#             */
/*   Updated: 2024/09/09 18:22:12 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_CHECKERS_H
# define IS_CHECKERS_H

int		ft_isalpha(int c);

int		ft_isspace(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);	

bool	ft_isnumber(char *str);	

bool	ft_isint(char *str);

int		ft_isascii(int c);

int		ft_isprint(int c);

int		isabovemid(t_list *to_find, t_list *lst);

int		ft_isspace(int c);

#endif