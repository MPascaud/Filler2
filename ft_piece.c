/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:16:25 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/25 01:26:15 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    ft_piece(t_data *data, char *tmp)
{
	int     nb;
	int     i;

	data->piece = (int*)malloc(sizeof(int) * 3);//<<<------------------
	nb = 0;
	i = 6;
	while (tmp[i] != ' ')
	{
		nb = (nb * 10) + (tmp[i] - '0');
		i++;
	}
	data->piece[0] = nb;
	nb = 0;
	i++;
	while (tmp[i] != ':')
	{
		nb = (nb * 10) + (tmp[i] - '0');
		i++;
	}
	data->piece[1] = nb;
	data->piece[2] = '\0';
}

