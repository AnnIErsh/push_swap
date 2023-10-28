/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 03:07:15 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/12 16:03:17 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	dealloc_buff_and_set_new_value(char **buff, char *new_value)
{
	char	*old;

	if (!*buff)
		*buff = ft_strdup("");
	old = *buff;
	if (new_value)
		*buff = new_value;
	free(old);
}

static void	find_line_in_saved_buff(char **line, char **saved_buff)
{
	char	*p_end;

	p_end = ft_strchr_buff(*saved_buff, '\n');
	if (p_end)
	{
		*p_end = '\0';
		*line = ft_strjoin(*saved_buff, "\n");
		dealloc_buff_and_set_new_value(saved_buff, ft_strdup(p_end + 1));
		if (!**saved_buff)
		{
			free(*saved_buff);
			*saved_buff = NULL;
		}
		return ;
	}
	*line = ft_strdup(*saved_buff);
	free(*saved_buff);
	*saved_buff = NULL;
}

static void	read_and_fill(int fd, char **saved_buff, char *buff, int *n_bytes)
{
	ft_bzero(buff, BUFFER_SIZE + 1);
	*n_bytes = read(fd, buff, BUFFER_SIZE);
	if (*n_bytes == -1 || !buff)
	{
		free(*saved_buff);
		*saved_buff = NULL;
		return ;
	}
	if (!*n_bytes)
		return ;
	*(buff + *n_bytes) = '\0';
	dealloc_buff_and_set_new_value(saved_buff, ft_strjoin(*saved_buff, buff));
}

char	*get_next_line(int fd)
{
	static char	*saved_buff;
	char		*buff;
	char		*line;
	int			n_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	n_bytes = 1;
	buff = (char *)malloc(BUFFER_SIZE + 1);
	while (!ft_strchr_buff(saved_buff, '\n') && n_bytes)
	{
		if (n_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		read_and_fill(fd, &saved_buff, buff, &n_bytes);
	}
	free(buff);
	if (!ft_strlen(saved_buff))
		return (NULL);
	find_line_in_saved_buff(&line, &saved_buff);
	return (line);
}

/*
#include <stdio.h>
int main()
{
    int fd;
    char *filename = "file1";
    fd = open(filename, O_RDONLY);
    char *str;

    for (int i = 0; i < 20; i++)
    {
        str = get_next_line(fd);
        printf("%d: %s", i, str);
		free(str);
    }
    return (0);
}
*/