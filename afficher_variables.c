/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:23:58 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/16 18:17:28 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

void    ft_afficher_variables(t_data *data, char *tmp, int war, int shapiece)
{
	int     i;

	dprintf(FDtest, "----------------------------------------------------------------------\n");
	dprintf(FDtest, "me = %c\n", data->me);
	dprintf(FDtest, "opp = %c\n", data->opp);
	dprintf(FDtest, "tmp = %s\n", tmp);
	dprintf(FDtest, "war = %d\n", war);
	dprintf(FDtest, "shapiece = %d\n", shapiece);
	i = 0;
	while (data->board[i])
	{
		dprintf(FDtest, "data->board[%d] = %d\n", i, data->board[i]);
		i++;
	}
	dprintf(FDtest, "data->board[%d] = %d\n", i, data->board[i]);
	i = 0;
	while (data->war[i] != NULL)
	{
		dprintf(FDtest, "data->war[%d] = %s\n", i, data->war[i]);
		i++;
	}
	dprintf(FDtest, "data->war[%d] = %s\n", i, data->war[i]);
	i = 0;
	while (data->piece[i])
	{
		dprintf(FDtest, "data->piece[%d] = %d\n", i, data->piece[i]);
		i++;
	}
	dprintf(FDtest, "data->piece[%d] = %d\n", i, data->piece[i]);
	i = 0;
	while (data->shapiece[i] != NULL)
	{
		dprintf(FDtest, "data->shapiece[%d] = %s\n", i, data->shapiece[i]);
		i++;
	}
	dprintf(FDtest, "data->shapiece[%d] = %s\n", i, data->shapiece[i]);


}

