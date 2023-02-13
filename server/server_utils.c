/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:41:37 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/13 15:39:04 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

void	byte_to_char(int sig)
{
	sigset_t	set;
	static int	numbyte;

	if (numbyte == 0 || numbyte == 7)
	{
		sigemptyset(&set);
		numbyte = 0;
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1)
		{
			sigaddset(&set, numbyte + 1);
			// ft_putchar('1', 1);
		}
		numbyte++;
	}
	if (numbyte == 7)
	// {
		// printf("\nnumbyte = %d , set = %u\n", numbyte, set);
	// }
		ft_putchar((char)set, 1);
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}
