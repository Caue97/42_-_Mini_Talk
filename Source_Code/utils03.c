/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:48:34 by felcaue-          #+#    #+#             */
/*   Updated: 2022/02/17 19:00:38 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_memcpy(char *copy, const void *original, size_t length)
{
	unsigned char	*source;
	unsigned char	*destiny;

	if (original == NULL && copy == NULL)
	{
		return (copy);
	}
	destiny = (unsigned char *) copy;
	source = (unsigned char *) original;
	while (length--)
	{
		*destiny++ = *source++;
	}
	return (copy);
}

char	*put_zero(char *str)
{
	int		counter;
	char	*aux;
	char	*send;

	counter = ft_strlen(str);
	if (counter == 7)
	{
		aux = "0";
		send = ft_strjoin(aux, str);
	}
	else if (counter == 6)
	{
		aux = "00";
		send = ft_strjoin(aux, str);
	}
	return (send);
}
