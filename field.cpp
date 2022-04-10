#include "field.h"

Field::Field() {
    field_to_show_ = std::vector<std::vector<char>>(this->field_size_, std::vector<char>(this->field_size_, '.'));
}

void Field::show_field() {
    for (int i = 0; i < this->field_size_; ++i) {
        for (int j = 0; j < this->field_size_; ++j) {
            std::cout << this->field_to_show_[i][j];
        }
        std::cout << '\n';
    }
}

void Field::set_ships() {
    //TODO: change - factory for example
    char letter;
    int number;
    std::string orientation;
    int field_size = 10;
    //this->field_to_show_ = std::vector<std::vector<char>> (field_size, std::vector<char>(field_size, '.'));
    for (int i = 0; i < 4; ++i) {
        std::cout << "Enter the coordinates of the start (upper left corner) of the single-deck ship:\n";
        std::cin >> letter >> number;
        //TODO: check format
        //TODO: check placement
        for (int j = 0; j < 1; ++j) {
            this->field_to_show_[number - 1][letter - 'a'] = 'o';
        }
    }
    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter the coordinates of the start (upper left corner)"
                     " and orientation (vertical or horizontal) of the double-deck ship:\n";
        std::cin >> letter >> number >> orientation;
        //TODO: check format
        //TODO: check placement

        if (orientation == "vertical") {
            for (int j = 0; j < 2; ++j) {
                this->field_to_show_[number - 1 + j][letter - 'a'] = 'o';
            }
        } else if (orientation == "horizontal") {
            for (int j = 0; j < 2; ++j) {
                this->field_to_show_[number - 1][letter - 'a' + j] = 'o';
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        std::cout << "Enter the coordinates of the start (upper left corner)"
                     " and orientation (vertical or horizontal) of the three-deck ship:\n";
        std::cin >> letter >> number >> orientation;
        //TODO: check format
        //TODO: check placement and orient

        if (orientation == "vertical") {
            for (int j = 0; j < 3; ++j) {
                this->field_to_show_[number - 1 + j][letter - 'a'] = 'o';
            }
        } else if (orientation == "horizontal") {
            for (int j = 0; j < 3; ++j) {
                this->field_to_show_[number - 1][letter - 'a' + j] = 'o';
            }
        }
    }
    for (int i = 0; i < 1; ++i) {
        std::cout << "Enter the coordinates of the start (upper left corner)"
                     " and orientation (vertical or horizontal) of the four-deck ship:\n";
        std::cin >> letter >> number >> orientation;
        //TODO: check format
        //TODO: check placement
        if (orientation == "vertical") {
            for (int j = 0; j < 4; ++j) {
                this->field_to_show_[number - 1 + j][letter - 'a'] = 'o';
            }
        } else if (orientation == "horizontal") {
            for (int j = 0; j < 4; ++j) {
                this->field_to_show_[number - 1][letter - 'a' + j] = 'o';
            }
        }
    }
}

bool Field::check_alive() {
    for (int i = 0; i < this->field_size_; ++i) {
        for (int j = 0; j < this->field_size_; ++j) {
            if (this->field_to_show_[i][j] == 'o') {
                return true;
            }
        }
    }
    return false;
}

bool Field::get_shot(int x, int y) {
    if(this->field_to_show_[x][y] == 'o'){
        this->field_to_show_[x][y] = '*';
        return true;
    }
    return false;
}
