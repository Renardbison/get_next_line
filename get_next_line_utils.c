/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 01:22:18 by lnyamets          #+#    #+#             */
/*   Updated: 2021/09/08 03:09:46 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_verify(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char	*my_join(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	len1_2;
	char	*ret;

	if (!s1)
		len1 = 0;
	else
		len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	len1_2 = len1 + len2 + 1;
	ret = malloc(sizeof(char) * len1_2);
	if (!ret)
		return (NULL);
	ft_memmove(ret, s1, len1);
	ft_memmove(ret + len1, s2, len2);
	ret[len1_2 - 1] = '\0';
	free(s1);
	return (ret);
}
