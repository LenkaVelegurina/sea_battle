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

void get_point(char& letter, short& number) {
    bool verdict = false;
    while (!verdict) {
        std::cin >> letter >> number;
        verdict = true;
        if (!('a' <= letter && letter <= 'j' && 1 <= number && number <= 10)) {
            std::cout << "Position entered in invalid format, please try again:\n";
            verdict = false;
        }
    }
}

void get_orientation(std::string& orientation) {
    bool verdict = false;
    while (!verdict) {
        std::cin >> orientation;
        verdict = true;
        if (!(orientation == "vertical" || orientation == "horizontal")) {
            std::cout << "Orientation entered in invalid format, please try again:\n";
            verdict = false;
        }
    }
}

void Field::set_ships() {
    //TODO: change - factory for example
    char letter;
    short number;
    std::string orientation;
    int field_size = 10;
    //this->field_to_show_ = std::vector<std::vector<char>> (field_size, std::vector<char>(field_size, '.'));
    for (int i = 0; i < 4; ++i) {
        std::cout << "Enter the coordinates of the start (upper left corner) of the single-deck ship:\n";
        get_point(letter, number);
        //TODO: check placement
        for (int j = 0; j < 1; ++j) {
            this->field_to_show_[number - 1][letter - 'a'] = 'o';
        }
    }
    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter the coordinates of the start (upper left corner)"
                     " and orientation (vertical or horizontal) of the double-deck ship:\n";
        get_point(letter, number);
        get_orientation(orientation);

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
        get_point(letter, number);
        get_orientation(orientation);
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
        get_point(letter, number);
        get_orientation(orientation);
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
    if (this->field_to_show_[x][y] == 'o') {
        this->field_to_show_[x][y] = '*';
        return true;
    }
    return false;
}
