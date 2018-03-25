/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 14:09:45 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/25 00:21:45 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE /*15*//*1*/300
# define MAX_FD 4865

# define FDtest open("/dev/ttys000", O_RDWR)

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

int     get_next_line(const int fd, char **line);
char    *ft_strstr(const char *haystack, const char *needle);
int		get_next_line(const int fd, char **line);
size_t      ft_strlen(const char *s);
char    *ft_strncat(char *dest, const char *src, size_t n);
char    *ft_strnew(size_t size);
char    *ft_strcpy(char *dest, const char *src);

typedef struct	s_data
{
	int		me;
	int		opp;
	int		*board;
	char	**war;
	int		*piece;
	char	**shapiece;
}				t_data;
typedef struct	s_heater
{
	int		heat;
	int		i;
	int		j;
}				t_heater;
typedef struct	s_move
{
	int		hori;
	int		verti;
}				t_move;
int		ft_possible(t_data *data);
void    ft_heatmap(t_data *data);
void    ft_heatmap2(t_data *data);
void    ft_heatmap_01p2(t_data *data);
void    ft_heatmap_00p2(t_data *data);
void	ft_board(t_data *data, char *tmp);
void    ft_piece(t_data *data, char *tmp);
void    ft_war(t_data *data, char *tmp, int war);
void    ft_shapiece(t_data *data, char *tmp, int shapiece);
void    ft_afficher_variables(t_data *data, char *tmp, int war, int shapiece);
void    ft_putchar(char c);
void    ft_putnbr(int nb);

int		ft_test(t_data *data);
void	ft_place_heat(t_data *data);	
void	ft_hot(t_data *data);
void	ft_heatmap_01p2(t_data *data);
int		ft_2ndchance(t_data *data);

#endif
