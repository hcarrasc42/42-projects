/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:32:11 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/10/04 09:13:24 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//Get_Paths se encarga de meter el path en un array y agregarle "/" al final
char	**get_path(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	paths = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			paths = ft_split(env[i] + 5, ':');
		}
		i++;
	}
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	return (paths);
}

//Get_cmd se encarga de recoger el argv y de ahí sacar el argumento
char	**get_cmd(char **argv)
{
	int		i;
	char	**cmd;

	i = 0;
	cmd = ft_split(*argv, ' ');
	return (cmd);
}

//Cmd_Path se en carga de juntar paths con cmd
char	*cmd_path(char **paths, char **cmd)
{
	int		i;
	char	*temp;
	char	*pathall;

	i = 0;
	temp = NULL;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], *cmd);
		if (access(temp, F_OK) == 0)
			pathall = temp;
		else
			free(temp);
		i++;
	}
	return (pathall);
}
