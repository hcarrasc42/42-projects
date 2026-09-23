/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:09:13 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/10/04 12:37:53 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

typedef struct s_path
{
	pid_t	pid;
	int		fd[2];
	char	**paths;
	char	*path;
	char	**cmd;
}		t_path;

//------UTILS-------//
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//---PIPEX_ACCESS---//
char	**get_cmd(char **argv);
char	**get_path(char **env);
char	*cmd_path(char **paths, char **cmd);

//---PIPEX_FORK----//
void	child_proces(char **argv, char **env, t_path man);
void	parent_proces(char **argv, char **env, t_path man);

//---PIPEX_SPLIT---//
char	**ft_split(char const *s, char c);

/*	^___^
	(o o)\___________
	(___)\           )\/\
		||--------W |
		||         || 
*/
#endif