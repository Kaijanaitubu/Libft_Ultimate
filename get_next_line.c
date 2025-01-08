/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tubu <tubu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:00:00 by kmogami           #+#    #+#             */
/*   Updated: 2025/01/08 15:55:33 by tubu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ult.h"

char	*ft_free(char **str)
{
	if (*str != 0)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*create_line(char **str)
{
	char	*line;
	char	*tmp;
	ssize_t	lb;

	lb = 0;
	while ((*str)[lb] && (*str)[lb] != '\n')
		lb++;
	if ((*str)[lb] == '\0')
	{
		line = ft_strdup(*str);
		ft_free(str);
		return (line);
	}
	line = (char *)malloc(sizeof(char) * (lb + 2));
	if (!line)
		return (ft_free(str));
	ft_strlcpy(line, *str, lb + 2);
	tmp = ft_strdup(*str + lb + 1);
	if (!tmp)
		return (ft_free(str), ft_free(&line));
	ft_free(str);
	*str = tmp;
	return (line);
}

char	*read_line(int fd, char **str)
{
	ssize_t	rd_size;
	char	*old_str;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (!ft_strchr(*str, '\n'))
	{
		rd_size = read(fd, buf, BUFFER_SIZE);
		if (rd_size == -1)
			return (ft_free(&buf));
		else if (rd_size == 0)
			break ;
		buf[rd_size] = 0;
		old_str = *str;
		*str = ft_strjoin(old_str, buf);
		ft_free(&old_str);
		if (*str == NULL)
			return (ft_free(&buf));
	}
	ft_free(&buf);
	return (create_line(str));
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (str == NULL)
		str = ft_strdup("");
	if (str == NULL)
		return (NULL);
	line = read_line(fd, &str);
	if (line == NULL || *line == '\0')
		return (ft_free(&line), ft_free(&str));
	return (line);
}
