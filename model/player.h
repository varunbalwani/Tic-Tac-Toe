#pragma once
#include "playingPiece.h"
#include<bits/stdc++.h>
using namespace std;
class Player {
    string name;
    PlayingPiece* piece;
    public:
        Player(string n, PlayingPiece* p) : name(n), piece(p) {}

        string getName() const {
            return name;
        }
        PlayingPiece* getPiece() const {
            return piece;
        }
};