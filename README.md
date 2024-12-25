# Tetris Game

## Group Members
- **Habibullah Khaliqyar**
- **Faiq Ayoubi**
- **Huzaifa Ahadi**

## Project Description
This project is an engaging and interactive Tetris game built using Raylib. The game features advanced gameplay mechanics, scoring, level progression, and an improved graphical interface with different colors for each tetromino. The user experience is enhanced with better input handling and animations.

## Features
- **Advanced Gameplay Mechanics**: Control falling blocks, fit them into a grid, and clear rows.
- **Scoring and Level Progression**: Earn points and advance to higher levels by clearing rows.
- **Improved Graphical Interface**: Different colors for each tetromino and better visual feedback.
- **Enhanced User Experience**: Better input handling and animations.

## Technical Architecture
The project is organized into several modules:
- **Main Module**: Handles the game loop, drawing, and user input.
- **Game Module**: Manages game logic, block movement, and game states.
- **Grid Module**: Manages the game grid, checks for row completion, and clears rows.
- **Block Module**: Manages individual blocks, their positions, rotations, and drawing.
- **Position Module**: Represents the position of blocks in the grid.
- **Color Module**: Defines colors for different tetrominoes.

The project contains 7 `.cpp` files and 5 header files that implement the core functionality of the Tetris game.
## Architecture Diagram
+-----------------------+
|        Main           |
| - Initialize Window   |
| - Game Loop           |
| - Draw                |
| - Handle Input        |
+-----------------------+
            |
            v
+-----------------------+
|        Game           |
| - Current Block       |
| - Next Block          |
| - Move Block          |
| - Rotate Block        |
| - Lock Block          |
| - Check Game Over     |
+-----------------------+
            |
            v
+-----------------------+
|        Grid           |
| - Initialize Grid     |
| - Draw Grid           |
| - Check Full Row      |
| - Clear Row           |
| - Move Rows Down      |
+-----------------------+
            |
            v
+-----------------------+
|        Block          |
| - Block Shapes        |
| - Get Positions       |
| - Draw Block          |
| - Rotate              |
| - Move                |
+-----------------------+
            |
            v
+-----------------------+
|       Position        |
| - Row                 |
| - Column              |
+-----------------------+
            |
            v
+-----------------------+
|        Color          |
| - Define Colors       |
| - Get Colors          |
+-----------------------+



## How to Run and Deploy the Project

### Prerequisites
- **Visual Studio Community 2022**
- **Raylib**
- **vcpkg** for package management

### Setup Instructions
1. **Ensure the following requirements are installed:**
  -**Visual Studio Community 2022**
  -**Raylib**
  -**vcpkg** for package management

2. **Clone the Repository**:
   
3. **Open the Project in Visual Studio**:
  -**Open Visual Studio Community 2022.**
  -**Open the TetrisGame project.**

4. **Build and Run the Project:**
  -**Build the solution in Visual Studio.**
  -**Run the project to start the game.**

### Detailed Documentation
1. **Initial Setup:**
  -**Install Raylib and vcpkg.**
  -**Set up Visual Studio for C++ development.**
2. **Game Logic**:
  -**Implement block movements and rotations.**
  -**Handle user inputs and keypress events.**

3. **Grid Management**:
  -**Manage and draw the game grid.**
  -**Implement collision detection and block placement logic.** 

4. **Scoring and Levels**:
  -**Implement scoring system and level progression.**
  -**Enhance rendering module for visual feedback.**

5. **Game Over and Restart Logic**:
  -**Implement game over conditions.**
  -**Provide options to restart the game.**

