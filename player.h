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

    void show_field_with_shots();

    bool check_alive();

    std::string get_shot(int x, int y, Player& other);
};
