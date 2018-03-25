/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:26:13 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/08 16:26:30 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

char    *ft_strstr(const char *haystack, const char *needle)
{
	int     i;
	int     j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
	{
		return ((char*)haystack);
	}
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
			{
				return ((char*)(haystack + i));
			}
			j++;
		}
		i++;
	}
	return (0);
}

