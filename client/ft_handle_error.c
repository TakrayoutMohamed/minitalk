/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:11:02 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/12 16:24:08 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

void	ft_handle_error(void)
{
	write(1, "there is an error", 18);
}
