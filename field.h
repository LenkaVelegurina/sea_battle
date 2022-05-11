#pragma once

#include <vector>
#include <iostream>
#include "ship.h"

class Field {
private:
    const int field_size_ = 10;
    std::vector<std::vector<Ship*>> field_;
    std::vector<std::vector<char>> field_to_show_;
    std::vector<std::vector<char>> shot_field_;
public:
    Field();

    void show_field();

    void show_field_with_shots();

    void set_ships();

    void get_point(char& letter, short& number);

    static void get_point_for_shot(char& letter, short& number);

    bool check_placement(char letter, short number, const std::string& orientation, ShipType type);

    void get_point_with_orientation(char& letter, short& number, std::string& orientation, ShipType type);

    bool check_alive();

    std::string get_shot(int x, int y, Field& other);

    std::string get_verdict(int x, int y, Field& other);
};
