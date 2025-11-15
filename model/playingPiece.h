#pragma once
#include "pieceType.h"


class PlayingPiece {
public:
    PieceType type;

    // Protected constructor so inherited classes can call it
    PlayingPiece(PieceType t) : type(t) {}

public:
    PieceType getType() const {
        return type;
    }
};