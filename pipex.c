/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:15:16 by alkane            #+#    #+#             */
/*   Updated: 2022/03/11 18:05:36 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_double(char **dp, int i)
{
	while (dp[++i])
		free(dp[i]);
	free(dp);
}

void	exit_error(const char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

int	file_open(const char *name, int o_flags)
{
	int	fd;
	
	fd = open(name, o_flags, 0644);
	if (fd < 0)
		exit_error(name);
	return (fd);
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

static char	*seek_path(char *execname, char **envp)
{
	// extern char	**environ;
	char		**paths;

	while (*envp != NULL)
	{
		if (!ft_strncmp(*envp, "PATH", 4))
		{
			paths = ft_split(*envp, ':');
			if (return_path(paths, execname))
				return (return_path(paths, execname));
			free_double(paths, -1);
		}
		envp++;
	}
	free(execname);
	return (NULL);
}

void	exec_cmd(char *argv, char **envp)
{
	// extern char	**environ;
	char		**input;
	char		*path;
	
	input = ft_split(argv, ' ');
	if (ft_strrchr(input[0], '/'))
		path = seek_path(ft_strrchr(input[0], '/'), envp);
	else
		path = seek_path(input[0], envp);
	if (!path)
	{
		free_double(input, 0);
		exit_error("command not found");
	}
	execve(path, input, envp);
	exit_error(path);
}

void	piping(char *argv, char **envp)
{	
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		exit_error("pipe");
	pid = fork();
	if (pid < 0)
		exit_error("fork");
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
		exec_cmd(argv, envp);
		close(fd[1]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int			i;
	int			fd[2];
	
	if (argc >= 5)
	{
		if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
		{
			fd[0] = file_open(input_to_limiter(argv[2]), O_RDONLY);
			fd[1] = file_open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND);
			i = 2;
		}
		else
		{
			fd[0] = file_open(argv[1], O_RDONLY);
			fd[1] = file_open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC);
			i = 1;
		}
		dup2(fd[0], STDIN_FILENO);
		unlink("temp");
		while (++i < argc - 2)
			piping(argv[i], envp);
		dup2(fd[1], STDOUT_FILENO);
		exec_cmd(argv[i], envp);
		close(fd[0]);
		close(fd[1]);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
