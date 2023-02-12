/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:41:37 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/12 19:31:10 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

void	byte_to_char(int sig)
{
	sigset_t	set;
	static int	numbyte;

	if (numbyte == 0 || numbyte == 6)
	{
		sigemptyset(&set);
		numbyte = 0;
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1)
		{
			sigaddset(&set, numbyte);
		}
		numbyte++;
	}
	if (numbyte == 6)
		ft_putchar((char)set, 1);
	ft_putchar(numbyte + 48, 1);
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}
