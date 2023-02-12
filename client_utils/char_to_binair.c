/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_binair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:30:03 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/12 14:51:51 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

void	char_to_binair(char c, int pid)
{
	int	signal_type;
	
	while (c)
	{
		signal_type = c % 2;
		c = c / 2;
		send_signal(signal_type, pid);
		usleep(1);
	}
}
