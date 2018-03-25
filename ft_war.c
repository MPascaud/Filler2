/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_war.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:19:17 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/16 17:19:33 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

void    ft_war(t_data *data, char *tmp, int war)
{
	int     i;
	int     k;

	i = 4;
	k = 0;
	data->war[war] = (char*)malloc(sizeof(char) * (data->board[1] + 1));
	while (tmp[i])
	{
		data->war[war][k] = tmp[i];
		k++;
		i++;
	}
	data->war[war][k] = '\0';
}

