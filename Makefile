# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschille <jschille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/30 20:21:02 by jschille          #+#    #+#              #
#    Updated: 2019/03/31 15:26:39 by jschille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ld_stack.a

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c src/service/*.c -I./includes/
	cp *.o ./bin/
	rm -f *.o
	ar rc $(NAME) ./bin/*.o
clean:
	rm -f ./bin/*.o
fclean: clean
	rm -f $(NAME)
re: fclean all