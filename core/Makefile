##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME	= arcade

CC	= g++

RM	= rm -f

SRCS	=	./src/main.cpp \
			./src/LibraryManagor.cpp	\
			./src/Core.cpp \
			./coremenu/CoreMenu.cpp \

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include
CPPFLAGS += -I ../global_include
CPPFLAGS += -Wall -Wextra -g3

all: $(NAME)
	mv $(NAME) ../

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -ldl -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
