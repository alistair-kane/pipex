/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:36:49 by alistair          #+#    #+#             */
/*   Updated: 2022/03/09 18:24:11 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*input_to_limiter(char *end_text)
{
	char	*line;
	int		fd;
	
	end_text = ft_strjoin(end_text, "\n");
	fd = open("temp", O_RDWR | O_CREAT, 0644);
	while (1)
	{
		write(0, "> ", 2);
		line = get_next_line(0);
		if (line == NULL || !ft_strncmp(end_text, line, ft_strlen(end_text)))
			break ;
		write(fd, line, ft_strlen(line));
	}
	return ("temp");
}
