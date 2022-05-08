#pragma once

enum class ShipType {
    kSingleDeck = 1,
    kTwoDeck = 2,
    kThreeDeck = 3,
    kFourDeck = 4,
};

enum class PlayerNumber {
    kFirstPlayer,
    kSecondPlayer
};

class Ship {
public:
    Ship() = default;

    Ship(ShipType, PlayerNumber);

    bool get_shot(int x, int y);

private:
    PlayerNumber player_number_;
    ShipType type_;
};