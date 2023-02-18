/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:20:59 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/18 17:29:09 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3 || ft_atoi(argv[1]) <= 0)
	{
		ft_handle_error("****please make sure that you entered ");
		ft_handle_error("two parameters \n");
		ft_handle_error("****Exemple :\n****./client PID \"the string\"");
	}
	else
	{
		while (argv[2][i])
		{
			send_char_bit_bit(argv[2][i], ft_atoi(argv[1]));
			i++;
		}
	}
	return (0);
}
