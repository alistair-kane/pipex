/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:15:16 by alkane            #+#    #+#             */
/*   Updated: 2022/02/21 16:39:10 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>

static char	*return_path(char **envp, char *execname)
{
	char	**paths;
	char	*path;
	int		i;
	
	while (*envp != NULL)
	{
		if (!ft_strncmp(*envp, "PATH", 4))
		{
			paths = ft_split(*envp, ':');
			i = 0;
			while (paths[i] != NULL)
			{
				if (i == 0)
					paths[i] = paths[i] + 5;
				path = ft_strjoin(paths[i], "/");
				path = ft_strjoin(path, execname);
				// printf("exec: %s\n",path);
				if (!access(path, X_OK))
					return (path);
				i++;
			}
		}
		envp++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	t_state	*state;
	int		fd[4];
	int		pid1;
	char	**input;
	char	*path;
	char	*execname;
	// if (argc != 5)
	// 	return (0);
		
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] == -1)
		return 2;
	
	if (pipe(fd + 2) == -1)
		return 2;

	pid1 = fork();
	if (pid1 == 0)
	{		
		// in child process
		// need to get path of cmd1 exec, argv[1] is holding exec name and params
		input = ft_split(argv[2], ' ');
		execname = ft_split(argv[2], ' ')[0];
		path = return_path(envp, execname);
		if (!path)
			return 2;
		printf("Here: %s", path);
		dup2(fd[0], STDIN_FILENO);
		// dup2(fd[3], STDOUT_FILENO);
		// close(fd[0]);
		// close(fd[1]);
		// close(fd[3]);
		// close(fd[4]);
		// execve(path, input, envp);
	}
	// back into parent because of execv
	return (0);
}