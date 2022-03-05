/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:15:16 by alkane            #+#    #+#             */
/*   Updated: 2022/03/05 02:06:25 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>
#include <sys/wait.h>

static void	free_double(char **dp, int i)
{
	while (dp[++i])
		free(dp[i]);
	free(dp);
}

static char	*return_path(char **paths, char *execname)
{
	int		i;
	char	*temp;
	char	*path;

	i = -1;
	while (paths[++i] != NULL)
	{
		if (i == 0)
			ft_memmove(paths[i], paths[i] + 5, ft_strlen(paths[i] + 5));
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, execname);
		free(temp);
		if (!access(path, X_OK))
			return (path);
		free(path);
	}
	return (NULL);
}

static char	*seek_path(char *execname)
{
	extern char	**environ;
	char		**paths;

	while (*environ != NULL)
	{
		if (!ft_strncmp(*environ, "PATH", 4))
		{
			paths = ft_split(*environ, ':');
			if (return_path(paths, execname))
				return (return_path(paths, execname));
			free_double(paths, -1);
		}
		environ++;
	}
	free(execname);
	return (NULL);
}

int	exec_cmd(char *argv)
{
	extern char	**environ;
	char		**input;
	char		*path;

	input = ft_split(argv, ' ');
	path = seek_path(input[0]);
	if (!path)
	{
		free_double(input, 0);
		return (2);
	}
	execve(path, input, environ);
	return (0);
}

void	piping(char *argv)
{	
	int			pid;
	int			fd[2];

	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid > 0)
	{	
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		exec_cmd(argv);
		close(fd[1]);
	}
}

int	main(int argc, char **argv)
{
	int			i;
	int			fd[2];
	
	if (argc >= 5)
	{
		if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
		{
			
			fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
			i = 2;
			return (0);
		}
		else if (argc >= 5)
		{
			fd[0] = open(argv[1], O_RDONLY);
			fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd[0] == -1)
				return 2;
			i = 1;
		}
		dup2(fd[0], STDIN_FILENO);
		while (++i < argc - 2)
			piping(argv[i]);
		dup2(fd[1], STDOUT_FILENO);
		if (exec_cmd(argv[i]))
			return 2;
		close(fd[0]);
		close(fd[1]);
	}
	return (0);
}
