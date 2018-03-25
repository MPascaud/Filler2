/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_possible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:56:37 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/24 22:15:23 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"


//2ndchance
//possible2nd
//si possible == 1, placer, sinon 0


int			ft_2ndplace(t_data *data, t_move *move)
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
	while (data->war[i] != NULL)
	{
		while (data->war[i][j])
		{
			while (data->shapiece[k] != NULL)
			{
				while (data->shapiece[k][l])
				{
					if (data->shapiece[k][l] == '*')
					{
						if ((k + i) > (data->board[0] - 1) || (l + j) > (data->board[1] - 1))
						{
							possible = 2;
							if (j == 0)
								return (0);
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
				ft_putnbr(i - move->verti);
				write(1, " ", 1);
				ft_putnbr(j - move->hori);
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
	return (0);
}



int			ft_2ndchance(t_data *data)
{
	t_move		*move;
	int			i;
	int			j;

	
	move = (t_move*)malloc(sizeof(t_move));
	move->hori = data->piece[1] - 1;
	move->verti = data->piece[0] - 1;
	i = 0;
	j = 0;
	while (i < data->piece[0])
	{
		while (data->shapiece[i][j])
		{
			if (data->shapiece[i][j] == '*' && j <= move->hori)
			{
				move->hori = j;
			}
			if (data->shapiece[i][j] == '*' && i<= move->verti)
			{
				move->verti = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
//	dprintf(FDtest, "move->hori = %d\n", move->hori);
//	dprintf(FDtest, "move->verti = %d\n", move->verti);
	i = 0;
	j = 0;
	while ((i + move->verti) < data->piece[0])
	{
		while (data->shapiece[i + move->verti][j + move->hori])
		{
			data->shapiece[i][j] = data->shapiece[i + move->verti][j + move->hori];
			j++;
		}
		while (data->shapiece[i][j])
		{
			data->shapiece[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
	i = 0;
	while (data->shapiece[i] != NULL)
	{
		dprintf(FDtest, "nouveau data->shapiece[%d] = %s\n", i, data->shapiece[i]);
		i++;
	}
	if (ft_possible(data) == 1)
	{
		ft_2ndplace(data, move);
		free(move);
	//	dprintf(FDtest, "COUCOU\n");
		return (1);
	}
	free(move);
	return (0);
}


int         ft_possible(t_data *data)
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
	while (data->war[i] != NULL)
	{
		while (data->war[i][j])
		{
			while (data->shapiece[k] != NULL)
			{
				while (data->shapiece[k][l])
				{
					if (data->shapiece[k][l] == '*')
					{
						if ((k + i) > (data->board[0] - 1) || (l + j) > (data->board[1] - 1))
						{
							possible = 2;
							if (j == 0)
								return (0);
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
				return (1);
			}
			possible = 0;
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

