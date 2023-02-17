/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:20:59 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/17 17:29:08 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3 || atoi(argv[1]) <= 0)  // neeed to creat the ft_atoi
	{
		ft_handle_error("please make sure that args are 2 andpid is gt 0");
	}
	else
	{
		while (argv[2][i])
		{
			send_char_bite_bite(argv[2][i], atoi(argv[1])); // neeed to creat the ft_atoi
			i++;
		}
	}
	return (0);
}
