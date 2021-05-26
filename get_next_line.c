/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:29:49 by cgangaro          #+#    #+#             */
/*   Updated: 2021/02/01 15:24:28 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int		verif(char **line, char **buff_mem)
{
	char	*temp;

	if (*buff_mem && ft_strchr(*buff_mem, 10) != NULL)
	{
		if (!(*line = ft_strncpy(*buff_mem, '\n')))
			return (-1);
		if (!(temp = ft_substr(*buff_mem, '\n')))
			return (-1);
		*buff_mem = temp;
		return (1);
	}
	else if (*buff_mem == NULL)
	{
		if (!(*buff_mem = ft_zero(NULL, 1)))
			return (-1);
	}
	return (0);
}

int		get_next_line(int fd, char **line, int buffer_size)
{
	char		buff_temp[buffer_size + 1];
	static char	*buff_mem;
	int			retread;
	int			v;

	if ((v = verif(line, &buff_mem)))
		return (v);
	if (v == -1)
		return (-1);
	while ((retread = read(fd, buff_temp, buffer_size)) != 0)
	{
		if (retread == -1)
			return (-1);
		buff_temp[retread] = '\0';
		if (!(buff_mem = ft_strjoin(buff_mem, buff_temp)))
			return (-1);
		if ((v = verif(line, &buff_mem)))
			return (1);
		if (v == -1)
			return (-1);
	}
	*line = buff_mem;
	buff_mem = NULL;
	return (0);
}
