/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 01:35:14 by pamatya           #+#    #+#             */
/*   Updated: 2024/05/29 00:33:02 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
// #include <stdio.h>
#include "pipex.h"

extern char **environ;

// Function to execute a shell command
int main(void)
{
	// char	*argv[] = {"/bin/ls", "-l", NULL};
	char	*path;
	char	**envp;
	int		fd[2];
	
	pipe(fd);
	fd[1] = open("next_file.txt", O_WRONLY | O_CREAT, 0777);
	ft_printf("fd[1] before dup2: %d\n", fd[1]);
	dup2(fd[1], STDOUT_FILENO);
	ft_printf("fd[1] after dup2: %d\n", fd[1]);
	close(fd[0]);
	close(fd[1]);
	
	// if (argc != 2)
	// {
	// 	ft_printf("Usage: %s <command>\n", argv[0]);
	// 	return (1);
	// }
	path = getenv("PATH");
	// ft_printf("PATH: %s\n", path);
	
	envp = ft_split(path, ':');
	// while (*envp)
	// {
	// 	ft_printf("%s\n", *envp);
	// 	envp++;
	// }
	
	
	// Execute the command "ls -l"
	// execve("/bin/ls", (char *[]){"ls", "-la", NULL}, envp);
	execve("/bin/ls", (char *[]){"ls", NULL}, environ);
	ft_printf("Error: This should not be printed...\n");	
	return (0);
}