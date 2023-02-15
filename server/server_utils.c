/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:41:37 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/15 17:59:20 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

void	byte_to_char(int sig, siginfo_t *info, void *ucontext)
{
	static sigset_t	set;
	static int		numbyte;
	static int		client_pid;

	(void *)ucontext;
	if (numbyte == 8 || client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		if (sigemptyset(&set))
			exit(EXIT_FAILURE);
		numbyte = 0;
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1)
		{
			if (sigaddset(&set, numbyte + 1))
				exit(EXIT_FAILURE);
		}
		numbyte++;
		if (sig == SIGUSR1)
			// printf("1");
			write(1, "1", 2);
		if (sig == SIGUSR2)
			write(1, "0", 2);
	}
	if (numbyte == 8)
		ft_putchar((char)set, 1);
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}
