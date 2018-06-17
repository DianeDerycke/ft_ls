# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/08 15:02:32 by DERYCKE           #+#    #+#              #
#    Updated: 2018/06/17 03:19:21 by DERYCKE          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIBFT = libft/libft.a
FILES =  main	parser	error	tools	sort_functions	\
		recursive lst_ft	display	 	set_time	\
		long_format		little_display	get_size	\
		init	grp_usr
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