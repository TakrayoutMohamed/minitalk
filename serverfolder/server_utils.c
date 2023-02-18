/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:41:37 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/18 17:05:05 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

/*get the signal SIGUSR1 ,SIGUSR2 till get 7 signals and print that character*/
void	bits_to_char(int sig, siginfo_t *info, void *ucontext)
{
	static sigset_t	set;
	static int		numbit;
	static int		client_pid;

	(void)ucontext;
	if (numbit == 7 || client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		sigemptyset(&set);
		numbit = 0;
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1)
			sigaddset(&set, numbit + 1);
		numbit++;
	}
	if (numbit == 7)
		ft_putchar_fd(set, 1);
}
