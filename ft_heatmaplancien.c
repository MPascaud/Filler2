/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:07:35 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/22 19:02:59 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"



void	ft_convert(t_data **data, int *line, int *i)
{
	while ((*data)->war[*line][*i])
	{
		if ((*data)->war[*line][*i] == '.')
			(*data)->war[*line][*i] = '0';
		if ((*data)->war[*line][*i] == 'O')
			(*data)->war[*line][*i] = 126;
		if ((*data)->war[*line][*i] == 'X')
			(*data)->war[*line][*i] = 127;
		(*i)++;
	}
	*i = 0;
	(*line)++;
}









/*
void	ft_horizontal
*/

void	ft_horizontal(t_data **data, int *line, int *change, int *heat)
{
	int		i;

	i = 0;
	while ((*data)->war[*line][i++])
		if ((*data)->war[*line][i] == (*data)->opp)
		{
			*change = i;
			while (*change >= 0 && *heat >= 0)
			{
				if ((*data)->war[*line][*change] != (*data)->me && (*data)->war[*line][*change] != (*data)->opp
						&& (*data)->war[*line][*change] < *heat)
				(*data)->war[*line][*change] = *heat;
				(*heat)--;
				(*change)--;
			}
			*change = i;
			*heat = 58;
			while ((*data)->war[*line][*change] && *heat >= 0)
			{
				if ((*data)->war[*line][*change] != (*data)->me && (*data)->war[*line][*change] != (*data)->opp
						&& (*data)->war[*line][*change] < *heat)
					(*data)->war[*line][*change] = *heat;
				(*heat)--;
				(*change)++;
			}
		}
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
	heat = 58;
	while (data->war[line] != NULL)
		ft_convert(&data, &line, &i);
	line = 0;
	while (data->war[line] != NULL)
	{
		ft_horizontal(&data, &line, &change, &heat);
		i = 0;
		heat = 58;
		line++;
	}
	line = 0;
	i = 0;
	heat = 58;
	while (data->war[line] != NULL)
	{
		while (data->war[line][i])
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
				heat = 58;
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
			heat = 58;
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
	heat = 58;
	while (data->war[line] != NULL)
	{
		while (data->war[line][i])
		{
			if (data->war[line][i] > 0 && data->war[line][i] <= 10)
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
				while (data->war[line][change] && heat >= 0)
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
//gauche droite haut bas
void	ft_heatmap3(t_data *data)
{
	int		heat;
	int		middle;
	int		i;
	int		j;
	int		heat2;

	middle = (data->board[0] - 1) / 2;
	heat = data->board[0] / 2;
	i = 0;
	j = 0;
	while (heat > 0)
	{
		heat2 = heat;
		while (heat2 > 0)
		{
			if (data->war[middle - j][i] != data->me && data->war[middle - j][i] != data->opp)
				data->war[middle - j][i] += heat2;
			if (data->war[middle + j + 1][i] != data->me && data->war[middle + j + 1][i] != data->opp)
				data->war[middle + j + 1][i] += heat2;
			j++;
			heat2 -= 300;
		}
		i++;
		heat -= 1;
		j = 0;;
	}
	heat = data->board[0] / 2;
	i = data->board[1] - 1;
	while (heat > 0)
	{
		heat2 = heat;
		while (heat2 > 0)
		{
			if (data->war[middle - j][i] != data->me && data->war[middle - j][i] != data->opp)
				data->war[middle - j][i] += heat2;
			if (data->war[middle + j + 1][i] != data->me && data->war[middle + j + 1][i] != data->opp)
				data->war[middle + j + 1][i] += heat2;
			j++;
			heat2 -= 300;
		}
		i--;
		heat -= 1;
		j = 0;
	}


	middle = (data->board[1] - 1) / 2;
	heat = data->board[1] / 2;
	i = 0;
	while (heat > 0)
	{
		heat2 = heat;
		while (heat2 > 0)
		{
			if (data->war[i][middle - j] != data->me && data->war[i][middle - j] != data->opp)
				data->war[i][middle - j] -= heat2;
			if (data->war[i][middle + j + 1] != data->me && data->war[i][middle + j + 1] != data->opp)
				data->war[i][middle + j + 1] += heat2;
			j++;
			heat2 -= 1;
		}
		i++;
		heat--;
		j = 0;
	}
	heat = data->board[1] / 2;
	i = data->board[0] - 1;
	while (heat > 0)
	{
		heat2 = heat;
		while (heat2 > 0)
		{
			if (data->war[i][middle - j] != data->me && data->war[i][middle - j] != data->opp)
				data->war[i][middle - j] += heat2;
			if (data->war[i][middle + j + 1] != data->me && data->war[i][middle + j + 1] != data->opp)
				data->war[i][middle + j + 1] += heat2;
			j++;
			heat2 -= 1;		
		}
		i--;
		heat--;
		j = 0;
	}
}


void	ft_heatmap_main(t_data **data)
{
	ft_heatmap(*data);
	ft_heatmap2(*data);
//	ft_heatmap3(*data);
}






