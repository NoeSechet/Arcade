# Arcade
Arcade Epitech Project. Creating graphical libraries + game libraries compatible with each other

In this project we had to recreate iconic games: Centiped and SolarFox.
While the player was in-game, he had to be able to switch between the 3 different graphical libraries we had implemented. 
The libraries are: SFML, SDL and NCURSES.

The graphical aspect of the games is very simple, but the architecture behind is complex and easy to re-use at the same time.

Our implementations of the games and the graphical libraries had to be able to work with different groups:
Our games had to work with THEIR graphical libraries (OpenGL, Vulcan... (I know those are specifications yes))
  and our graphical libraries had to be able to make their games work too.
  The inverse also had to work (their games with our graphical libs, and their graphical libs with our games)

Those requirements meant that the graphical part had to be completely separate from the game state. In order to make the 2 communicate
together we had what we called a "core", receiving and sending messages from one another.
