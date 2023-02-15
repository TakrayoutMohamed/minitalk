/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:43:34 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/15 18:03:14 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

int	send_signal(int signal_type, int pid)
{
	int	kill_return;

	if (signal_type)
		if (kill(pid, SIGUSR1))
			exit(EXIT_FAILURE);
	else if (kill(pid, SIGUSR2))
		exit(EXIT_FAILURE);
	return (kill_return);
}
