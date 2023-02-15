/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:20:59 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/15 18:05:14 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3 || atoi(argv[1]) == 0 || atoi(argv[1]) == -1)  // neeed to creat the ft_atoi
	{
		ft_handle_error();
	}
	else
	{
		while (argv[2][i])
		{
			// printf("the size of the string is : %d\n",sizeof(argv[2]));
			// printf("\nchar %d : %d\n", i, argv[2][i]);
			// if (argv[2][i] > 127)
			// {
			// 	printf("dddddddf");
			// }
			send_char_bite_bite(argv[2][i], atoi(argv[1])); // neeed to creat the ft_atoi
			i++;
		}
	}
	return (0);
}
