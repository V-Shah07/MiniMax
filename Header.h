#pragma once

void printBoard(char* board);

int determineMoveSlow(char*, bool, int*);
int determineMoveFast(char*, bool, int*);
char isWin(char* board);

enum type {maximizing, minimizing};

const char sym[2] = { 'x','o' };
const int score[2] = {10, -10 };
const type state[2] = { maximizing, minimizing };