# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/08 15:02:32 by DERYCKE           #+#    #+#              #
#    Updated: 2018/06/22 00:45:59 by DERYCKE          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIBFT = libft/libft.a
FILES =  main	parser	error	utils	sort_functions	\
		recursive lst_ft	display	 	set_time	\
		long_format		little_display	get_size	\
		init	grp_usr		verification	permissions
SRC = $(addsuffix .c, $(FILES))

all: $(NAME)

$(NAME): $(SRC)
	cd libft/ && $(MAKE)
	gcc -Wall -Werror -Wextra -o $@ $^ $(LIBFT)
	
clean:
	cd libft/ && $(MAKE) clean

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all