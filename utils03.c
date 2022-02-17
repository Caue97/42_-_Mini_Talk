/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:00:35 by felcaue-          #+#    #+#             */
/*   Updated: 2022/02/16 21:01:10 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strdup(const char *strin_g)
{
	size_t	length;
	char	*new_cpy;

	length = ft_strlen(strin_g) + 1;
	new_cpy = malloc(length);
	if (!new_cpy)
	{
		return (0);
	}
	return (ft_memcpy(new_cpy, strin_g, length));
}
