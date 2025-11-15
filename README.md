# 🎮 Tic-Tac-Toe Game (C++ | OOP | SOLID Principles)

A fully object-oriented implementation of the classic **Tic-Tac-Toe** game written in C++.  
This project follows **SOLID principles**, clean architecture, and proper modular class design.

---

## 🚀 Features

- ✔️ 3×3 Tic-Tac-Toe playable in the terminal  
- ✔️ Two-player turn-based gameplay  
- ✔️ Clean and modular object-oriented architecture  
- ✔️ User input like `1,2` (row, col)  
- ✔️ Automatic board rendering after each move  
- ✔️ Winner detection & invalid-move handling  
- ✔️ Extensible design — easy to add new piece types or game variations  

---

## 🧩 Object-Oriented Design & Principles Used

This project is built using standard OOP and SOLID principles:

### 🔹 Single Responsibility Principle (SRP)
Each class handles a single purpose:
- `Board` → grid management  
- `Player` → player identity  
- `PlayingPiece` → piece abstraction  
- `TicTacToe` → game controller  

### 🔹 Open/Closed Principle (OCP)
You can add new pieces (Triangle, Square, etc.)  
or expand board size without modifying existing classes.

### 🔹 Liskov Substitution Principle (LSP)
`PlayingPieceX` and `PlayingPieceO` can replace the base `PlayingPiece` without breaking functionality.

### 🔹 Encapsulation
Internal data is hidden behind getters—preventing direct external modification.

### 🔹 Separation of Concerns
Game engine, model classes, and UI logic are all clearly separated.

---

## 🏗️ Architecture Overview

### **Classes**
- **PlayingPiece (Base Class)**  
  - `PlayingPieceX`  
  - `PlayingPieceO`  
- **Player** (name + piece)  
- **Board** (grid, placement, printing, free cell logic)  
- **TicTacToe** (game loop, turn handling, winner checking)

### **Flow**
1. `main.cpp` creates a `TicTacToe` object  
2. Calls `InitializeGame()`  
3. Calls `startGame()` → the main game loop  
4. Players enter moves like `1,2`  
5. Board updates and winner is detected  

---

## 📦 Folder Structure

