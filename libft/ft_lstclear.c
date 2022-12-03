/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:36:26 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/03 21:44:52 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **alst, void (*del)(void *))
{
	if (!alst || !*alst)
		return ;
	ft_lstclear(&((*alst)->next), del);
	ft_lstdelone(*alst, del);
	*alst = NULL;
}
