/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:41:37 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/16 22:50:00 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

int	get_nbr_bytes(int first_byte);

void	byte_to_char(int sig, siginfo_t *info, void *ucontext)
{
	static sigset_t	set;
	static int		numbit;
	static int		client_pid;
	static int		numbyte;

	printf("**numbit = %d numbyte = %d**",numbit,numbyte);
	(void)ucontext;
	if (numbit == (8 * numbyte) || client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		if (sigemptyset(&set))
			exit(EXIT_FAILURE);
		numbit = 0;
		numbyte = 1;
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1)
		{
			if (sigaddset(&set, numbit + 1))
				exit(EXIT_FAILURE);
		}
		numbit++;
		if (sig == SIGUSR1)
			// printf("1");
			write(1, "1", 2);
		if (sig == SIGUSR2)
			write(1, "0", 2);
		if (numbit == 8)
			printf("\nhhhhhhh\n");
	}
	if (numbit == 8)
		numbyte = get_nbr_bytes(set);
	if (numbit == (8 * numbyte))
	{
		ft_putchar(set, numbyte);
		printf("%u",set);
	}
}
/*returns how many bytes you need to print a character */
int	get_nbr_bytes(int first_byte)
{
	int	needed_bytes;

	if (first_byte <= 127)
	{
		needed_bytes = 1;
	}
	if (first_byte > 127 && first_byte <= 192)
	{
		needed_bytes = 1;
	}
	if (first_byte > 192 && first_byte <= 224)
	{
		needed_bytes = 2;
	}
	if (first_byte > 224 && first_byte <= 240)
	{
		needed_bytes = 4;
	}
	if (first_byte > 240 && first_byte <= 248)
	{
		needed_bytes = 5;
	}
	if (first_byte > 248 && first_byte <= 252)
	{
		needed_bytes = 6;
	}
	if (first_byte > 252 && first_byte <= 254)
	{
		needed_bytes = 7;
	}
	if (first_byte > 254 && first_byte <= 255)
	{
		needed_bytes = 8;
	}
	return (needed_bytes);
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}
