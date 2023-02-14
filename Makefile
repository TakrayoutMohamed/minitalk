# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 18:48:09 by mohtakra          #+#    #+#              #
#    Updated: 2023/02/14 18:48:12 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMECLIENT = client
NAMESERVER = server
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SERVERPATH = ./server/
CLIENTPATH = ./client/

SERVER_SRC  =	$(SERVERPATH)server_utils.c   $(SERVERPATH)server.c
CLIENT_SRC	=	$(CLIENTPATH)char_to_binair.c $(CLIENTPATH)ft_handle_error.c\
				$(CLIENTPATH)send_signal.c    $(CLIENTPATH)client.c

SERVER_SRC	 =  $(SERVER_SRC:.c=.o)
CLIENT_OBJ	 =  $(CLIENT_SRC:.c=.o)

all: $(NAMECLIENT) $(NAMESERVER)

norm : $(SERVER_SRC) $(CLIENT_SRC)
	@echo "**********************the Norminette result*************************"
	@norminette $(SERVER_SRC) $(CLIENT_SRC) minitalk.h $(SERVERPATH)server.h $(CLIENTPATH)client.h

#$(NAMECLIENT): $(CLIENT_OBJ)
#		@ar rc $@ $(CLIENT_OBJ)
#		@echo "all the files has been archieved successfully in $@"

%.o : %.c ft_printf.h $(LIBFTPATH)libft.h
		@$(CC) -I. -o $@ -c $< $(CFLAGS)
		@echo "the file $@ has been created from $<"

clean:
		@$(RM) $(OBJ)
		@echo "all the .o has been deleted successfully"
		
fclean: clean
		@$(RM) $(NAME)
		@echo "the $(NAME) has been deleted"

re: fclean all

.PHONE : clean $(NAME) all fclean re norm