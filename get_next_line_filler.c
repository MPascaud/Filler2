/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:26:23 by mpascaud          #+#    #+#             */
/*   Updated: 2018/01/23 18:34:45 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int		ft_ft2(char **line, char *tmp)
{
	char	*tmp2;
	int		n;
	int		i;

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
	return (n);
}

int		get_next_line(const int fd, char **line)
{
	static char		tmp[MAX_FD][BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || (read(fd, &ret, 0)) == -1)
		return (-1);
	*line = NULL;
	ret = 0;
	if (ft_ft2(line, tmp[fd]) == 1)
		return (1);
	while ((ret = read(fd, tmp[fd], BUFF_SIZE)) > 0)
	{
		tmp[fd][ret] = '\0';
		if (ft_ft2(line, tmp[fd]) == 1)
			return (1);
	}
	if (**line != '\0')
		return (1);
	return (0);
}

/*int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open (argv[1], O_RDONLY);
	if (argc == 2)
	{
		while (get_next_line(fd, &line) == 1)
		{
			write(1, line, ft_strlen(line));
			write(1, "\n", 1);
		}
		free(line);
	}
	return (0);

}
*/

int		main(int ac, char **av)
{
	char	*line;

	get_next_line(0, &line);
	write(1, line, ft_strlen(line));	
	return (0);
}

/*
int     main(int ac, char **av)
{
	    int     i;
		int     *fd;
		char    *line;

		i = 0;
		fd = ft_memalloc(ac - 1);
		while (i < ac)
		{
			(ac == 1) ? (fd[i] = 0) : (fd[i] = open(av[i + 1], O_RDONLY));
			while (get_next_line(fd[i], &line) == 1)
				printf("%s\n", line);
			close(fd[i++]);
		}
		return (0);
}*/
