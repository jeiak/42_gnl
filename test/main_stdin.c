/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:07:38 by jesssanc          #+#    #+#             */
/*   Updated: 2025/01/10 09:26:02 by jesssanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h>

int	main(void)
{
	char	*line;

	printf("Escribe texto (Ctrl+D para terminar):\n");
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break;
		if (line[0] == '\0')
		{
			free(line);
			continue;
		}
		printf("Línea leída: %s", line);
		free(line);
	}
	return (0);
} 
//  cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c get_next_line_bonus.h //
