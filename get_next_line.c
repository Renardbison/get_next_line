/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:37:56 by lnyamets          #+#    #+#             */
/*   Updated: 2021/09/09 00:41:00 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

void	netoyer_save(char **pp, int i)
{
	char	*new_str;
	int		j;

	if (!(*pp)[i])
	{
		free(*pp);
		*pp = NULL;
		return ;
	}
	new_str = (char *)malloc(sizeof(char *) * (ft_strlen((*pp)) - i + 1));
	if (!new_str)
		return ;
	j = i + 1;
	i = 0;
	while ((*pp)[j])
		new_str[i++] = (*pp)[j++];
	new_str[i] = '\0';
	free((*pp));
	*pp = new_str;
	if (!ft_strlen(*pp))
	{
		free(*pp);
		*pp = NULL;
	}
	return ;
}

char	*return_line(char **pp)
{
	char	*line;
	char	*bac;
	int		i;
	int		j;

	bac = *pp;
	if (!bac)
		return (NULL);
	i = 0;
	while (bac[i] && bac[i] != '\n')
		i++;
	if (bac[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = -1;
	while (++j <= i)
		line[j] = bac[j];
	if (bac[j - 1] == '\n')
		line[j] = '\0';
	netoyer_save(pp, i);
	return (line);
}

void	init_local_var(int *p_ret, char **new_line)
{
	*p_ret = 1;
	*new_line = NULL;
}

char	*get_next_line(int fd)
{
	char		*buf;	
	int			ret;
	static char	*save = NULL;
	char		*new_line;

	init_local_var(&ret, &new_line);
	buf = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buf || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_verify(save) && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if ((ret == -1 ) || (!ret && !save))
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		if (ret != 0)
			save = my_join(save, buf);
	}
	free(buf);
	new_line = return_line(&save);
	return (new_line);
}
