/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:28:10 by maroy             #+#    #+#             */
/*   Updated: 2023/06/13 17:19:37 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "utils.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <unistd.h>

# define ERROR_ARGC "\033[1;31m ERROR 🛑 : Must have 5 arguments.	\n\033[0m"
# define ERROR_INFILE "\033[1;31m ERROR 🛑 : Infile	\n\033[0m"
# define ERROR_OUTFILE "\033[1;31m ERROR 🛑 : Outfile	\n\033[0m"
# define ERROR_PIPE "\033[1;31m ERROR 🛑 : Pipe	\n\033[0m"
# define ERROR_CMD "\033[1;31m ERROR 🛑 : Command Not found	\n\033[0m"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		end[2];
	int		fd_in;
	int		fd_out;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}			t_pipex;
//pipex_child
void		first_child(t_pipex pipex, char *argv[], char *envp[]);
void		second_child(t_pipex pipex, char *argv[], char *envp[], int argc);
//
int			error_message(char *error);

void		ft_close_pipes(t_pipex *pipex);
void		ft_parent_free(t_pipex *pipex);
void		ft_child_free(t_pipex *pipex);

#endif