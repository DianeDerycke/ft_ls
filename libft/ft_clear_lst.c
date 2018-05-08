/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 22:16:59 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/03/23 22:21:12 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_lst(t_dblist *lst)
{
   t_elem		*tmp;
   t_elem 		*elem;

   tmp = NULL;
   elem = lst->first;
   while(elem)
   {
     tmp = elem;
     elem = elem->next;
     free(tmp);
   }
   lst->first = NULL;
   lst->last = NULL;
}