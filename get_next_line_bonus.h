/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:20:23 by mpihur            #+#    #+#             */
/*   Updated: 2023/11/20 18:48:23 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdlib.h>

/*utils*/
short	ft_strchr_n(char *s);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);

/*in main file*/
char	*ft_buff_left(char *l_buff);
char	*ft_copy_line(char *l_buff);
char	*ft_read(int fd, char *l_buff);
char	*get_next_line(int fd);

#endif
