NAME		=	ex01

UNAME_S		:=	$(shell uname -s)

# Default settings
CC			=	c++
FLAG		=	-Wall -Wextra -Werror -std=c++98

# Settings for florencecousergue macOS
ifeq ($(UNAME_S), Darwin)
CC			=	c++
FLAG		=	-Wall -Wextra -Werror -std=c++98
endif

C_FILES		=	main.cpp Serializer.cpp

OBJ_DIR		=	builds

OBJS		=	$(addprefix $(OBJ_DIR)/, $(C_FILES:.cpp=.o))

DEPS		=	$(OBJS:.o=.d)

all:		$(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(FLAG) -MMD -MP -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJ_DIR)/*.o $(DEPS)
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

-include $(DEPS)

.PHONY:	all clean fclean re
