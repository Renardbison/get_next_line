#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#define BUFFER_SIZE 4

int ft_verify(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++; //Faire attention sur cette partie car
	   		  //l adresse peut changer vue aue ce n est pas une copie par value
	}
	return (0);
}

char *get_next_line(int fd)
{
	char	*buf;	
	int		ret;
	static char	*save;
	char *output;
		
	tmp = NULL;
	buf = NULL;
	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	if (buf = malloc(sizeof(char * ) * BUFFER_SIZE + 1) == NULL)
		return NULL;
	if (!ft_verify(save) && ret != 0)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		save = my_join(save, buf);
		free(buf);
	}
	return (save);

}

int main()
{
	int fd;
	fd = open(0, O_RDONLY);
	
   if (fd == -1)
	   return 1;
   return (get_next_line(fd));

}
