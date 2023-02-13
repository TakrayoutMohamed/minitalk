/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_binair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:30:03 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/13 17:16:35 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

void	char_to_binair(char c, int pid)
{
	int	signal_type;
	int	number_of_bytes;

	number_of_bytes = 7;
	while (number_of_bytes--)
	{
		signal_type = c % 2;
		c = c / 2;
		send_signal(signal_type, pid);
		usleep(400);
	}
}
