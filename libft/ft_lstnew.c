/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:13:49 by rtorres           #+#    #+#             */
/*   Updated: 2024/05/27 13:21:00 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}
