# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 18:48:09 by mohtakra          #+#    #+#              #
#    Updated: 2023/02/16 16:32:53 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=MINITALK
SERVERNAME=server
CLIENTNAME=client
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SERVERPATH = ./serverfolder/
CLIENTPATH = ./clientfolder/

SERVER_SRC  =	$(SERVERPATH)server_utils.c  $(SERVERPATH)main_server.c
CLIENT_SRC	=	$(CLIENTPATH)char_to_binair.c $(CLIENTPATH)ft_handle_error.c \
				$(CLIENTPATH)send_signal.c $(CLIENTPATH)main_client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

all		: $(NAME)
		@$(CC) -o $(SERVERNAME) $(SERVER_OBJ)
		@echo "the client has ben created successfully"
		@$(CC) -o $(CLIENTNAME) $(CLIENT_OBJ)
		@echo "the client has ben created successfully"
$(NAME) : $(SERVER_OBJ) $(CLIENT_OBJ)
		

$(SERVERNAME): $(SERVER_OBJ)
				@$(CC) -o $@ $(SERVER_OBJ)
				@echo "the server has ben created successfully"

$(CLIENTNAME): $(CLIENT_OBJ)
			@$(CC) -o $@ $(CLIENT_OBJ)
			@echo "the client has ben created successfully"

%.o: %.c minitalk.h
	$(CC) $(CFLAGS)  -c $< -o $@
	@echo "the file $@ has been created from $<"

clean:
		@$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
		@echo "all the .o has been deleted successfully"

fclean: clean
		@$(RM) $(SERVERNAME) $(CLIENTNAME)
		@echo "the executable has been deleted"
	
re: fclean all

.PHONY : server client clean $(NAME) all fclean bonus re 