/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:25:32 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/25 00:41:24 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

int     ft_ft2(char **line, char *tmp)
{
	char    *tmp2;
	int     n;
	int     i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			break ;
		i++;
	}
	n = 1;
	if (tmp[i] != '\n')
		n = 0;
	tmp2 = ft_strnew(ft_strlen(*line) + i);
	ft_strcpy(tmp2, *line);
	ft_strncat(tmp2, tmp, i);
	ft_strcpy(tmp, &tmp[i + n]);
	free(*line);
	*line = tmp2;
//	free(tmp2);//<------------------
	return (n);
}


int     get_next_line(const int fd, char **line)
{
	static char     tmp[MAX_FD][BUFF_SIZE + 1];
	int             ret;

	if (fd < 0 || !line || (read(fd, &ret, 0)) == -1)
	{
//		free(tmp[fd]);//<<---------------
	//	free(*line);
		return (-1);
	}
	*line = NULL;
	ret = 0;
	if (ft_ft2(line, tmp[fd]) == 1)
	{
//		free(*line);
//		free(tmp[fd]);//<<--------------
		return (1);
	}
	while ((ret = read(fd, tmp[fd], BUFF_SIZE)) > 0)
	{
		tmp[fd][ret] = '\0';
		if (ft_ft2(line, tmp[fd]) == 1)
		{
	//		free(*line);//<<<<<-----
		//	free(tmp[fd]);//<<--------------
			return (1);
		}
	}
	if (**line != '\0')
	{
	//	free(*line);//<<<<---
//		free(tmp[fd]);//<<<<------------------
		return (1);
	}
//	free(*line);
//	free(tmp[fd]);//<<------------------
//	free(tmp[MAX_FD]);//<<<<---
	return (0);
}

