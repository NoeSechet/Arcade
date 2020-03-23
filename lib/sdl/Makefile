##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME	= lib_arcade_sdl.so


RM	= rm -f

SRCS	= ./src/Graphic_sdl.cpp \

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ../
CPPFLAGS += -I ./include
CPPFLAGS += -I ../../global_include
CPPFLAGS += -fpic -Wall -Wextra
LDFLAGS = -shared

SFMLNCURSESFLAGS = `sdl2-config --libs` -lSDL2 -Wall -lSDL2_ttf -lSDL2_image -lSDL2_mixer

all: $(NAME)
	mv $(NAME) ../

$(NAME): $(OBJS)
	g++ $(LDFLAGS) -o $(NAME) $(OBJS) $(SFMLNCURSESFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re