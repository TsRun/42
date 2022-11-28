/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:14:09 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/19 00:07:40 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_error(char *file_name, int i, char *name)
{
	ft_puterror(name);
	if (i == 0)
		ft_puterror(": cannot open \'");
	else if (i == 1)
		ft_puterror(": error reading \'");
	ft_puterror(basename(file_name));
	if (i == 0)
		ft_puterror("\' for reading: ");
	else if (i == 1)
		ft_puterror("\': ");
	if (i != 2)
		ft_puterror(strerror(errno));
	ft_puterror("\n");
	return (0);
}

t_list	*ft_error2(t_list *list, int n, char *str, char *name)
{
	ft_puterror(name);
	if (n == 0)
	{
		ft_puterror(": option requires an argument -- ‘c’\n");
		return (0);
	}
	ft_puterror(": invalid number of bytes: ‘");
	ft_puterror(basename(str));
	ft_puterror("’");
	if (n == 2)
		ft_puterror(": Value too large for defined data type");
	ft_puterror("\n");
	free(list);
	return (0);
}
