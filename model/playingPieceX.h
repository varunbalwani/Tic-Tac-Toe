#pragma once

#include "playingPiece.h"

class PlayingPieceX : public PlayingPiece {
    public:
        PlayingPieceX() : PlayingPiece(PieceType::X) {}
};