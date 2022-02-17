/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:49:54 by felcaue-          #+#    #+#             */
/*   Updated: 2022/02/17 19:06:25 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_itoa(int n)
{
	char		*ret_strng;
	long int	num_og_c;
	long int	len_count;

	num_og_c = n;
	len_count = 0;
	if (num_og_c <= 0)
	{
		len_count++;
	}
	while (num_og_c)
	{
		num_og_c = (num_og_c / 10);
		len_count++;
	}
	ret_strng = malloc(sizeof(char) * (len_count + 1));
	if (!ret_strng)
	{
		return (NULL);
	}
	ret_strng[len_count] = 0;
	convt_to_number(n, ret_strng, (len_count - 1));
	return (ret_strng);
}

void	convt_to_number(int n_conv, char *d_str, long int length)
{
	unsigned int	n_holder;

	n_holder = n_conv;
	if (n_conv < 0)
	{
		d_str[0] = '-';
		n_holder = -n_holder;
	}
	if (n_holder >= 10)
	{
		convt_to_number((n_holder / 10), d_str, (length - 1));
	}
	d_str[length] = (n_holder % 10) + '0';
}

size_t	ft_strlcpy(char *copy, const char *original, size_t size)
{
	size_t	size_og;
	size_t	counter;

	size_og = ft_strlen(original);
	counter = 0;
	if (!original || !copy)
	{
		return (0);
	}
	if (size != 0)
	{
		while (original[counter] != '\0' && counter < (size - 1))
		{
			copy[counter] = original[counter];
			counter++;
		}
		copy[counter] = '\0';
	}
	return (size_og);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strng_u;
	char	*destiny_ret;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	strng_u = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)
				+ 1) * sizeof(char));
	if (strng_u == NULL)
	{
		return (NULL);
	}
	destiny_ret = strng_u;
	while (*s1)
	{
		*strng_u++ = *s1++;
	}
	while (*s2)
	{
		*strng_u++ = *s2++;
	}
	*strng_u = '\0';
	return (destiny_ret);
}

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
