# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljustici <ljustici@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 12:39:37 by ljustici          #+#    #+#              #
#    Updated: 2022/09/17 17:35:14 by ljustici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client
NAME_S_B = server_bonus
NAME_C_B = client_bonus

SRC_S = server.c
SRC_C = client.c

SRC_S_B = server_bonus.c
SRC_C_B = client_bonus.c

LIBFT		= pglibft/libft.a
SRC_LIBFT	= ./pglibft

CC = gcc
CFLAGS = -Wall -Werror -Wextra
COLOR_DONE = \033[47m\033[1;32m
NORMI = norminette .

all:  ${LIBFT} $(NAME_S) $(NAME_C)

$(NAME_S): $(SRC_S)
	@$(CC) $(CFLAGS)  ${LIBFT}  -o $@ $(SRC_S)
	@echo "$(COLOR_DONE)Server compiled successfully\n"

$(NAME_C): $(SRC_C)
	@$(CC) $(CFLAGS)  ${LIBFT}  -o $@ $(SRC_C)
	@echo "$(COLOR_DONE)Client compiled successfully\n"

$(NAME_S_B): $(SRC_S_B)
	@$(CC) $(CFLAGS)  ${LIBFT}  -o $@ $(SRC_S_B)
	@echo "$(COLOR_DONE)Bonus server compiled successfully\n"

$(NAME_C_B): $(SRC_C_B)
	@$(CC) $(CFLAGS)  ${LIBFT}  -o $@ $(SRC_C_B)
	@echo "$(COLOR_DONE)Bonus client compiled successfully\n"

${LIBFT}:
			@$(MAKE) -C ./pglibft
			@echo "$(COLOR_DONE)Libft compiled successfully\n"

bonus:		${LIBFT} $(NAME_S_B) $(NAME_C_B)

clean:
			@ $(MAKE) clean -sC $(SRC_LIBFT)
			
fclean:	clean
			@ $(MAKE) fclean -sC $(SRC_LIBFT)
			@rm -f $(NAME_S) $(NAME_C) $(NAME_S_B) $(NAME_C_B)

re: fclean all
			
.PHONY: all clean re fclean 