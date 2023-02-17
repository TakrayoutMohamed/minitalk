/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:41:37 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/17 17:43:10 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

int	get_nbr_bytes(int first_byte);
/*returns the reverse bytes of an sigset_t taken as argument*/
sigset_t	reverse_nbr_bytes(sigset_t set, int numbytes)
{
	sigset_t	reversed_number;
	int			number_of_bits;
	int			i;
	int			j;

	i = 0;
	j = 0;
	number_of_bits = 8 * numbytes;
	sigemptyset(&reversed_number);
	numbytes = 1;
	while ( i < number_of_bits)
	{
		if (i % 8 == 0 && i != 0)
		{
			numbytes++;
			j = 0;
		}
		if (set % 2 == 1)
		{
			sigaddset(&reversed_number, number_of_bits - ((8 * numbytes - 1) - j));
		}
		set = set / 2;
		i++;
		j++;
	}
	return (reversed_number);
}
/*returns how many bytes you need to print a character depending on its first one*/
int	get_nbr_bytes(int first_byte)
{
	int	needed_bytes;

	if (first_byte < 192)
		needed_bytes = 1;
	if (first_byte >= 192 && first_byte < 224)
		needed_bytes = 2;
	if (first_byte >= 224 && first_byte < 240)
		needed_bytes = 3;
	if (first_byte >= 240)
		needed_bytes = 4;
	return (needed_bytes);
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	byte_to_char(int sig, siginfo_t *info, void *ucontext)
{
	static sigset_t	set;
	static int		numbit;
	static int		client_pid;
	static int		numbyte;

	(void)ucontext;
	if (numbit == (8 * numbyte) || client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		sigemptyset(&set);
		numbit = 0;
		numbyte = 1;
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1)
			sigaddset(&set, numbit + 1);
		numbit++;
	}
	if (numbit == 8)
		numbyte = get_nbr_bytes(set);
	if (numbit == (8 * numbyte))
	{
		if (numbyte > 1)
		{
			set = reverse_nbr_bytes(set, numbyte);
			write(1, &set, numbyte);
		}
		else
			ft_putchar(set, 1);
	}
}