/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:24:57 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/17 17:36:14 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = byte_to_char;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_handle_error("there is an erro occured while using sigaction");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_handle_error("there is an erro occured while using sigaction");
		exit(EXIT_FAILURE);
	}
	printf("the pid is : %d \n", getpid());//ddddwwwwwwweeeeeee remove the printf
	while (1)
		sleep(1);
	return (0);
}
