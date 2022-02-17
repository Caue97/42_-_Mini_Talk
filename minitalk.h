/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:13:22 by felcaue-          #+#    #+#             */
/*   Updated: 2022/02/17 13:54:45 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK
# define MINITALK

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

//mt_server.c ==========================================

/**
 * @brief Used for the server to receive the signal
 * 
 * @param signal The signal received
 */
void		receive_signal(int signal);

//mt_client.c ==========================================

/**
 * @brief Starts the signal that will be sent
 * 
 * @param string The information to put in the signal
 * @param pid Connection Number
 */
void		start_signal(char **string, int pid);

/**
 * @brief Send the signal to the server
 * 
 * @param bin The binary information to send
 * @param pid Connection Number
 */
void		send_signal(int binary, int pid);

/**
 * @brief Sends a message to the user, informing of errors
 * 
 * @param aux Type of error
 */
void		error_init(int aux);

//utils_binary.c ==========================================

/**
 * @brief Converts the information received to binary
 * 
 * @param nbr Information received to convert
 * @param base The base to use in conversion
 * @return The binary information
 */
int			convert_to_binary(unsigned long nbr, char *base);

/**
 * @brief Check the number base passed
 * 
 * @param base The base passed to test
 * @return If the base is the correct one
 */
int			check_base( char *base);

/**
 * @brief Generates the binary return needed to pass the information coverted
 * 
 * @param base The binary base
 * @param nbr_final The final form of the information to send
 * @param counter the counter used to measure the size of the information
 * @return int 
 */
int			eternal_return(char *base, int nbr_final[], int counter);

//utils01.c ============================================

/**
 * @brief Writes a character in the file descriptor specified
 * 
 * @param c The char to write
 * @param fd The file descriptor
 */
void		ft_putchar_fd(char c, int fd);

/**
 * @brief Writes a number on the file descriptor specified
 * 
 * @param n The number to write in the file descriptor
 * @param fd 
 */
void		ft_putnbr_fd(int n, int fd);

int			ft_atoi(const char *to_convert);

static int	check_overflow(int number_o, int f_negative_o);

size_t		ft_strlen(const char *str);

//utils02.c ============================================

//utils03.c ============================================

#endif
