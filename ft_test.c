/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:32:28 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/26 17:34:46 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "filler.h"













int         ft_test(t_data *data)
{
	int     i;
	int     j;
	int     k;
	int     l;
	int     possible;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	possible = 0;

	while (/*data->war[i] != NULL*/i < data->board[0])
	{
		while (/*data->war[i][j] != '\0'*/j < data->board[1])
		{
			while (/*data->shapiece[k] != NULL*/k < data->piece[0])
			{
				while (/*data->shapiece[k][l] != '\0'*/l < data->piece[1])
				{
					if (data->shapiece[k][l] == '*' /*&& (k + i) < data->board[0] && (l + j) < data->board[1]*/)
					{
						if ((k + i) > (data->board[0] - 1) || (l + j) > (data->board[1] - 1))
						{
							//	dprintf(FDtest, "i = %d, j = %d, k = %d, l = %d\n", i, j, k, l);	
							possible = 2;
							if (j == 0)
							{
								write (1, "0 0\n", 4);
								return (0);
							}
							break ;
						}
						if (data->war[k + i][l + j] == data->me)
						{
							possible++;
						}
						if (data->war[k + i][l + j] == data->opp)
						{
							possible = 2;
						}
					}
					l++;
				}
				l = 0;
				k++;
			}
			if (possible == 1)
			{
				//	dprintf(FDtest, "ligne = %d, case = %d\n", i, j);
				ft_putnbr(i);
				write(1, " ", 1);
				ft_putnbr(j);
				write(1, "\n", 1);
				return (1);
			}
			possible = 0;
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	write (1, "0 0\n", 4);
	//	dprintf(FDtest, "placement impossible");
	return (0);
}


int		ft_possible_heat(t_data *data)
{
	int			i;
	int			j;
	int			k;
	int			l;
	int			possible;
	int			thermometer;
	t_heater	*heater;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	possible = 0;
	thermometer = 0;
	heater = (t_heater*)malloc(sizeof(t_heater));
	heater->heat = 0;
	heater->i = 0;
	heater->j = 0;
//	ft_heatmap(data);
//	ft_heatmap2(data);
	while (/*data->war[i] != NULL*/i < data->board[0])
	{
		while (/*data->war[i][j]*/j < data->board[1])
		{
			while (/*data->shapiece[k] != NULL*/k < data->piece[0])
			{
				while (/*data->shapiece[k][l]*/l < data->piece[1])
				{
					if (data->shapiece[k][l] == '*')
					{
						if ((k + i) > (data->board[0] - 1) || (l + j) > (data->board[1] - 1))
						{
							possible = 2;
							if (j == 0)
							{
								//write(FDtest, "j = 0\n", 6);
								ft_putnbr(heater->i);
								write(1, " ", 1);
								ft_putnbr(heater->j);
								write(1, "\n", 1);
								//dprintf(FDtest, "heater->heat = %d\n", heater->heat);
								if (heater->heat > 0)
								{
									free(heater);
									return (1);
								}
								free(heater);
								return (0);
							}
							break ;
						}
						if (data->war[k + i][l + j] == data->me)
						{
							possible++;
						}
						if (data->war[k + i][l + j] == data->opp)
						{
							possible = 2;
						}
						if (thermometer < data->war[k + i][l + j] && data->war[k + i][l + j] != data->me
								&& data->war[k + i][l + j] != data->opp)
						{
						//	dprintf(FDtest, "%d\n", data->war[k + i][l + j]); 
							thermometer = data->war[k + i][l + j];
						}
					}
					l++;
				}
				l = 0;
				k++;
			}
			if (possible == 1)
			{
				if (thermometer > heater->heat /*&& heater->heat != 56 && heater->heat != 57*/)
				{
					heater->heat = thermometer;
					heater->i = i;
					heater->j = j;
					//return (1);
				}
			}
			possible = 0;
			k = 0;
			thermometer = 0;
			j++;
		}
		//thermometer = 0;
		j = 0;
		i++;
	}
	ft_putnbr(heater->i);
	write(1, " ", 1);
	ft_putnbr(heater->j);
	write(1, "\n", 1);
//	dprintf(FDtest, "heater->heat = %d\n", heater->heat);
	if (heater->heat > 0)
	{
		free(heater);
		return (1);
	}
	free(heater);
	return (0);
}

void	ft_place_heat(t_data *data)
{
	/*if (ft_possible_heat(data) == 0)
	{
		write (FDtest, "COUCOU\n", 7);
		ft_test(data);//ft_rush
	}*/
	ft_possible_heat(data);
}










