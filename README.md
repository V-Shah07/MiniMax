# MiniMax

## How to run:
1. Clone this repository 
2. Go to the directory that you want this program in and type "git clone " followed by the "HTTPS" link you can find from the "Code" button
3. Enter the "MiniMax" folder using ```cd MiniMax```
4. Compile using this command: ```g++ -o TicTacToe ABP.cpp DFS.cpp funcs.cpp main.cpp```
5. In terminal, type: ```./TicTacToe.exe```
### Alternatively:
1. Download the files of this repository by zipping it, and then open that folder through file explorer
2. If you are on a linux based shell: ```g++ -o TicTacToe ABP.cpp DFS.cpp funcs.cpp main.cpp``` should compile and ```./TicTacToe.exe``` should run it
3. If you are on windows: ```gcc ABP.cpp DFS.cpp funcs.cpp main.cpp -o TicTacToe.exe``` should compile and ```TicTacToe.exe``` should run it

## How it works:

There are two things that you can do. Either play a game against the algorithm or run multiple tests 

### Playing against the algorithm

* Standard Tic Tac Toe rules
    - Spots are numbered 1-9
* DFS is used to find best possible place to move
* Algorithm develops a tree based on status of the board
    - When certain possibilities result in a loss, it is removed from that part of the tree
* I made a separate file to test alpha-beta pruning
    - It uses alpha to store a maximum move and beta to store a minimum and if alpha > beta, it prunes(removes) that part of the tree
    - It has a huge impact on efficiency and is shown when iteration counts are displayed

With this Mini-Max implentation with DFS, the computer will **never** lose, and always win or tie.
### Multiple Tests
* Many games are simulated, you get to choose how many
    - Even after 10,000 tests, the algorithm has great results
        - Almost always a 85%+ win rate
        - Gauranteed to have a 0% loss rate