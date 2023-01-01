#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*output;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	output = (char *) malloc (sizeof(char) * (size + 1));
	while (*s1)
		output[i++] = *(s1++);
	while (*s2)
		output[i++] = *(s2++);
	output[i] = '\0';
	return (output);
}

char    *get_next_line(int fd)
{
	static char	buffer[1][4];
	char			*line;
	int			i;
	int			j;
	int			flag;

	if (read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	flag = 0;
	while (!flag && (buffer[fd][0] || (read(fd, buffer[fd], 4) > 0)))
	{
		line = ft_strjoin(line, buffer[fd]);
		i = 0;
		j = 0;
		while (buffer[fd][i])
		{
			if (flag)
				buffer[fd][j++] = buffer[fd][i];
			if (buffer[fd][i] == '\n')
				flag = 1;
			buffer[fd][i++] = 0;
		}
	}
	return (line);
}
