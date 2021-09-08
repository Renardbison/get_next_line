/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 03:10:44 by lnyamets          #+#    #+#             */
/*   Updated: 2021/09/08 19:12:59 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **ag)
{
	int	fd;
	char	*tt;

	fd = 0;
	if (ac >= 2)
		fd = open(ag[1], O_RDONLY);
	printf("%s",(tt = get_next_line(fd)));
	while(tt)
	{
		free(tt);
		printf("%s",(tt = get_next_line(fd)));
	}
	if (tt)
		free(tt);
  	system("leaks a.out");
	return (1);
}
