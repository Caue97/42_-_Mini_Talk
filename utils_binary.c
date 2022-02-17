/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:02:28 by felcaue-          #+#    #+#             */
/*   Updated: 2022/02/17 15:41:30 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	convert_to_binary(unsigned long nbr, char *base)
{
	int	size_base;
	int	nbr_final[100];
	int	counter;

	counter = 0;
	size_base = 0;
	nbr = (unsigned int)nbr;
	if (check_base(base))
	{
		size_base = ft_strlen(&base[size_base]);
		while (nbr)
		{
			nbr_final[counter] = nbr % size_base;
			nbr = nbr / size_base;
			counter++;
		}
	}
	return (eternal_return(base, nbr_final, counter));
}

int	check_base( char *base)
{
	int	counter_01;
	int	counter_02;

	counter_01 = 0;
	counter_02 = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[counter_01])
	{
		counter_02 = counter_01 + 1;
		if (base[counter_01] < 32 || base[counter_01] > 126)
			return (0);
		while (base[counter_02])
		{
			if (base[counter_01] == base[counter_02])
				return (0);
			counter_02++;
		}
		counter_01++;
	}
	return (1);
}

int	eternal_return(char *base, int nbr_final[], int counter)
{
	char	*holder_01;
	char	*holder_02;
	int		count_ext;

	holder_02 = (char *)malloc(sizeof(char *) * (counter + 1));
	holder_02[counter + 1] = '\0';
	count_ext = 0;
	while (--counter >= 0)
	{
		if (base[nbr_final[counter]] == '1')
			holder_01 = "1";
		else
			holder_01 = "0";
		holder_02[count_ext] = *holder_01;
		count_ext++;
	}
	counter = ft_atoi(holder_02);
	free (holder_02);
	return (counter);
}

char	*ft_binary_itoa(int numb)
{
	char		*str;
	long int	binary_og;
	long int	count;
	char		*send;

	binary_og = numb;
	count = 0;
	if (binary_og <= 0)
		count++;
	while (binary_og)
	{
		binary_og = (binary_og / 10);
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = 0;
	convert (numb, str, (count - 1));
	send = put_zero(str);
	free (str);
	return (send);
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
