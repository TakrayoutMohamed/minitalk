# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 18:48:09 by mohtakra          #+#    #+#              #
#    Updated: 2023/02/15 20:25:19 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=MINITALK
SERVERNAME=server
CLIENTNAME=client
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SERVERPATH = ./server/
CLIENTPATH = ./client/

SERVER_SRC  =	$(SERVERPATH)server_utils.c   $(SERVERPATH)server.c
CLIENT_SRC	=	$(CLIENTPATH)char_to_binair.c $(CLIENTPATH)ft_handle_error.c\
				$(CLIENTPATH)send_signal.c    $(CLIENTPATH)client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

all: $(NAME)

$(NAME) : $(SERVERNAME) $(CLIENTNAME)
# @$(CC) -I./server/ $(CFLAGS) -o $(SERVERNAME) $(SERVER_OBJ)
# @echo "the server has ben created successfully"
# @$(CC) -I. $(CFLAGS) -o $(CLIENTNAME) $(CLIENT_OBJ)
# @echo "the client has ben created successfully"

server: $(SERVER_OBJ)
		$(CC) -o $@ $(SERVER_OBJ)

client: $(CLIENT_OBJ)
		@$(CC) -o $@ $(CLIENT_OBJ)

%.o: %.c minitalk.h
		@$(CC) $(CFLAGS)  -c $< 
		@echo "the file $@ has been created from $<"

clean:
		@$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
		@echo "all the .o has been deleted successfully"

fclean: clean
		@$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
		@echo "the libft.a has been deleted"
	
re: fclean all

.PHONE : clean $(NAME) all fclean bonus re