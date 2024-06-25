/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:20:42 by pamatya           #+#    #+#             */
/*   Updated: 2024/06/25 20:19:53 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	// Check if the number of arguments to be accepted is this
	if (argc != 5)
		return (write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40), 1);
	data.argC = argc;
	data.argV = argv;
	data.env_vars = envp;
	data.paths = get_paths(envp);
	if (!data.paths)
		return (write(2, "Couldn't get paths\n", 19), 2);
	data.cmd1.str = ft_split(argv[2], ' ');
	if (!data.cmd1.str)
		return (ft_free2D(data.paths) , write(2, "Couldn't split cmd1\n", 19), 2);
	data.bin_path1 = get_binary_path(data.cmd1.str[0], data.paths);
	if (!data.bin_path1)
		return (ft_free2D(data.paths), ft_free2D(data.cmd1.str), write(2, "Couldn't get binary path\n", 25), 2);
	// data.cmd2 = malloc(sizeof(t_str_list));
	data.cmd2.str = ft_split(argv[3], ' ');
	if (!data.cmd2.str)
		return (ft_free2D(data.paths), ft_free2D(data.cmd1.str), free(data.bin_path1), write(2, "Couldn't split cmd2\n", 19), 2);
	// cmd2 = ft_parse(cmd2);
	data.bin_path2 = get_binary_path(data.cmd2.str[0], data.paths);
	if (!data.bin_path2)
		return (ft_free2D(data.paths), ft_free2D(data.cmd1.str), free(data.bin_path1), ft_free2D(data.cmd2.str), write(2, "Couldn't get binary path\n", 25), 2);
	pipe(data.pipe_fd);
	// data.pipe_fd[0]	-	read end
	// data.pipe_fd[1]	-	write end
	initialize_children(&data);
	return (0);
}
