##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

NAME	= lib_arcade_Centiped.so

RM	= rm -f

SRCS	= ./src/Centiped.cpp \

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ../
CPPFLAGS += -I ./include
CPPFLAGS += -I ../../
CPPFLAGS += -fpic -Wall -Wextra
LDFLAGS = -shared

all: $(NAME)
	mv $(NAME) ../

$(NAME): $(OBJS)
	g++ $(LDFLAGS) -o $(NAME) $(OBJS) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re