/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:48:34 by felcaue-          #+#    #+#             */
/*   Updated: 2022/02/17 15:53:00 by felcaue-         ###   ########.fr       */
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
