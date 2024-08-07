# MasterMind Game

## Overview
This is an implementation of the MasterMind game in C++. In this game, the computer generates a secret code of four colors chosen from six possible colors (red, blue, yellow, purple, white, and orange). The player's objective is to guess the code within a limited number of attempts by receiving feedback after each guess.

## Features
- The computer generates a random code consisting of four colors.
- Players make guesses by entering a sequence of four characters representing colors.
- Feedback is provided after each guess, indicating how many colors are correct and how many of those are in the correct position.
- The game ends when the player correctly guesses the code or reaches the maximum number of allowed guesses (default is 6).

## How to Play
1. **Starting the Game:**
   - The game starts with a welcoming message explaining the available colors and instructions to guess the code.
   - A random code is generated by the computer.

2. **Making Guesses:**
   - Players enter their guesses by typing a sequence of characters corresponding to the colors (e.g., "rwby" for red, white, blue, yellow).
   - After each guess, the game provides feedback indicating how close the guess was to the actual code.

3. **Feedback:**
   - Feedback consists of two numbers:
     - The first number represents how many colors are in the correct position.
     - The second number represents how many colors are correct but in the wrong position.
   - Players use this feedback to refine their subsequent guesses.

4. **End of Game:**
   - The game ends when the player correctly guesses the code (all four colors in the correct positions) or after a maximum number of guesses (default 6) is reached.
   - The correct code is revealed if the player fails to guess it.

## Implementation Details
- **Dependencies:** This game uses standard C++ libraries including `<iostream>`, `<vector>`, `<string>`, `<cstdlib>`, and `<ctime>`.
- **Classes and Functions:**
  - `enum color`: Defines six different colors used in the game.
  - `class Code`: Represents the secret code and includes methods to generate the code randomly and convert it to a string.
  - `class Player`: Represents the player and includes methods to make guesses, retrieve the current guess, and receive feedback on guesses.
  - `main()`: Implements the game loop, where the player interacts with the computer to guess the code and receive feedback.

## Getting Started
To run the game:
- Compile the source code (`mastermind.cpp`) using a C++ compiler.
- Execute the compiled binary.
