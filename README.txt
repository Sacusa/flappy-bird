***************************************************************************************************

Flappy Bird for Command-Prompt

***************************************************************************************************
Contents:

1. Introductiom
2. System requirements
3. How to play
4. Understanding the code

***************************************************************************************************
1. Introduction

This is a version of the game Flappy Bird for Command-Prompt on Windows. The game uses only the
standard C++ library, and no graphics library. It is a fully functional stand-alone program.

Features:
# 3 difficulty levels to choose from
# 'Bell' sound on every successful passing of a pipe
# High score system which saves the top 5 high scores
# In-Game instructions

***************************************************************************************************
2. System requirements

# Processor: Dual core CPU
# OS: Micrsoft Windows

This being a Command Prompt game doesn't have any other special requirements.

***************************************************************************************************
3. How to play

# The objective of this game is to get the bird across the pipes safely, without it touching any
  pipe or the ground.

# To make the bird fly up, simply press the Spacebar.

# For every pipe the bird safely passes, one point is awarded.

# Touching any pipe or the ground ends the game instantly.

# The score is displayed in the bottom-left corner of the score.

# To leave the game in the middle, simply press the Escape key.

These instructions can also be viewed in-game from the main menu.

***************************************************************************************************
4. Understanding the code

While making the game, i tried to keep the code as simple as possible.

The class 'pipe', as the name suggests, contains the various properties and functions of the pipes.
Because there can be atmost three pipes on the screen at any given time, i've made three objects of
this class.

The class 'bird', again, contains the properties and functions of the bird. As a consequence, there
is only a single object for it.

I've added comments for what every function and most variables do.

Also, the game is multi-threaded. There is a separate thread for the input function. This is
because there is no way i could've made the game run and wait for input simultaneously.

***************************************************************************************************