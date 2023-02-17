/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:23:39 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/17 17:26:56 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
	# include <stdio.h>
	# include <stdlib.h>
	# include <unistd.h>
	# include <signal.h>
	# include <string.h>
	// the client's functions
	void	ft_handle_error(char *str);
	void	send_char_bite_bite(unsigned char c, int pid);
	int		send_signal(int signal_type, int pid);
	// the server's function
	void	byte_to_char(int sig, siginfo_t *info, void *ucontext);
	void	ft_putchar(char c, int fd);
#endif
