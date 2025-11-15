#pragma once
#include <vector>
#include <iostream>
#include "playingPiece.h"

class Board {
public:
    int size;
    std::vector<std::vector<PlayingPiece*>> board;

    Board(int s) : size(s) {
        board = std::vector<std::vector<PlayingPiece*>>(s, std::vector<PlayingPiece*>(s, nullptr));
    }

    std::vector<std::pair<int,int>> getFreeCells() {
        std::vector<std::pair<int,int>> freeCells;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == nullptr) {
                    freeCells.push_back({i, j});
                }
                }
        }
        return freeCells;
    }

    void printBoard() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == nullptr) {
                    std::cout << " . ";
                } else if (board[i][j]->getType() == PieceType::X) {
                    std::cout << " X ";
                } else {
                    std::cout << " O ";
                }
                std::cout << "|";
                }
            std::cout << "\n";
        }
    }

    bool placePiece(int row, int col, PlayingPiece* piece) {
        if (row < 0 || row >= size || col < 0 || col >= size)
            return false;

        if (board[row][col] != nullptr)
            return false;

        board[row][col] = piece;
        return true;
    }
};
