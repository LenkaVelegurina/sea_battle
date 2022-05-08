#pragma once

enum class ShipType {
    kSingleDeck,
    kTwoDeck,
    kThreeDeck,
    kFourDeck,
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