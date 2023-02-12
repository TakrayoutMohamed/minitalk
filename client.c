/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:20:59 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/12 15:20:25 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 3)
	{
		ft_handle_error();
	}
	else
	{
		while (argv[2][i])
		{
			char_to_binair(argv[2][i], ft_atoi(argv[1]));
			i++;
		}
		
	}
	return (0);
}
