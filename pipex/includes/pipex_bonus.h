/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:22:11 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/10/07 08:48:39 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1

typedef struct s_bonus
{
	pid_t	pid;
	int		fd[2];
	int		fdin;
	int		fdout;
	char	*path;
	char	**cmd;
}		t_bonus;

//-----Pipex_bonus-----//
int		openfile(char *filename, int mode);
char	*get_path(char *cmd, char **env);
void	exec(char *cmd, char **env);
void	redir(char *argv, char **env, t_bonus bonus);

//---Pipex_bonus_utils--//
char	**str_split(char *str, char sep);
char	*str_ndup(char *str, unsigned int n);
char	*path_join(char *path, char *bin);
int		str_ichr(char *str, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
