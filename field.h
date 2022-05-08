#pragma once

#include <vector>
#include <iostream>
#include "ship.h"

class Field {
private:
    const int field_size_ = 10;
    std::vector<std::vector<Ship*>> field_;
    std::vector<std::vector<char>> field_to_show_;
public:
    Field();

    void show_field();

    void set_ships();

    bool check_alive();

    bool get_shot(int x, int y);
};

void get_point(char& letter, short& number);

void get_orientation(std::string& orientation);