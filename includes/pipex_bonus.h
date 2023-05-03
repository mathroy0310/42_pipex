/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:28:10 by maroy             #+#    #+#             */
/*   Updated: 2023/04/21 18:41:52 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "utils.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <unistd.h>

# define ERROR_ARGC "\033[1;31m ERROR 🛑 : Must have 5 arguments. \n\033[0m"
# define ERROR_INFILE "\033[1;31m ERROR 🛑 : Infile	\n\033[0m"
# define ERROR_OUTFILE "\033[1;31m ERROR 🛑 : Outfile	\n\033[0m"
# define ERROR_PIPE "\033[1;31m ERROR 🛑 : Pipe	\n\033[0m"
# define ERROR_CMD "\033[1;31m ERROR 🛑 : Command Not found	\n\033[0m"

typedef struct s_pipex
{
	pid_t	pid;
	int		*pipe;
	int		fd_in;
	int		fd_out;
	int		cmd_nbs;
	int		pipe_nbs;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}			t_pipex;

int	is_here_doc_in_args(char *arg, t_pipex *pipex);

#endif