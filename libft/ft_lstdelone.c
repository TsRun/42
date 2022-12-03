/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:52:54 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/03 22:00:39 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *alst, void (*del)(void *))
{
	if (!alst)
		return ;
	if (del && alst->content)
	{
		del(alst->content);
		alst->content = NULL;
	}
	if (del)
		del((void *)alst);
}
