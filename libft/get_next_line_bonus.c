/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:33:57 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/07 16:50:35 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_and_save(int fd, char *buffer, char *save)
{
	char	*temp;
	int		bytes;

	while (save && !ft_strchr(save, '\n'))
	{
		bytes = read(fd, buffer, 0xFF);
		if (bytes == -1)
		{
			free(save);
			return (NULL);
		}
		else if (bytes == 0)
			return (save);
		buffer[bytes] = '\0';
		temp = save;
		save = ft_strjoin(temp, buffer);
		free(temp);
	}
	return (save);
}

static char	*get_line(char *save)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!save || !*save)
		return (NULL);
	while (save[i] != '\n' && save[i])
		i++;
	if (save[i] == '\n')
		i++;
	line = ft_substr(save, 0, i);
	return (line);
}

static char	*get_new_save(char *save)
{
	char	*new_save;
	size_t	i;

	i = 0;
	while (save && save[i] != '\n' && save[i])
		i++;
	if (save && save[i] == '\n')
		new_save = ft_strdup(&save[i + 1]);
	else
		new_save = NULL;
	free(save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save[512];
	char		*buffer;
	char		*line;

	if (fd < 0 || fd > 256)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * 0xFF);
	if (!buffer)
		return (NULL);
	if (!save[fd])
		save[fd] = ft_strdup("");
	save[fd] = read_and_save(fd, buffer, save[fd]);
	line = get_line(save[fd]);
	save[fd] = get_new_save(save[fd]);
	free(buffer);
	return (line);
}
