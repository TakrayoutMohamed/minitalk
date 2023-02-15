# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 18:48:09 by mohtakra          #+#    #+#              #
#    Updated: 2023/02/15 17:48:41 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAMECLIENT=client
# NAMESERVER=server
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

server: $(SERVER_OBJ)
		$(CC) -o $@ $(SERVER_OBJ)
		@echo "the server has ben created successfully"

client: $(CLIENT_OBJ)
		@$(CC) -o $@ $(CLIENT_OBJ)
		@echo "the client has ben created successfully"

$(SERVER_OBJ) : $(SERVER_SRC) $(SERVERPATH)server.h 
		@$(CC) -I. $(CFLAGS) -o $@ -c $< 
		@echo "the file $@ has been created from $<"

%.o: %.c $(SERVERPATH)server.h 
		@$(CC) -I. $(CFLAGS) -o $@ -c $< 
		@echo "the file $@ has been created from $<"

clean:
		@$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
		@echo "all the .o has been deleted successfully"

fclean: clean
		@$(RM) $(SERVERPATH)$(SERVER_OBJ) $(CLIENTPATH)$(CLIENT_OBJ)
		@echo "the libft.a has been deleted"
	
re: fclean all

.PHONE : clean $(NAME) all fclean bonus re