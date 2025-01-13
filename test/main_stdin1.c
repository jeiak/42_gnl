/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:07:38 by jesssanc          #+#    #+#             */
/*   Updated: 2025/01/10 10:24:46 by jesssanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h>

int	main(void)
{
	//int		fd;
	char	*line;

	//fd = open("test.txt", O_RDONLY);
	//if (fd == -1)
	//{
	//	perror("Error");
	//	return (1);
	//}
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		printf("Linea: %s", line);
		free(line);
	}
	//close(fd);
	return (0);
} 
//  cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 main_fd.c get_next_line.c get_next_line_utils.c get_next_line.h //