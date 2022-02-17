# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 19:15:02 by felcaue-          #+#    #+#              #
#    Updated: 2022/02/17 19:10:30 by felcaue-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

N_SERVER	=	server
N_CLIENT	=	client

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

DIRECTORY	=	Objs_Minitalk

INCLUDE		=	Source_Code/minitalk.h

CLIENT		=	mt_client.c

SERVER		=	mt_server.c

UTILS		=	utils_binary.c utils01.c utils02.c utils03.c

ADD_ARG_U	=	$(addprefix Source_Code/,$(UTILS))
ADD_ARG_C	=	$(addprefix Source_Code/,$(CLIENT))
ADD_ARG_S	=	$(addprefix Source_Code/,$(SERVER))

OBJS		=	$(addprefix $(DIRECTORY)/,$(UTILS:.c=.o))
C_OBJS		=	$(addprefix $(DIRECTORY)/,$(CLIENT:.c=.o))
S_OBJS		=	$(addprefix $(DIRECTORY)/,$(SERVER:.c=.o))

all:		debug $(N_CLIENT) $(N_SERVER)

debug:
		echo $(OBJS) $(C_OBJS) $(S_OBJS)
		echo $(UTILS) $(CLIENT) $(SERVER)

$(DIRECTORY)/%.o:	Source_Code/%.c
					$(CC) $(CFLAGS) -c $< -o $@

$(N_CLIENT):	$(DIRECTORY) $(C_OBJS) $(OBJS) $(INCLUDE)
			$(CC) $(CFLAGS) $(C_OBJS) $(OBJS) -o $@

$(N_SERVER):	$(DIRECTORY) $(S_OBJS) $(OBJS) $(INCLUDE)
			$(CC) $(CFLAGS) $(S_OBJS) $(OBJS) -o $@


$(DIRECTORY):
				mkdir -p $(DIRECTORY)

git:
			clear
			git add .
			git commit -m "make git update"
			git push origin

clean:
			$(RM) $(DIRECTORY)

fclean:		clean
			$(RM) $(N_CLIENT) 
			$(RM) $(N_SERVER)

my_clean:	clean
			$(RM) $(N_CLIENT)
			$(RM) $(N_SERVER)
			clear

re:			fclean all

.PHONY:		all clean fclean re