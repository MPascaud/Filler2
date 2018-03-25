/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shapiece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:21:20 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/16 17:21:55 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

void    ft_shapiece(t_data *data, char *tmp, int shapiece)
{
	int     i;
	int     k;

	i = 0;
	k = 0;
	data->shapiece[shapiece] = (char*)malloc(sizeof(char) * (data->piece[1] + 1));
	while (tmp[i])
	{
		data->shapiece[shapiece][k] = tmp[i];
		k++;
		i++;
	}
	data->shapiece[shapiece][k] = '\0';
}

