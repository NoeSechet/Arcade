##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME	= lib_arcade_ncurses.so


RM	= rm -f

SRCS	= ./src/Graphic_ncurses.cpp \

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ../
CPPFLAGS += -I ./include
CPPFLAGS += -I ../../global_include
CPPFLAGS += -fpic -Wall -Wextra
LDFLAGS = -shared

all: $(NAME)
	mv $(NAME) ../

$(NAME): $(OBJS)
	g++ $(LDFLAGS) -o $(NAME) $(OBJS) -lncurses

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re