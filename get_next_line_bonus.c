/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:52:22 by mpihur            #+#    #+#             */
/*   Updated: 2023/11/20 21:19:19 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_buff_left(char *l_buff)
{
	char	*r;
	size_t	i;
	size_t	j;

	i = 0;
	while (l_buff[i] && l_buff[i] != '\n')
		i++;
	if (!l_buff[i])
	{
		free (l_buff);
		return (NULL);
	}
	r = (char *)malloc(ft_strlen(l_buff) - i + 1);
	if (r == NULL)
		return (NULL);
	i++;
	j = 0;
	while (l_buff[i])
		r[j++] = l_buff[i++];
	r[j] = '\0';
	free(l_buff);
	return (r);
}

char	*ft_copy_line(char *l_buff)
{
	int		i;
	char	*res;

	i = 0;
	if (!l_buff[i])
		return (NULL);
	while (l_buff[i] != '\n' && l_buff[i])
		i++;
	res = (char *)malloc(i + 2);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (l_buff[i] != '\n' && l_buff[i])
	{
		res[i] = l_buff[i];
		i++;
	}
	if (l_buff[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_read(int fd, char *l_buff)
{
	int		read_res;
	char	*buff;

	read_res = 1;
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	while (read_res > 0 && !ft_strchr_n(l_buff))
	{
		read_res = read(fd, buff, BUFFER_SIZE);
		if (read_res < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[read_res] = '\0';
		l_buff = ft_strjoin_gnl(l_buff, buff);
	}
	free(buff);
	return (l_buff);
}

char	*get_next_line(int fd)
{
	static char	*large_b[1024];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (!ft_strchr_n(large_b[fd]))
		large_b[fd] = ft_read(fd, large_b[fd]);
	if (large_b[fd] == NULL)
		return (NULL);
	res = ft_copy_line(large_b[fd]);
	large_b[fd] = ft_buff_left(large_b[fd]);
	return (res);
}
/*
#include <fcntl.h>
#include <stdio.h>

int     main(void)
{
        int     fd;
        int     fd2;
        int     fd3;
        char    *res;
        unsigned int    i;

        i = 0;
        fd = open("file.txt", O_RDONLY);
        fd2 = open("file2.txt", O_RDONLY);
        fd3 = open("f3.txt", O_RDONLY);
        if (fd < 0 || fd2 < 0)
                return (0);
        while (i < 14)
        {
                if (i % 2 == 0)
                        res = get_next_line(fd2);
                else if (i % 3 == 0)
                        res = get_next_line(fd3);
                else
                        res = get_next_line(fd);
                if (res == NULL)
                        printf("NULL\n");
                printf("** %s*\n", res);
                i++;
        }
        free(res);
        return (0);
}*/
