/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:15:16 by alkane            #+#    #+#             */
/*   Updated: 2022/02/21 02:00:44 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_state	*state;
	int	fd[4];
	int pid1;
	char **input;

	if (argc != 5)
		return (0);
		
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] == -1)
		return 2;
	
	if (pipe(fd + 2) == -1
		return 2;
	
	pid1 = fork()
	if (pid1 == 0)
	{
		//in child process
		"which ls grep"
		//need to get path of cmd1 exec, argv[1] is holding exec name and params
		input = ft_split(argv[1], ' ');
		execname = ft_split(argv[1], ' ')[0];
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[3], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(fd[3]);
		close(fd[4]);
		execve("PATHTHATIFIND", input, envp);
	}
	// back into parent because of execv
	return (0);
}