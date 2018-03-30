/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:18:01 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/30 16:21:42 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"


void	ft_hot(t_data *data)
{
	if (data->board[1] == 0)
		return ;
	ft_heatmap(data);
	ft_heatmap2(data);
	if (data->board[1] == 40 && (data->me == 'X' || data->me == 127))
	{
	//	dprintf(FDtest, "COUCOU\n");
		ft_heatmap_01p2(data);
	}
	if (data->board[1] == 17 && (data->me == 'X' || data->me == 127))
	{

	//	dprintf(FDtest, "COUCOU\n");
		ft_heatmap_00p2(data);
	}

}







