# Bridg-It (C++)

A graphical C++ implementation of the classic **Bridg-It** connection game, built with **graphics.h**.  
The game supports **Player vs Player** and **Player vs Computer**, with **Easy** and **Hard** AI difficulty.

Developed as a team project (2 people), with work split across game logic, DFS win-checking, UI/menus and AI behavior.

---

## Gameplay

Bridg-It is a grid-based connection game. Each player places “bridges” on the board and tries to connect their opposite sides before the opponent.

This implementation includes:
- **Graphical UI** (`graphics.h`)
- **Interactive menus** (opponent selection, difficulty, board size, colors)
- **Board sizes:** `5`, `7`, `9`
- **Win detection using DFS** (Depth-First Search) on the board state

---

## AI Opponent

### Easy Mode
The computer uses a **random valid placement** approach (with constraints) and then checks win conditions.

### Hard Mode
The computer uses a **heuristic strategy**:
- tries immediate winning moves first (simulates moves and checks win with DFS)
- otherwise searches positions to improve its chances
- uses a board evaluation function:
  - rewards consecutive/connected placements
  - balances offense (own connections) and defense (reducing opponent advantage) via:
    `EvaluareTabla(player2) - EvaluareTabla(player1)`

Key functions involved:
- `CalculatorRandom(...)`
- `CalculatorStrategie(...)`
- `EvaluareTabla(...)`

---

## Win Checking (DFS)

Win conditions are verified via DFS traversal over the grid:
- `DFS_Player_1(...)` + `Parcurgere_DFS_Player1(...)`
- `DFS_Player_2(...)` + `parcurgere_DFS_player2(...)`

This ensures efficient detection of a completed connection path.

---

## Tech Stack

- **C++**
- **WinBGIm** (`graphics.h`, `winbgim.h`)
- `conio.h` for keyboard input
- Windows-specific functions (e.g., `Beep`)

> Note: this project is intended for Windows setups compatible with WinBGIm.

---

## How to Build & Run

### Option A (Recommended): Code::Blocks + WinBGIm
1. Install Code::Blocks (MinGW)
2. Set up **WinBGIm / graphics.h** in your compiler
3. Create a C++ project and add `main.cpp`
4. Build & Run

### Option B: g++ (only if WinBGIm is configured)
```bash
g++ -std=c++17 -o bridg_it main.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
./bridg_it
