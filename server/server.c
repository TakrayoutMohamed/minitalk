/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:24:57 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/12 17:49:34 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &byte_to_char;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("the pid is : %d \n", getpid());//ddddwwwwwwweeeeeee remove the printf
	while (1)
		sleep(1);
	return (0);
}
