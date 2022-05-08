#pragma once

#include <string>
#include "ship_factory.h"
#include "field.h"

class Player {
private:
    std::string password_;
    PlayerNumber player_number_;
    Field field_;

    bool check_password(const std::string&);

public:
    explicit Player(std::string, PlayerNumber);

    void authorization();

    void make_move(Player& other);

    void set_ships();

    void show_field();

    bool check_alive();

    bool get_shot(int x, int y);
};