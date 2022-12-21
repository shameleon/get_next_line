/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:39:45 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/20 08:20:57 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	src_len;
	unsigned int	sub_len;
	char			*sub;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	sub_len = len;
	if (start + len > src_len)
		sub_len = src_len - start;
	if (start > src_len)
		sub_len = 0;
	sub = (char *)malloc (sizeof(*sub) * (sub_len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	unsigned int	len;
	unsigned int	i;
	char			*dst;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc (sizeof(*dst) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		dst[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	dst[len] = '\0';
	free (s1);
	free (s2);
	return (dst);
}
