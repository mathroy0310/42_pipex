/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:29:38 by maroy             #+#    #+#             */
/*   Updated: 2023/04/18 23:57:17 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int errorMessage(char *error)
{
    write(2, error, ft_strlen(error));
    return(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_pipex pipex;


	ft_printf("argc : %d", argc);
	if (argc != 5)
		return (errorMessage(ERROR_ARGC));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		return (errorMessage(ERROR_INFILE));
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0664);
	if (pipex.outfile < 0)
		return (errorMessage(ERROR_OUTFILE));
	if (pipe(pipex.end) < 0)
		return (errorMessage(ERROR_PIPE));
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
	{
		//first Child
		dup2(pipex.end[1], 1);
		close(pipex.end[0]);
		dup2(pipex.infile, 0);

		//je dois execve kekpart icitte
		
		/* Replace the current process, executing PATH with arguments ARGV and
  		 environment ENVP.  ARGV and ENVP are terminated by NULL pointers.  */
		 
		//execve(path, argv , envp);
	}
		
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
	{
		//second chilrd
		dup2(pipex.end[0], 0);
		close(pipex.end[1]);
		dup2(pipex.infile, 1);

		//je dois execve kekpart icitte

		/* Replace the current process, executing PATH with arguments ARGV and
  		 environment ENVP.  ARGV and ENVP are terminated by NULL pointers.  */
		 
		//execve(path, argv , envp);
	}
	return (EXIT_SUCCESS);
}

// int	test(int argc, char *argv[])
// {
// 	int end[2];
// 	int f1;
// 	int f2;
// 	pid_t parent;
// 	pipe(end);

// 	if (argc < 5)
// 	{
// 		ft_printf("\033[1;31m ERROR 🛑 : Must have more than 5 argc.	\033[0m");
// 		return (EXIT_FAILURE);
// 	}
// 	parent = fork();

// 	char *infile = argv[1];
// 	// char *cmd1 = argv[2];
// 	// char *cmd2 = argv[3];
// 	char *outfile = argv[4];

// 	f1 = open(infile, STDIN_FILENO);
// 	f2 = open(outfile, STDOUT_FILENO);

// 	if (parent == -1)
// 	{
// 		perror("Fork: ");
// 		return (EXIT_FAILURE);
// 	}
// 	if (!parent) // if fork() returns 0, we are in the child process
// 	{
// 		dup2(f1, STDIN_FILENO);
// 		dup2(end[1], STDOUT_FILENO);

// 		close(end[1]);
// 		close(f1);
// 		return (EXIT_FAILURE);
// 	}
// 	else
// 	{
// 		int status;
// 		waitpid(-1, &status, 0);
// 		dup2(f2, STDOUT_FILENO);
// 		dup2(end[0], STDIN_FILENO);
		
// 		close(end[0]);
// 		close(f2);
// 		return (EXIT_FAILURE);
// 	}
// 	return (EXIT_SUCCESS);
// }