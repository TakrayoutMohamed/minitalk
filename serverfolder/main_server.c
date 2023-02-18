/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:24:57 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/18 16:54:39 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = bits_to_char;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_handle_error("there is an error occured while using sigaction");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_handle_error("there is an error occured while using sigaction");
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd("Server PID :", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("", 1);
	while (1)
		sleep(1);
	return (0);
}
