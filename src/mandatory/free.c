/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:32:25 by maroy             #+#    #+#             */
/*   Updated: 2023/06/13 17:02:10 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	ft_close_pipes(t_pipex *pipex)
{
	close(pipex->end[0]);
	close(pipex->end[1]);
}

void	ft_parent_free(t_pipex *pipex)
{
	int	i;

	i = -1;
	//close(pipex->fd_in);
	//close(pipex->fd_out);
	while (pipex->cmd_paths[++i])
		free(pipex->cmd_paths[i]);
	free(pipex->cmd_paths);
}

void	ft_child_free(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->cmd_args[++i])
		free(pipex->cmd_args[i]);
	free(pipex->cmd_args);
}
