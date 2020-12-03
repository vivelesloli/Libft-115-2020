/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:07:52 by cnavone           #+#    #+#             */
/*   Updated: 2020/12/03 05:58:01 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		result;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' ||
			str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - '0';
	}
	result *= sign;
	return (result);
#include "get_next_line.h"

/*
** This function appends a single line into our line variable. We do this by
** finding the length of the line. If at index len, the character is a newline,
** we save the string into line up to the length found. Then we readjust the
** stored data (**s) by creating a temporary string that stored the rest of data
** after the newline. We free the stored data to update it to the current
** address because we already append a line from it. This is done by freeing *s
** and setting it equal to the temporary string that stored the remaining data.
** At any point when we reach the end of the file, we free the memory used to
** track our location in *s because it is not needed anymore.
*/

static int	appendline(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

/*
** This is a helper function created to output the results after all the other
** cases are taken care of in get_next_line. For example, if ret is less than 0,
** then return -1 since an error occurred. If the reading is completed, return a
** 0. Else, go to appendline function to return 1 and save the line read at the
** current address of the static variable stored.
*/

static int	output(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	else
		return (appendline(&s[fd], line));
}

/*
** The get_next_line function reads a file and returns the line ending with a
** newline character from a file descriptor. A static variable is used, so that
** whenever get_next_line is called, it remembers the previous function call.
** When get_next_line is first called, we check to see if our static variable
** **s is empty. If it is, we allocate memory for it using our buff string.
** In the loop, we will continue to read more of the line and join them together
** using a temporary string. This temporary string will replace the stored data
** each iteration so that we can keep track of how much is read and delete
** the previous stored data. This is needed because we are only reading so many
** n-bytes at a time decided by our BUFF_SIZE. If we read at each iteration
** without freeing memory, then we would have memory leaks. The loop breaks when
** a newline is encountered. Finally, we call output function to check what
** should be returned.
*/

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*s[FD_SIZE];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (output(s, line, ret, fd));
}

#include "get_next_line.h"

int   main(int ac, char **av)
{
  char  *line;
  int   fd1;
  int   fd2;

  fd1 = open(av[1], O_RDONLY);
  fd2 = open(av[2], O_RDONLY);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  return (0);
}}
#include "get_next_line.h"

//cette fonction, si tu mets mode = 0; ça compte la position du premier \n dans la string
//si y'en a pas, ça renvoie -1;
//
//en mode = 1; c'est juste un strlen

int				has_n(char *str, int mode)
{
	int i;

	i = 0;
	if (mode == 0)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			return (i);
		return (-1);
	}
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

// un strjoin qui free la chaine initiale

char			*join_and_free(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;
	char	*tmp;

	tmp = s1;
	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (has_n(s1, 1) + has_n(s2, 1) + 1));
	if (res == 0)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(tmp);
	return (res);
}

//si t'as une chaine de caractere aaaaaaaaaa\nbbbb;
//ça va metre un \0 a la place du n, donc la chaine sera aaaaaaaa
//et les bbbbb seront mis dans le reste

void			set_zero_and_remains(char *line, char *remains)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		line[i] = 0;
		i++;
		while (line[j + i])
		{
			remains[j] = line[i + j];
			j++;
		}
	}
	remains[j] = 0;
}

int				init_and_error(int fd, char **line, char *buffer)
{
	if (line == NULL || BUFFER_SIZE <= 0 || fd <= -1 || fd >= 255)
		return (-1);
	if (!(*line = malloc(sizeof(char) * 1)))
		return (-1);
	*line[0] = 0;
	buffer[0] = 0;
	return (0);
}

//en gros : on vérifie avec le != 42 si c'est le premier appel pour ce buffer la; la valeur 42 est arbitraire
//si c'est le premier call on initie les trucs comme il faut'
//
// pour l'algo, on strjoin la line avec le reste, puis on join la line avec ce qu'on lit dans le fichier tant que y'a pas de \n dedans
// a la fin, on met le 0 dans la line au premier \n trouvé, et ce qui suit ce premier \n est mis dans le reste.
// si y'avait un \n dans la line, faut renvoyer 1 (d'ou le k =)

int				get_next_line(int fd, char **line)
{
	static char		remains[256][BUFFER_SIZE + 2];
	char			buffer[BUFFER_SIZE + 1];
	int				i;
	int				k;

	if (init_and_error(fd, line, buffer) == -1)
		return (-1);
	if (remains[fd][BUFFER_SIZE + 1] != 42)
	{
		remains[fd][0] = 0;
		remains[fd][BUFFER_SIZE + 1] = 42;
	}
	else
		*line = join_and_free(*line, remains[fd]);
	while ((has_n(*line, 0) == -1) && (i = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[i] = 0;
		*line = join_and_free(*line, buffer);
	}
	k = has_n(*line, 0);
	set_zero_and_remains(*line, remains[fd]);
	if (k == -1 || fd == -1 || i == -1)
		remains[fd][BUFFER_SIZE + 1] = 0;
	return ((i == -1 || fd == -1) ? -1 : k != -1);
}
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_RDONLY);
	char *line;
	int k = 1;
	int j = 1;

	while (k > 0)
	{
		k = get_next_line(fd1, &line);
		printf("%s\n", line);
		if (k >= 0)
		{
			free(line);
			line = NULL;
		}
	}
	while (j > 0 )
	{
		j = get_next_line(fd2, &line);
		printf("%s\n", line);
		if (j >= 0)
		{
			free(line);
			line = NULL;
		}
	}

    return (argc + argv[0][0]);
}