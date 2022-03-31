# MiniMax

## How to run:
1. Clone this repository 
2. Go to the directory that you want this program in and type "git clone " followed by the "HTTPS" link you can find from the "Code" button
3. Enter the "MiniMax" folder using ```cd MiniMax```
4. Compile using this command: ```g++ -o TicTacToe ABP.cpp DFS.cpp funcs.cpp main.cpp```
5. In terminal, type: ```./TicTacToe.exe```

## How it works:

There are two things that you can do. Either play a game against the algorithm or run multiple tests 

### Playing against the algorithm

It works as a standard tic tac toe game. You enter a number from 1-9 and then the computer places its character. To figure out where it should put its character, it uses DFS to find out the best possible place. The DFS algorithm develops a tree based on the current status of the board, and if a certain possibility results in a loss for the computer, it erradicates that part of the tree. After finishing the DFS portion, I copied it into another file, but added alpha-beta pruning, a simple, yet highly effective technique to boost the efficiency of the algorithm. Essentially, it uses a variable, alpha to store a maximum, and beta to store a minimum, and if alpha > beta, it prunes(removes) that part of the tree. This has an enourmous benefit on the efficiently of the program. 

### Multiple Tests

This simulates many games where the computer uses its algorithm, and a fake dummy player randomly chooses where it wants to put its character. Even after 10,000 tests, the algorithm usually results in a 85%+ win rate with a 0% loss rate. 