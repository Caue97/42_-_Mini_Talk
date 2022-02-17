N_SERVER	=	server
N_CLIENT	=	client

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

DIRECTORY	=	Objs_Minitalk

INCLUDE		=	Source_Code/minitalk.h

CLIENT		=	mt_client.c $(UTILS)

SERVER		=	mt_server.c $(UTILS)

UTILS		=	utils_binary.c utils01.c utils02.c utils03.c

ARGS_CLIENT	=	$(addprefix Source_Code/, $(CLIENT))

OBJS_CLIENT	= $(addprefix ./$(DIRECTORY)/,$(ARGS_CLIENT:Source_Code/%.c=%.o))

all:		debug $(N_CLIENT)

debug:
		echo $(CLIENT) $(SERVER)

$(DIRECTORY)/%.o:	Source_Code/%.c
					$(CC) $(CFLAGS) -c $< -o $@

$(N_CLIENT):	$(DIRECTORY) $(OBJS_CLIENT) $(INCLUDE)
			$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $@

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
			$(RM) $(N_CLIENT) $(N_SERVER)

my_clean:	clean
			$(RM) $(N_CLIENT) $(N_SERVER)
			clear

re:			fclean all

.PHONY:		all clean fclean re