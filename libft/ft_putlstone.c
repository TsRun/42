/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:51:25 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/30 13:14:05 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlstone(t_list *elem)
{
	if (!elem)
		return ;
	ft_putstr("Value of this elem: ");
	write(1, elem->content, elem->content_size);
	ft_putstr(", size of this elem: ");
	ft_putnbr((int) elem->content_size);
	ft_putchar('\n');
}
