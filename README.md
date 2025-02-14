# Hungry Snake Game

Welcome to the **Hungry Snake Game**! This project includes two versions of the game:
1. **Terminal Version**: A console-based version of the game.
2. **Graphical Version**: A graphical version built using the **SFML (Simple and Fast Multimedia Library)**.

Both versions are written in C++ and provide a fun and interactive experience where you control a snake to catch falling frogs.

---

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [How to Run](#how-to-run)
  - [Terminal Version](#terminal-version)
  - [Graphical Version](#graphical-version)
- [Gameplay](#gameplay)
- [Code Structure](#code-structure)
- [Dependencies](#dependencies)

---

## Introduction

The **Hungry Snake Game** is a fun and interactive game where the player controls a snake to catch falling frogs. The goal is to score as many points as possible by catching frogs before they reach the bottom of the screen. The game increases in speed as you progress, making it more challenging over time.

- **Terminal Version**: A simple console-based version of the game, perfect for quick play and learning the basics.
- **Graphical Version**: A more engaging version with graphics, sound effects, and a high-score system, built using SFML.

---

## Features

### Terminal Version
- **Simple Controls**: Use the `A` and `D` keys to move the snake left and right.
- **Dynamic Gameplay**: Frogs fall from random positions at increasing speeds.
- **Score Tracking**: Your score increases with each frog caught.
- **Game Over**: The game ends if a frog reaches the bottom without being caught.
- **Cross-Platform**: Works on both Windows and Unix-like systems.

### Graphical Version
- **Graphical Interface**: Built using SFML for rendering graphics and handling input.
- **Sound Effects**: Includes background music, eating sounds, and game-over sounds.
- **High Score System**: Tracks and displays the highest score achieved.
- **Interactive Menu**: Start and exit the game using the mouse.

---

## How to Run

### Terminal Version

#### Prerequisites
- A C++ compiler (e.g., `g++` or `clang++`).
- A terminal or command prompt.

#### Steps to Run
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/sedwna/Hungry-Snake-Adventure.git
   ```

2. **Compile the Code**:
   ```bash
   g++ -o hungry_snake_terminal main_terminal.cpp app_terminal.cpp snake_terminal.cpp frog_terminal.cpp -Iinclude
   ```

3. **Run the Game**:
   ```bash
   ./hungry_snake_terminal
   ```

4. **Follow the Instructions**:
   - At the prompt, type `s` to start the game.
   - Use `A` to move the snake left and `D` to move right.
   - Type `help` for a list of commands.

---

### Graphical Version

#### Prerequisites
- A C++ compiler (e.g., `g++` or `clang++`).
- **SFML Library** installed on your system.
- A terminal or command prompt.

#### Steps to Run
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/hungry-snake-game.git
   cd hungry-snake-game
   ```

2. **Install SFML** (if not already installed):
   - On **Ubuntu/Debian**:
     ```bash
     sudo apt-get install libsfml-dev
     ```
   - On **Windows**: Download SFML from [SFML's official website](https://www.sfml-dev.org/download.php) and set up the library.

3. **Compile the Code**:
   ```bash
   g++ -o hungry_snake_graphical main.cpp app.cpp game.cpp snake.cpp frog.cpp -Iinclude -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
   ```

4. **Run the Game**:
   ```bash
   ./hungry_snake_graphical
   ```

5. **Follow the Instructions**:
   - Use the mouse to click on the **Start** button to begin the game.
   - Use `A` to move the snake left and `D` to move right.
   - Click on the **Exit** button to quit the game.

---

## Gameplay

### Terminal Version
- **Objective**: Catch as many frogs (`*`) as possible with your snake (`^`).
- **Controls**:
  - `A`: Move the snake left.
  - `D`: Move the snake right.
- **Scoring**: Each frog caught increases your score by 1.
- **Game Over**: If a frog reaches the bottom of the screen without being caught, the game ends.

### Graphical Version
- **Objective**: Catch as many frogs as possible with your snake.
- **Controls**:
  - `A`: Move the snake left.
  - `D`: Move the snake right.
- **Scoring**: Each frog caught increases your score by 1.
- **Game Over**: If a frog reaches the bottom of the screen without being caught, the game ends.
- **High Score**: The game tracks and displays the highest score achieved.

---

## Code Structure

The project is organized into the following files:

### Terminal Version
- **`main_terminal.cpp`**: The entry point of the terminal version. Initializes the `App` class and starts the game loop.
- **`app_terminal.cpp`**: Contains the main logic for the terminal version, including the game loop, board rendering, and input handling.
- **`snake_terminal.cpp`**: Implements the snake's movement logic.
- **`frog_terminal.cpp`**: Handles the frog's random generation and movement.

### Graphical Version
- **`main.cpp`**: The entry point of the graphical version. Initializes the `App` class and starts the game loop.
- **`app.cpp`**: Contains the main menu logic, including rendering the menu and handling user input.
- **`game.cpp`**: Implements the main game logic, including rendering the game, handling collisions, and updating the score.
- **`snake.cpp`**: Handles the snake's movement and speed.
- **`frog.cpp`**: Manages the frog's position, speed, and random generation.
- **`include/`**: Contains header files (`app.hpp`, `game.hpp`, `snake.hpp`, `frog.hpp`) for class definitions.

---

## Dependencies

### Terminal Version
- **Standard C++ Library**: The project uses the standard C++ library for input/output, strings, and random number generation.

### Graphical Version
- **SFML Library**: The project uses SFML for graphics, window management, and audio.
  - Install SFML using your package manager or download it from the [official website](https://www.sfml-dev.org/).
- **Standard C++ Library**: The project uses the standard C++ library for input/output, strings, and random number generation.

---

