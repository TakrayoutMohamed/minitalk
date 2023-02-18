# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 18:48:09 by mohtakra          #+#    #+#              #
#    Updated: 2023/02/18 18:49:02 by mohtakra         ###   ########.fr        #
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
ERRORPATH = ./handle_error/
FT_LIBFTPATH = ./libft/

SERVER_SRC  =	$(SERVERPATH)server_utils.c  $(SERVERPATH)main_server.c \
				$(ERRORPATH)ft_handle_error.c
CLIENT_SRC	=	$(CLIENTPATH)client_utils.c $(CLIENTPATH)main_client.c \
				$(ERRORPATH)ft_handle_error.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

all		: $(NAME)

norm : $(SERVER_SRC) $(CLIENT_SRC)
	make -C $(FT_LIBFTPATH) norm
	@echo "**********************the Norminette result*************************"
	@norminette minitalk.h $(SERVER_SRC) $(CLIENT_SRC)
	

$(NAME) : $(SERVERNAME) $(CLIENTNAME)
		

$(SERVERNAME): libft.a $(SERVER_OBJ)
				@$(CC) -o $@ $(SERVER_OBJ) $(FT_LIBFTPATH)libft.a

$(CLIENTNAME): libft.a $(CLIENT_OBJ)
			@$(CC) -o $@ $(CLIENT_OBJ) $(FT_LIBFTPATH)libft.a

%.o: %.c minitalk.h 
	@$(CC) $(CFLAGS)  -c $< -o $@
	@echo "the file $@ has been created from $<"

libft.a :
		@make -C $(FT_LIBFTPATH)
clean:
		@$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
		@make -C $(FT_LIBFTPATH) clean
		@echo "all the .o has been deleted successfully"

fclean: clean
		@$(RM) $(SERVERNAME) $(CLIENTNAME)
		@make -C $(FT_LIBFTPATH) fclean
		@echo "the executable client and server has been deleted"
	
re: fclean all

.PHONY : server client clean $(NAME) all fclean bonus re 