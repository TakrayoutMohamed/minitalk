/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_binair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:30:03 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/16 22:44:24 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

void	send_char_bite_bite(unsigned char c, int pid)
{
	int	bit_to_send;
	int	number_of_bits;

	number_of_bits = 8;
	// printf("\n||\n");
	// write(1, &c, 1);
	// printf("\n||\n");
	while (number_of_bits--)
	{
		bit_to_send = c % 2;
		c = c / 2;
		if (send_signal(bit_to_send, pid) == -1)
		{
			ft_handle_error();
			return;
		}
		usleep(200);
	}
}
