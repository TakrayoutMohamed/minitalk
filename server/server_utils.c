/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:41:37 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/14 18:34:44 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

void	byte_to_char(int sig, siginfo_t *info, void *ucontext)
{
	sigset_t	set;
	static int	numbyte;
	static int  client_pid;
	
	if (numbyte == 0 || numbyte == 7 || client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		sigemptyset(&set);
		numbyte = 0;
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1)
			sigaddset(&set, numbyte + 1);
		numbyte++;
	}
	if (numbyte == 7)
		ft_putchar((char)set, 1);
}
// void	test(int sig, siginfo_t *info, ucontext_t *uap)
// {
// 	static int  firstpid;
	
// 	if (!firstpid)
// 	{
// 		firstpid = info->si_pid;
// 	}
// 	else if (info->si_pid != firstpid)
// 	{
// 		sigemptyset();
// 		firstpid = info->si_pid;
// 	}
// }
void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}
