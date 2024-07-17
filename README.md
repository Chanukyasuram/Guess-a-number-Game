# Guess a Number Game

## Overview
This project is a console-based game written in C++ where players guess a randomly generated number between 1 and 100. The game provides feedback on the player's guesses, including hints after a certain number of attempts, and maintains a leaderboard to track players' scores.

## Features
- **User Input and Random Number Generation**: 
  - Players enter their name to start the game.
  - A random number between 1 and 100 is generated for the player to guess.
- **Game Mechanics**:
  - Players have up to six attempts to guess the correct number.
  - Feedback is provided on whether the guess is too high or too low, with additional hints if the player is close.
  - Special hints are given after the 3rd and 5th failed attempts.
- **Leaderboard**:
  - A map is used to maintain the leaderboard, storing player names and their scores.
  - Players' scores are incremented each time they successfully guess the number.
- **Menu System**:
  - A simple menu allows players to choose between playing the game, viewing the leaderboard, or exiting the application.

## Tech Stack
- **C++**: The primary programming language used for developing the application.
- **Data Structures and Algorithms (DSA)**: Utilized for implementing efficient game mechanics and leaderboard management.

## How to Run
1. **Clone the repository**:
    ```bash
    git clone <repository_url>
    ```
2. **Navigate to the project directory**:
    ```bash
    cd guess-a-number-game
    ```
3. **Compile the code**:
    ```bash
    g++ -o guess_game main.cpp
    ```
4. **Run the executable**:
    ```bash
    ./guess_game
    ```

## Code Explanation
### Main Game Logic
- **Function: `playGame()`**
    - Prompts the user to enter their name.
    - Generates a random number between 1 and 100.
    - Allows the user up to six attempts to guess the number.
    - Provides feedback on the guesses, including hints for closer guesses.
    - Updates the leaderboard if the player guesses correctly.

### Leaderboard Management
- **Function: `displayLeaderBoard()`**
    - Displays the current leaderboard, showing player names and their scores.

### Menu Display
- **Function: `displayMenu()`**
    - Displays a menu with options to play the game, view the leaderboard, or exit.
    - Uses a loop to continue displaying the menu until the user chooses to exit.
