/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:24:57 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/15 17:59:54 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = byte_to_char;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	printf("the pid is : %d \n", getpid());//ddddwwwwwwweeeeeee remove the printf
	while (1)
		sleep(1);
	return (0);
}
