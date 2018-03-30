/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:07:35 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/30 15:36:54 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

int		ft_distance(t_data *data)
{
	if (data->board[0] == 100)
		return (100);
	else
		return (58);
}


void    ft_heatmap(t_data *data)
{
	int     line;
	int     i;
	int     change;
	int     heat;

	line = 0;
	i = 0;
	change = 0;
	heat = /*58*/ft_distance(data);
	if (data->war[0] == NULL || data->shapiece[0] == NULL)
		return ;
	while (/*data->war[line] != NULL*/line < data->board[0])
	{
		while (/*data->war[line][i]*/i < data->board[1])
		{
			if (data->war[line][i] == '.')
				data->war[line][i] = '0';
			if (data->war[line][i] == 'O')
				data->war[line][i] = 126;
			if (data->war[line][i] == 'X')
				data->war[line][i] = 127;
			i++;
		}
		i = 0;
		line++;
	}
	i = 0;
	line = 0;
	while (/*data->war[line] != NULL*/line < data->board[0])
	{
		while (/*data->war[line][i]*/i < data->board[1])
		{
			if (data->war[line][i] == data->opp)
			{
				change = i;
				while (change >= 0 && heat >= 0)
				{
					if (data->war[line][change] != data->me && data->war[line][change] != data->opp
							&& data->war[line][change] < heat)
					{
						data->war[line][change] = heat;
					}
					heat--;
					change--;
				}
				change = i;
				heat = /*58*/ft_distance(data);
				while (/*data->war[line][change]*/change < data->board[1] && heat >= 0)
				{
					if (data->war[line][change] != data->me && data->war[line][change] != data->opp
							&& data->war[line][change] < heat)
					{
						data->war[line][change] = heat;
					}
					heat--;
					change++;
				}
			}
			i++;
		}
		i = 0;
		heat = /*58*/ft_distance(data);
		line++;
	}
	line = 0;
	i = 0;
	heat = /*58*/ft_distance(data);
	while (/*data->war[line] != NULL*/line < data->board[0])
	{
		while (/*data->war[line][i]*/i < data->board[1])
		{
			if (data->war[line][i] == data->opp)
			{
				change = line;
				while (change >= 0 && heat >= 0)
				{
					if (data->war[change][i] != data->me && data->war[change][i] != data->opp
							&& data->war[change][i] < heat)
					{
						data->war[change][i] = heat;
					}
					heat--;
					change--;
				}
				change = line;
				heat = /*58*/ft_distance(data);
				while (change < data->board[0] && heat >= 0)
				{
					if (data->war[change][i] != data->me && data->war[change][i] != data->opp
							&& data->war[change][i] < heat)
					{
						data->war[change][i] = heat;
					}
					heat--;
					change++;
				}
			}
			i++;
			heat = /*58*/ft_distance(data);
		}
		i = 0;
		line++;
	}
}

void    ft_heatmap2(t_data *data)
{
	int     line;
	int     i;
	int     change;
	int     heat;

	line = 0;
	i = 0;
	change = 0;
	heat = /*58*/ft_distance(data);
	if (data->war[0] == NULL || data->shapiece[0] == NULL)
		return ;	
	while (/*data->war[line] != NULL*/line < data->board[0])
	{
		while (/*data->war[line][i]*/i < data->board[1])
		{
			if (data->war[line][i] > 0 && data->war[line][i] <= 120)
			{
				change = i;
				heat = data->war[line][i];
				while (change >= 0 && heat >= 0)
				{
					if (data->war[line][change] != data->me && data->war[line][change] != data->opp
							&& data->war[line][change] < heat)
					{
						data->war[line][change] = heat;
					}
					heat--;
					change--;
				}
				change = i;
				heat = data->war[line][i];
				while (/*data->war[line][change]*/change < data->board[1] && heat >= 0)
				{
					if (data->war[line][change] != data->me && data->war[line][change] != data->opp
							&& data->war[line][change] < heat)
					{
						data->war[line][change] = heat;
					}
					heat--;
					change++;
				}
			}
			i++;
		}
		i = 0;
		line++;
	}
}



void	ft_okright_01p2(int *okright, t_data *data)
{
//	int		i;
	int		line;

//	i = 0;
	line = 0;
	while (line < data->board[0])
	{
		if (/*data->war[line][data->board[1] - 1] == data->me ||*/ data->war[line][data->board[1] - 1] == data->opp)
		{
			*okright = 1;
		}
		line++;
	}
}

