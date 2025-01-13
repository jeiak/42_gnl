/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:16:10 by jesssanc          #+#    #+#             */
/*   Updated: 2025/01/09 12:21:07 by jesssanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{
	int	fd1	=	open("test.txt", O_RDONLY);
	int	fd2	=	open("test1.txt", O_RDONLY);
	int	fd3	=	open("test2.txt", O_RDONLY);

	if	(fd1	<	0	||	fd2	<	0	||	fd3	<	0)	{
		perror("Error");
		return	1;
	}

	char	*line;

	// Leer alternadamente de los tres file descriptors
	line	=	get_next_line(fd1);
	printf("fd1:	%s", line);
	free(line);

	line	=	get_next_line(fd2);
	printf("fd2:	%s", line);
	free(line);

	line	=	get_next_line(fd3);
	printf("fd3:	%s", line);
	free(line);

	line	=	get_next_line(fd1);
	printf("fd1:	%s", line);
	free(line);

	line	=	get_next_line(fd2);
	printf("fd2:	%s", line);
	free(line);

	line	=	get_next_line(fd3);
	printf("fd3:	%s", line);
	free(line);

	close(fd1);
	close(fd2);
	close(fd3);

	return	0;
}