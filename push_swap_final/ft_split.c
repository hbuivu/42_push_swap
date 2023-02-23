/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:07:06 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/14 11:22:17 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	j = 0;
	while (src[j])
		j++;
	return (j);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	while (i <= len)
	{
		if (s[i] == (char)c)
			break ;
		i++;
	}
	if (i > len)
		return (NULL);
	return ((char *)s + i);
}

static int	num_strs(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
		i++;
	}
	return (count + 1);
}

static char	*cpystr(char const *s, char c)
{
	char	*buffer;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	buffer = ft_calloc(i + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s, i + 1);
	return (buffer);
}

char	**ft_split(char const *s, char c, t_nlist **head)
{
	char	**buffer;
	int		i;
	int		strs;

	if (!s)
		return (NULL);
	strs = num_strs(s, c);
	buffer = (char **)ft_calloc(strs, sizeof(char *));
	if (!buffer)
		exit_on_malloc_error(head, buffer);
	i = 0;
	while (i < strs - 1)
	{
		while (*s == c)
			s++;
		buffer[i] = cpystr(s, c);
		if (!buffer[i])
			exit_on_malloc_error(head, buffer);
		i++;
		s = ft_strchr(s, c);
	}
	buffer[i] = NULL;
	return (buffer);
}
