/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:14:29 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/16 17:15:04 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    ft_board(t_data *data, char *tmp)
{
	int     nb;
	int     i;

	data->board = (int*)malloc(sizeof(int) * 3);
	nb = 0;
	i = 8;
	while (tmp[i] != ' ')
	{
		nb = (nb * 10) + (tmp[i] - '0');
		i++;
	}
	data->board[0] = nb;
	nb = 0;
	i++;
	while (tmp[i] != ':')
	{
		nb = (nb * 10) + (tmp[i] - '0');
		i++;
	}
	data->board[1] = nb;
	data->board[2] = '\0';
}

