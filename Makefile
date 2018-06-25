# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/08 15:02:32 by DERYCKE           #+#    #+#              #
#    Updated: 2018/06/25 13:32:09 by dideryck         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIBFT = libft/libft.a
FILES =  main	parser	error	utils	sort_ft	\
		recursive lst_ft	display	 	set_time	\
		long_format		get_size	\
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