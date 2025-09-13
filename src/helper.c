/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <rtorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:01:45 by rtorres           #+#    #+#             */
/*   Updated: 2024/08/06 17:03:07 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_img(void *mlx_ptr, void **img)
{
	if (*img)
	{
		mlx_destroy_image(mlx_ptr, *img);
		*img = NULL;
	}
}
