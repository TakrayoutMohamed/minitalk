/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:41:37 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/15 14:11:03 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

void	byte_to_char(int sig, siginfo_t *info, void *ucontext)
{
	// sigset_t	set;
	// int  client_pid;
	// int walo = 0;
	int numbit;
	int var = numbit;
	printf("nbit--> %d\n",var);
	// numbit = 0;
	numbit++;
	// if (numbite == 0 || numbite == 8 || client_pid != info->si_pid)
	// {
	// 	client_pid = info->si_pid;
	// 	// sigemptyset(&set);
	// 	numbite = 0;
	// }
	
	// if (sig == SIGUSR1 || sig == SIGUSR2)
	// {
	// 	// if (sig == SIGUSR1)
	// 	// sigaddset(&set, numbite + 1);
	// 	numbite++
	// }
	// if (numbite == 8)
	// {
	// 	ft_putchar((char)set, 1);
	// 	// printf("\n********\n%c\n************\n", 223);
	// }
}
void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}
