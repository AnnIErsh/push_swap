/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 03:07:04 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/12 15:59:07 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str + i && *(str + i))
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ch;

	ch = s;
	while (n)
	{
		*ch++ = '\0';
		n--;
	}
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*copy;

	len = ft_strlen(s1);
	i = 0;
	copy = (char *)malloc(len + 1);
	if (copy)
	{
		while (i < len)
		{
			*(copy + i) = *(s1 + i);
			i++;
		}
		*(copy + i) = '\0';
	}
	else
		return (NULL);
	return (copy);
}

char	*ft_strchr_buff(const char *buff, int c)
{
	size_t	i;

	i = 0;
	while (buff + i && *(buff + i))
	{
		if (*(buff + i) == (char)c)
			return ((char *)buff + i);
		i++;
	}
	if (!(char)c)
		return ((char *)buff + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		*(str + i++) = *s1++;
	while (s2 && *s2)
		*(str + i++) = *s2++;
	*(str + i) = '\0';
	return (str);
}
