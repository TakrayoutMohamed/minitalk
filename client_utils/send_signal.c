/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:43:34 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/11 22:16:44 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

int	send_signal(int signal_type, int pid)
{
	int	kill_return;

	if (signal_type == 1)
		kill_return = kill(pid, SIGUSR1);
	else
		kill_return = kill(pid, SIGUSR2);
	return (kill_return);
}
