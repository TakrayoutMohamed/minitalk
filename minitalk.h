/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:23:39 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/11 22:17:58 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

#ifndef MINITALK_H
# define MINITALK_H
	void	ft_handle_error();
	void	char_to_binair(char c, int pid);
	int		send_signal(int, int);
#endif
