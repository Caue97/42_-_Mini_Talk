/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:21:38 by felcaue-          #+#    #+#             */
/*   Updated: 2022/02/17 13:39:50 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int	pid;
	int	aux;

	aux = 0;
	if (argc != 3)
	{
		aux = 1;
		error_init(aux);
	}
	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		aux = 2;
		error_init(aux);
	}
	start_signal(&argv[2], pid);
}

void	start_signal(char **string, int pid)
{
	int				counter;
	int				binary;
	int unsigned	converted;

	counter = 0;
	while (string[0][counter])
	{
		converted = string[0][counter];
		binary = convert_to_binary((unsigned long)converted, "01");
		send_signal(binary, pid);
		counter++;
	}
}

void	send_signal(int binary, int pid)
{
	char	*binary_char;
	int		counter;

	binary_char = ft_itoa(binary);
	counter = 0;
	while (binary_char[counter])
	{
		if (binary_char[counter] == '0')
		{
			kill(pid, SIGUSR1);
			usleep(2500);
		}
		else if (binary_char[counter] == '1')
		{
			kill (pid, SIGUSR2);
			usleep(2500);
		}
		counter++;
	}
	free (binary_char);
	binary_char = NULL;
}

void	error_init(int aux)
{
	if (aux == 1)
	{
		write (1, "Error, check the arguments.\n", 28);
		exit (1);
	}
	if (aux == 2)
	{
		write (1, "Error, check the conversion PID.\n", 33);
		exit (1);
	}
}
