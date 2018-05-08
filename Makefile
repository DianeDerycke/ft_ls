# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/08 15:02:32 by DERYCKE           #+#    #+#              #
#    Updated: 2018/05/08 19:43:03 by DERYCKE          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIBFT = libft/libft.a
FILES =  main	parser	error	add_file_to_lst	verif_ft
SRC = $(addsuffix .c, $(FILES))

all: $(NAME)

$(NAME): $(SRC)
	cd libft/ && $(MAKE)
	gcc -Wall -Werror -Wextra -o $@ $^ $(LIBFT)
	
clean:
	cd libft/ && $(MAKE) clean
	rm -f $(NAME)

fclean: clean
	rm -f $(LIBFT)

re: clean all