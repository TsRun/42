/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:14:09 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/21 00:08:14 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_put_error(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	ft_error(char *file_name, int i, char *name)
{
	ft_puterror(name + 2);
	if (i == 1)
		ft_puterror(": ");
	else if (i == 0)
		ft_puterror(": ");
	if (file_name[0] != 0)
		ft_puterror(basename(file_name));
	if (i == 1)
		ft_puterror(": ");
	else if (i == 0)
		ft_puterror(": ");
	if (i != 2)
		ft_puterror(strerror(errno));
	ft_puterror("\n");
	return (-1);
}

t_list	*ft_error2(t_list *list, int n, char *str, char *name)
{
	ft_puterror(name + 2);
	if (n == 0)
	{
		ft_puterror(": invalid option -- '");
		write(2, str, 1);
		ft_puterror("'\n");
		return (0);
	}
	ft_puterror(": invalid number of bytes: ‘");
	ft_puterror(basename(str));
	ft_puterror("’\n");
	free(list);
	return (0);
}
