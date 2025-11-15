#include "model/model.h"
#include "TicTacToe.h"
using namespace std;

int main(){
    TicTacToe game;
    game.InitializeGame();
    string winner = game.startGame();
    cout<<"Winner: "<< winner << endl;
}