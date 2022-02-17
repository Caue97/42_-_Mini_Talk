/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:13:22 by felcaue-          #+#    #+#             */
/*   Updated: 2022/02/17 18:07:52 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

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

/**
 * @brief Converts a binary int to a *char
 * 
 * @param numb the binary to convert
 * @return The converted number 
 */
char		*ft_binary_itoa(int numb);

/**
 * @brief Auxialiary Function to function 'BINARY_ITOA', puts the rest of 
 * the zero/s in place
 * 
 * @param str The char to receive zeros
 * @return The char with the zeros
 */
char		*put_zero(char *str);

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
 * @param n The number to write
 * @param fd The file descriptor
 */
void		ft_putnbr_fd(int n, int fd);

/**
 * @brief Converts a 'Char' number to a 'Int' number
 * 
 * @param to_convert The number to convert
 * @return The number in 'Int'
 */
int			ft_atoi(const char *to_convert);

/**
 * @brief Auxialiary Function to function 'ATOI', it checks if the 
 * number is bigger than the limits of int 
 * 
 * @param number_o The number to check
 * @param f_negative_o If is negative
 * @return If there is overflow
 */
static int	check_overflow(int number_o, int f_negative_o);

/**
 * @brief Checks the size of a string
 * 
 * @param str The string
 * @return The size of the string passed
 */
size_t		ft_strlen(const char *str);

//utils02.c ============================================

/**
 * @brief Converts a 'Int' number to a 'Char' number
 * 
 * @param n The number to convert
 * @return The number in 'Char'
 */
char		*ft_itoa(int n);

/**
 * @brief Auxialiary Function to function 'ITOA', The major part of the 
 * conversion is done in this function
 * 
 * @param n_conv The number to convert
 * @param d_str The 'malloc' string 
 * @param length The size of the number
 */
static void	convt_to_number(int n_conv, char *d_str, long int length);

/**
 * @brief Copies a *char, or part of it, to a new *char that was passed 
 * to the function
 * 
 * @param copy Where to copy the *char
 * @param original The original *char
 * @param size The size of the copy to make
 * @return The size of the original *char
 */
size_t		ft_strlcpy(char *copy, const char *original, size_t size);

/**
 * @brief Join two *char together
 * 
 * @param s1 The first *char
 * @param s2 The second *char
 * @return The combined *char
 */
char		*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Duplicates the string
 * 
 * @param strin_g The string to duplicate
 * @return The duplicated string
 */
char		*ft_strdup(const char *strin_g);

//utils03.c ============================================

/**
 * @brief Copies a const *void, or part of it, to a *char that was passed 
 * to the function
 * 
 * @param copy Where to copy
 * @param original The original string
 * @param length size of the copy
 * @return The copied string 
 */
void		*ft_memcpy(char *copy, const void *original, size_t length);

#endif
