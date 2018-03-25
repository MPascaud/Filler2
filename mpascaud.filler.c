/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mpascaud.filler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:38:30 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/25 01:47:53 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





#include "filler.h"



void	ft_free(t_data **data, int *war, int *shapiece)
{
	int		i;

	i = 0;
	(*war) = 0;
	(*shapiece) = 0;
	free((*data)->board);
	while ((*data)->war[i])
	{
		free((*data)->war[i]);
		i++;
	}
	free((*data)->war[i]);
//	i++;
//	free((*data)->war[i]);
	free((*data)->war);
	free((*data)->piece);
	i = 0;
	while ((*data)->shapiece[i])
	{
		free((*data)->shapiece[i]);
		i++;
	}
	free((*data)->shapiece[i]);
//	i++;
//	free((*data)->shapiece[i]);
	free((*data)->shapiece);
}

int		main(void)
{
	char	*tmp;
	t_data	*data;
	int		war;
	int		shapiece;
//	int		impossible;

	war = 0;
	shapiece = 0;
//	impossible = 0;
	data = (t_data*)malloc(sizeof(t_data));
	while (1)
	{
		while (get_next_line(0, &tmp))
		{
		//	/*if (tmp[0] == '=' ||*/ tmp == NULL/*ajout anti leaks et seg*/)//si on ne peut plus poser
		//	{
				//write (1, "0 0\n", 4);
				//free data
				//break ;
		//		return (0);
		//	}
		//	if (tmp[0] == '\0')
		//		return(0);
			if (ft_strstr(tmp, "mpascaud"))
			{
				if (tmp[10] == '1')
				{
			//		data->me = 'O';
			//		data->opp = 'X';
					data->me = 126;
					data->opp = 127;
				}
				else
				{
			//		data->me = 'X';
			//		data->opp = 'O';
					data->me = 127;
					data->opp = 126;
				}
			}
			if (ft_strstr(tmp, "Plateau"))
			{
				ft_board(data, tmp);
			}
			if (tmp[0] >= 48 && tmp[0] <= 57)
			{
				if (war == 0)
				{
					data->war = (char**)malloc(sizeof(char*) * (data->board[0] + 1));
				}
				ft_war(data, tmp, war);
				war++;
				if (war == data->board[0] /*|| tmp == NULL*//*rajout segfault*/)
				{
				//	data->war[war] = (char*)malloc(sizeof(char));//<<<<<<<<--------
					data->war[war] = NULL;
				//	while (1);//<<<<-----------
				}
			}
			if (ft_strstr(tmp, "Piece"))
			{
			//	while (1);
				ft_piece(data, tmp);
			}
			if (tmp[0] == '.' || tmp[0] == '*')
			{
				if (shapiece == 0)
				{
					data->shapiece = (char**)malloc(sizeof(char*) * (data->piece[0] + 1));
				}
				ft_shapiece(data, tmp, shapiece);
				shapiece++;
				if (shapiece == data->piece[0] /*|| tmp == NULL*//*2e rajout segfault*/)
				{
					//data->shapiece[shapiece] = (char*)malloc(sizeof(char));//<<<<--------
					data->shapiece[shapiece] = NULL;
					//	write(1, "0 0\n", 4);
					//write(1, "8 2\n", 4);
					//	write(1, "12 14\n", 6);
			//		free(tmp);
			//		tmp = NULL;
					break ;
				}
			}
			//if (ft_possible(data) == 0)
			//	break ;
		//	if (impossible == 1)
		//		break ;
			free(tmp);
			tmp = NULL;
		//	while (1);
		}
//		free(tmp);
//		ft_free(&data, &war, &shapiece);
//		free(data);
//		while (1);
		ft_hot(data);
	//	ft_heatmap(data);
	//	ft_heatmap2(data);
	//	ft_heatmap3(data);
		ft_afficher_variables(data, tmp, war, shapiece);
	//	ft_possible(data);
	/*	if (ft_possible(data) == 0)
		{
		//	write(FDtest, "pad place\n", 10);
		//	write(1, "0 0\n", 4);
		//	impossible = 1;
			//break ;
			return (0);
		}*/
		if (ft_possible(data) == 1)
		{
			ft_place_heat(data);//if possible == 1
		         	           //if possible == 0 && possible2 == 1
		}
		if (data->board[0] != 15)
			if (ft_possible(data) == 0 && ft_2ndchance(data) == 0) //&& ft_possible2 == 0
			{
	
			//	ft_2ndchance(data);
				ft_free(&data, &war, &shapiece);
				free(tmp);
				free(data);
				write(FDtest, "placement impossible\n", 21);
				write (1, "0 0\n", 4);
				return (0);
			}
		if (data->board[0] == 15)
		{
			if (ft_possible(data) == 0)
			{
				ft_free(&data, &war, &shapiece);
				free(tmp);
				free(data);
				write(FDtest, "placement impossible\n", 21);
				write (1, "0 0\n", 4);
				return (0);
			}
		}
	//	free(tmp);
	//	ft_free(&data, &war, &shapiece);
//		if (ft_test(data) == 0)
//			return (0);
//	ft_test(data);			
//		sleep(1);
//		if (tmp[0] == '=')
//			break ;
	//	if (tmp == NULL || tmp[0] == '\0')
	//		break ;
	//	if (tmp != NULL)
	//	{
		//	free(tmp);
		//	tmp = NULL;
	//	}
	//	if (tmp == NULL)//<<-------------------------------
	//		break ;
	//	if (impossible == 1)
	//	{
			//write(1, "0 0\n", 4);
	//		ft_free(&data, &war, &shapiece);
	//		break ;
	//	}
		ft_free(&data, &war, &shapiece);
	//	free(tmp);
	//	free(data);
	//	while(1);
	//	while (1);
	}
	free(data);
	free(tmp);
	return (0);
}
