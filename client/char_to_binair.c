/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_binair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:30:03 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/14 20:27:16 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

void	send_char_bite_bite(char c, int pid)
{
	int	bit_to_send;
	int	number_of_bits;

	number_of_bits = 7;
	while (number_of_bits--)
	{
		bit_to_send = c % 2;
		c = c / 2;
		send_signal(bit_to_send, pid);
		usleep(200);
	}
}
