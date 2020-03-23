##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

all:	core games graphicals

core:
	make -C core

games:
	make -C games/solar_fox
	make -C games/centiped

graphicals:
	make -C lib/ncurses
	make -C lib/sfml


clean:
	make clean -C core
	make clean -C games/solar_fox
	make clean -C games/centiped
	make clean -C lib/ncurses
	make clean -C lib/sfml

fclean: clean
	make fclean -C core
	make fclean -C games/solar_fox
	make fclean -C games/centiped
	make fclean -C lib/ncurses
	make fclean -C lib/sfml

 re:	fclean all

 .PHONY: all core games graphicals clean fclean re