void	ft_okup_01p2(int *okup, t_data *data)
{
	int		i;

	i = 0;
	while (i < data->board[1])
	{
		if (/*data->war[0][i] == data->me ||*/ data->war[0][i] == data->opp)
		{
	//		dprintf(FDtest, "coucou\n");
			*okup = 1;
		}
		i++;
	}
} 

void	ft_down_01p2(int *okdown, t_data *data)
{
	int		i;

	i = 0;
	while (i < data->board[1])
	{
		if (data->war[data->board[0] - 1][i] == data->me /*|| data->war[data->board[0] - 1][i] == data->opp*/)
			*okdown = 1;
		i++;
	}
}

void	ft_okleft_01p2(int *okleft, t_data *data)
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


void    ft_heatmap_01p2(t_data *data)
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

	if (data->war[0] == NULL || data->shapiece[0] == NULL)
		return ;
	ft_okright_01p2(&okright, data);
	ft_okup_01p2(&okup, data);
	ft_down_01p2(&okdown, data);
	ft_okleft_01p2(&okleft, data);
	middle = /*(data->board[0] - 1) / 2*/16;
	heat = (data->board[0] / 1) + 8;
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
	//			else
	//				data->war[middle - j][i] -= heat2;
			}
			if (data->war[middle + j + 1][i] != data->me && data->war[middle + j + 1][i] != data->opp)
			{
				if (okleft == 0)
					data->war[middle + j + 1][i] += heat2;
	//			else
	//				data->war[middle + j + 1][i] -= heat2;
			}
			j++;
			heat2 -= 5;
		}
		i++;
		heat -= 1;
		j = 0;;
	}
	heat = data->board[0] / 1;
	middle = 11;
	i = data->board[1] - 1;
	while (heat > 0 /*&& okright == 0*/)
	{
		heat2 = heat;
		while (heat2 > 0)
		{
			if (data->war[middle - j][i] != data->me && data->war[middle - j][i] != data->opp)
			{
				if ((okup == 1 && okleft == 1) || okright == 1)
					data->war[middle - j][i] += heat2;
	//			else
	//				data->war[middle - j][i] -= heat2;
			}
			if (data->war[middle + j + 1][i] != data->me && data->war[middle + j + 1][i] != data->opp)
			{
				if (okup == 1 || okright == 1)
					data->war[middle + j + 1][i] += heat2;
	//			else
	//				data->war[middle + j + 1][i] -= heat2;
			}
			j++;
			heat2 -= 6;
		}
		i--;
		heat -= 1;
		j = 0;
	}


	middle = /*(data->board[1] - 1) / 2*/ 28;
	heat = data->board[1] / /*(4 - okdown)*/ 2;
	i = 0;
	while (heat > 0 /*&& okup == 0*/ /*&& okdown == 0*/)
	{
		heat2 = heat;
		while (heat2 > 0)
		{
			if (data->war[i][middle - j] != data->me && data->war[i][middle - j] != data->opp)
			{
				if (okup == 0)
					data->war[i][middle - j] += heat2;
	//			else 
	//				data->war[i][middle - j] -= heat2;
			}
			if (data->war[i][middle + j + 1] != data->me && data->war[i][middle + j + 1] != data->opp)
			{
				if (okup == 0)
					data->war[i][middle + j + 1] += heat2;
	//			else
	//				data->war[i][middle + j + 1] -= heat2;
			}
			j++;
			heat2 -= 3;
		}
		i++;
		heat -= 2;
		j = 0;
	}
	heat = (data->board[1] / (4 - okup));
	i = data->board[0] - 1;
//	while (heat > 0 /*&& okdown == 0*/ /*&& okup == 0*/)
//	{
//		heat2 = heat;
//		while (heat2 > 0)
//		{
//			if (data->war[i][middle - j] != data->me && data->war[i][middle - j] != data->opp)
//			{
//				if (okdown == 0)
//					data->war[i][middle - j] += heat2;
//		//		else
//		//			data->war[i][middle - j] -= heat2;
//			}
//			if (data->war[i][middle + j + 1] != data->me && data->war[i][middle + j + 1] != data->opp)
//			{
//				if (okdown == 0)
//					data->war[i][middle + j + 1] += heat2;
//		//		else
//		//			data->war[i][middle + j + 1] -= heat2;
//			}
//			j++;
//			heat2 -= 2;
//		}
//		i--;
//		heat -= 2;
//		j = 0;
//	}
}





