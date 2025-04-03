# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 13:00:43 by fcouserg          #+#    #+#              #
#    Updated: 2024/11/24 18:44:15 by fcouserg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   replace

CC          =   c++

FLAG        =   -std=c++98 -Wall -Wextra -Werror

C_FILES     =   main.cpp Sed.cpp

OBJ_DIR     =   builds

OBJS        =   $(addprefix $(OBJ_DIR)/, $(C_FILES:.cpp=.o))

DEPS        =   $(OBJS:.o=.d)

all:		$(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(FLAG) -MMD -MP -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJ_DIR)/*.o $(DEPS) rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

-include $(DEPS)

.PHONY:	all clean fclean re