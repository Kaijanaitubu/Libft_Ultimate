/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tubu <tubu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:59:52 by kmogami           #+#    #+#             */
/*   Updated: 2025/01/08 15:55:33 by tubu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ult.h"

ssize_t	ft_strcnt(const char *s)
{
	ssize_t	i;

	i = 0;
	if (s == 0)
		return (-1);
	if (s[0] == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strcnt(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	len1;
	size_t	len2;

	len1 = ft_strcnt(s1);
	len2 = ft_strcnt(s2);
	cat = (char *)malloc((len1 + len2 + 1));
	if (cat == NULL)
		return (NULL);
	ft_strlcpy(cat, s1, len1 + 1);
	ft_strlcpy(cat + len1, s2, len2 + 1);
	return (cat);
}

char	*ft_strdup(const char *s1)
{
	long long	src_len;
	long long	idx;	
	char		*p;

	idx = 0;
	src_len = ft_strcnt(s1);
	p = (char *)malloc(sizeof(char) * (src_len + 1));
	if (p == 0)
		return (0);
	while (s1[idx])
	{
		p[idx] = s1[idx];
		idx++;
	}
	p[idx] = 0;
	return (p);
}
