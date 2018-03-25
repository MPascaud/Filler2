/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:07:35 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/24 21:54:12 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"


void	ft_okright_00p2(int *okright, t_data *data)
{
//	int		i;
	int		line;

//	i = 0;
	line = 0;
	while (line < data->board[0])
	{
		if (data->war[line][data->board[1] - 1] == data->me /*|| data->war[line][data->board[1] - 1] == data->opp*/)
		{
			*okright = 1;
		}
		line++;
	}
}

void	ft_okup_00p2(int *okup, t_data *data)
{
	int		i;

	i = 0;
	while (i < data->board[1])
	{
		if (data->war[0][i] == data->me /*|| data->war[0][i] == data->opp*/)
		{
	//		dprintf(FDtest, "coucou\n");
			*okup = 1;
		}
		i++;
	}
} 

void	ft_down_00p2(int *okdown, t_data *data)
{
	int		i;

	i = 0;
	while (i < data->board[1])
	{
		if (/*data->war[data->board[0] - 1][i] == data->me ||*/ data->war[data->board[0] - 1][i] == data->opp)
			*okdown = 1;
		i++;
	}
}

void	ft_okleft_00p2(int *okleft, t_data *data)
{
	int		line;

	line = 0;
	while (line < data->board[0])
	{
		if (data->war[line][0] == data->me /*|| data->war[line][0] == data->opp*/)
			*okleft = 1;
		line++;
	}
}


void    ft_heatmap_00p2(t_data *data)
{
	int     heat;
	int     middle;
	int     i;
	int     j;
	int     heat2;
	int		okleft;
	int		okright;
	int		okup;
	int		okdown;

	okleft = 0;
	okright = 0;
	okup = 0;
	okdown = 0;

	ft_okright_00p2(&okright, data);
	ft_okup_00p2(&okup, data);
	ft_down_00p2(&okdown, data);
	ft_okleft_00p2(&okleft, data);
	middle = /*(data->board[0] - 1) / 2*/7;
	heat = (data->board[0] / 1);
	i = 0;
	j = 0;
	while (heat > 0 /*&& okleft == 0*/)
	{
		heat2 = heat;
		while (heat2 > 0)
		{
			if (data->war[middle - j][i] != data->me && data->war[middle - j][i] != data->opp)
			{
				if (okleft == 0)
					data->war[middle - j][i] += heat2;
		//		if (okup == 0)
		//			data->war[middle - j][i] -= heat2;
			}
			if (data->war[middle + j + 1][i] != data->me && data->war[middle + j + 1][i] != data->opp)
			{
				if (okleft == 0)
					data->war[middle + j + 1][i] += heat2;
	//			if (okup == 0)
	//				data->war[middle + j + 1][i] -= heat2;
			}
			j++;
			heat2 -= 4;
		}
		i++;
		heat -= 1;
		j = 0;;
	}
	middle = 13;
	heat = data->board[0] / 2;
	i = data->board[1] - 1;
	while (heat > 0 /*&& okright == 0*/)
	{
		heat2 = heat;
		while (heat2 > 0)
		{
			if (data->war[middle - j][i] != data->me && data->war[middle - j][i] != data->opp)
			{
			//	if (okright == 0)
			//		data->war[middle - j][i] += heat2;
				if (okup == 0 || okleft == 0)
					data->war[middle - j][i] -= heat2;
			}
	//		if (data->war[middle + j + 1][i] != data->me && data->war[middle + j + 1][i] != data->opp)
	//		{
	//			if (okright == 0)
	//				data->war[middle + j + 1][i] += heat2;
		//		if (okup == 0)
		//			data->war[middle + j + 1][i] -= heat2;
	//		}
			j++;
			heat2 -= 3;
		}
		i--;
		heat -= 1;
		j = 0;
	}


	middle = /*(data->board[1] - 1) / 2*/16;
	heat = (data->board[1] / 2) + 17;
	i = 0;
	while (heat > 0 /*&& okup == 0*/ /*&& okdown == 0*/)
	{
		heat2 = heat;
		while (heat2 > 0)
		{
			if (data->war[i][middle - j] != data->me && data->war[i][middle - j] != data->opp)
			{
				if (okup == 0 && okdown == 0 && okleft == 0)
					data->war[i][middle - j] += heat2;
	//			else 
	//				data->war[i][middle - j] -= heat2;
			}
//			if (data->war[i][middle + j + 1] != data->me && data->war[i][middle + j + 1] != data->opp)
//			{
//				if (okup == 0)
//					data->war[i][middle + j + 1] += heat2;
//	//			else
//	//				data->war[i][middle + j + 1] -= heat2;
//			}
			j++;
			heat2 -= 3;
		}
		i++;
		heat -= 2;
		j = 0;
	}
	middle = 8;
	heat = /*(data->board[1] / 2)*/27;
	i = data->board[0] - 1;
	while (heat > 0 /*&& okdown == 0*/ /*&& okup == 0*/)
	{
		heat2 = heat;
		while (heat2 > 0)
		{
			if (data->war[i][middle - j] != data->me && data->war[i][middle - j] != data->opp)
			{
		//		if (okdown == 0)
		//			data->war[i][middle - j] += heat2;
				if (okup == 0)
					data->war[i][middle - j] -= heat2;
			}
			if (data->war[i][middle + j + 1] != data->me && data->war[i][middle + j + 1] != data->opp)
			{
	//			if (okdown == 0)
	//				data->war[i][middle + j + 1] += heat2;
				if (okup == 0)
					data->war[i][middle + j + 1] -= heat2;
			}
			j++;
			heat2 -= 6;
		}
		i--;
		heat -= 2;
		j = 0;
	}
}





