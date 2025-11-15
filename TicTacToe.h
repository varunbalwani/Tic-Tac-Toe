#pragma once
#include "model/Player.h"
#include "model/Board.h"
#include "model/playingPieceX.h"
#include "model/playingPieceO.h"
#include <deque>
#include <vector>
#include <string>
using namespace std;
class TicTacToe {
    deque<Player> players;
    Board board;
public:
    TicTacToe() : board(3) {}  
    void InitializeGame() {
        // auto piece1 = PlayingPieceX();
        PlayingPieceX* piece1 = new PlayingPieceX();
        Player player1("Player 1", piece1);
        PlayingPieceO* piece2 = new PlayingPieceO();
        Player player2("Player 2", piece2);
        players.push_back(player1);
        players.push_back(player2);

        board = Board(3); 
    };

    string startGame() {
        bool noWinnerFound = true;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while(noWinnerFound)
        {
            Player player = players.front();
            players.pop_front();
            board.printBoard();
            vector<pair<int,int>> freeCells = board.getFreeCells();

            if(freeCells.size() == 0) {
                noWinnerFound = false;
                continue;
            }
            cout<<"Player: "<< player.getName() << ", enter your move (row,col): ";
            string input;
            
            getline(cin, input);
            
            //divide based on ,
            int row = stoi(input.substr(0, input.find(',')));
            int col = stoi(input.substr(input.find(',') + 1));
            bool successfullyAdded = board.placePiece(row, col, player.getPiece());
            if(!successfullyAdded){
                players.push_front(player);
                continue;
            }
            players.push_back(player);
            
            bool winner = isWinner(row, col, player.getPiece()->getType());
            if(winner) {
                return player.getName() ;
            }
        }
        return "Tie";
    }

    bool isWinner(int row, int col, PieceType type) {
        bool rowMatch = true;
        bool colMatch = true;
        bool diag1Match = true;
        bool diag2Match = true;

        for(int i=0;i<board.size;i++)
        {
            if(board.board[row][i] == nullptr || board.board[row][i]->getType() != type) {
                rowMatch = false;
            }
            if(board.board[i][col] == nullptr || board.board[i][col]->getType() != type) {
                colMatch = false;
            }
            if(board.board[i][i] == nullptr || board.board[i][i]->getType() != type) {
                diag1Match = false;
            }
            if(board.board[i][board.size - i - 1] == nullptr || board.board[i][board.size - i - 1]->getType() != type) {
                diag2Match = false;
            }
        }
        return rowMatch || colMatch || diag1Match || diag2Match;
    }
};
