/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:43:34 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/16 17:04:48 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

int	send_signal(int signal_type, int pid)
{
	int	kill_return;

	kill_return = 1337;
	if (signal_type == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
			kill_return = -1;
	}
	else if (kill(pid, SIGUSR2) == -1)
		kill_return = -1;
	return (kill_return);
}
