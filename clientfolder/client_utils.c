/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:30:03 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/18 18:24:35 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

static void	send_signal(int signal_type, int pid)
{
	if (signal_type == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_handle_error("Error with the kill function while sending");
			ft_handle_error("the SIGUSR1");
			exit(EXIT_FAILURE);
		}
	}
	else if (kill(pid, SIGUSR2) == -1)
	{
		ft_handle_error("Error with the kill function while sending");
		ft_handle_error("the SIGUSR2");
		exit(EXIT_FAILURE);
	}
}

void	send_char_bit_bit(char c, int pid)
{
	int	bit_to_send;
	int	number_of_bits;

	number_of_bits = 7;
	while (number_of_bits--)
	{
		bit_to_send = c % 2;
		c = c / 2;
		send_signal(bit_to_send, pid);
		usleep(550);
	}
}
