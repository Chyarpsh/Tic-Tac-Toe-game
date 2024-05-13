Welcome to the Tic-Tac-Toe Game repository! This simple command line game allows players to enjoy the classic game of Tic-Tac-Toe against each other.

How to Play:

1)Clone or download the repository to your local machine.
2)Navigate to the directory containing the game files.

Compile the game using a C++ compiler. For example:

g++ MoveStack.cpp GameState.cpp main.cpp -o tictactoe

Run the compiled executable:

./tictactoe

Follow the on-screen instructions to play the game. Players take turns making moves by entering the coordinates of the target cell. For example, entering "move 1 1" places the player's symbol in the middle cell of the board.
Features:

1)Two classes, MoveStack, and GameState, manage moves and game state.
2)MoveStack stores past moves for the ability to undo actions.
3)GameState represents the current state of the game, including the board and past moves.
4)Players can undo the last move if desired.
5)The game checks for win conditions after each move and terminates when a player wins or the game ends in a draw.

Files Included:

1)MoveStack.cpp: Implementation of the MoveStack class.
2)MoveStack.h: Header file for the MoveStack class.
3)GameState.cpp: Implementation of the GameState class.
4)GameState.h: Header file for the GameState class.
5)main.cpp: Main game loop and user interface.
6)testdriverMoveStack.cpp: Test driver for the MoveStack class.
7)testdriverGameState.cpp: Test driver for the GameState class.
8)results.pdf: Document containing the results of test cases.
9)README.md: This file providing instructions and information about the game.