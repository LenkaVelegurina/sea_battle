#include "field.h"

Field::Field() {
    field_to_show_ = std::vector<std::vector<char>>(this->field_size_,
                                                    std::vector<char>(this->field_size_, '.'));
    shot_field_ = std::vector<std::vector<char>>(this->field_size_,
                                                 std::vector<char>(this->field_size_, '.'));
}

void Field::show_field() {
    std::cout << "   ";
    for (char i = 'a'; i <= 'j'; ++i) {
        std::cout << i;
    }
    std::cout << '\n';
    for (int i = 0; i < this->field_size_; ++i) {
        std::cout << i + 1 << ((i == 9) ? " " : "  ");
        for (int j = 0; j < this->field_size_; ++j) {
            std::cout << this->field_to_show_[i][j];
        }
        std::cout << '\n';
    }
}

void Field::show_field_with_shots() {
    std::cout << "   ";
    for (char i = 'a'; i <= 'j'; ++i) {
        std::cout << i;
    }
    std::cout << '\n';
    for (int i = 0; i < this->field_size_; ++i) {
        std::cout << i + 1 << ((i == 9) ? " " : "  ");
        for (int j = 0; j < this->field_size_; ++j) {
            std::cout << this->shot_field_[i][j];
        }
        std::cout << '\n';
    }
}

bool Field::check_placement(char letter, short number, const std::string& orientation, ShipType type) {
    if (orientation == "vertical") {
        for (int i = number - 1; i < number + (short) type; ++i) {
            if (i >= 1 && i <= 10) {
                if (field_to_show_[i - 1][letter - 'a'] != '.') {
                    return false;
                }
                if (letter > 'a' && field_to_show_[i - 1][letter - 'b'] != '.') {
                    return false;
                }
                if (letter < 'j' && field_to_show_[i - 1][letter - 'a' + 1] != '.') {
                    return false;
                }
            }
        }
    } else if (orientation == "horizontal") {
        for (int i = letter - 1; i < letter + (short) type + 1; ++i) {
            if (i >= 'a' && i <= 'j') {
                if (field_to_show_[number - 1][i - 'a'] != '.') {
                    return false;
                }
                if (number > 1 && field_to_show_[number - 2][i - 'a'] != '.') {
                    return false;
                }
                if (number < 10 && field_to_show_[number][i - 'a'] != '.') {
                    return false;
                }
            }
        }
    }
    return true;
}

void Field::get_point_for_shot(char& letter, short& number) {
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

void Field::get_point(char& letter, short& number) {
    bool verdict = false;
    while (!verdict) {
        std::cin >> letter >> number;
        verdict = true;
        if (!('a' <= letter && letter <= 'j' && 1 <= number && number <= 10)) {
            std::cout << "Position entered in invalid format, please try again:\n";
            verdict = false;
        } else if (field_to_show_[number - 1][letter - 'a'] != '.') {
            std::cout << "This position is already occupied by a ship, please try again:\n";
            verdict = false;
        } else if (!check_placement(letter, number, "horizontal", ShipType::kSingleDeck)) {
            std::cout << "There is already a ship near this position, please try again:\n";
            verdict = false;
        }
    }
}


void Field::get_point_with_orientation(char& letter, short& number, std::string& orientation, ShipType type) {
    bool verdict = false;
    while (!verdict) {
        std::cin >> letter >> number;
        std::cin >> orientation;
        verdict = true;
        if (!('a' <= letter && letter <= 'j' && 1 <= number && number <= 10)) {
            std::cout << "Position entered in invalid format, please try again:\n";
            verdict = false;
        } else if (!(orientation == "vertical" || orientation == "horizontal")) {
            std::cout << "Orientation entered in invalid format, please try again:\n";
            verdict = false;
        } else if (orientation == "horizontal" && letter + (int) type > 'j' + 1 ||
                   orientation == "vertical" && number + (int) type - 1 > 11) {
            std::cout << "The ship goes out of bounds, please try again:\n";
            verdict = false;
        } else if (!check_placement(letter, number, "horizontal", type)) {
            std::cout << "There is already a ship near this position, please try again:\n";
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
        show_field();
    }
    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter the coordinates of the start (upper left corner)"
                     " and orientation (vertical or horizontal) of the double-deck ship:\n";
        get_point_with_orientation(letter, number, orientation, ShipType::kTwoDeck);

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
        show_field();
    }
    for (int i = 0; i < 2; ++i) {
        std::cout << "Enter the coordinates of the start (upper left corner)"
                     " and orientation (vertical or horizontal) of the three-deck ship:\n";
        get_point_with_orientation(letter, number, orientation, ShipType::kThreeDeck);

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
        show_field();
    }
    for (int i = 0; i < 1; ++i) {
        std::cout << "Enter the coordinates of the start (upper left corner)"
                     " and orientation (vertical or horizontal) of the four-deck ship:\n";
        get_point_with_orientation(letter, number, orientation, ShipType::kFourDeck);

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
        show_field();
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

std::string Field::get_verdict(int x, int y, Field& other) {
    std::vector<std::pair<int, int>> coords;
    coords.emplace_back(x, y);
    int t_x = x - 1, t_y = y;
    while (t_x >= 0 && (this->field_to_show_[t_x][t_y] == 'o' || this->field_to_show_[t_x][t_y] == '*')) {
        coords.emplace_back(t_x, t_y);
        t_x--;
    }
    t_x = x + 1, t_y = y;
    while (t_x < field_size_ && (this->field_to_show_[t_x][t_y] == 'o' || this->field_to_show_[t_x][t_y] == '*')) {
        coords.emplace_back(t_x, t_y);
        t_x++;
    }
    t_x = x, t_y = y + 1;
    while (t_y < field_size_ && (this->field_to_show_[t_x][t_y] == 'o' || this->field_to_show_[t_x][t_y] == '*')) {
        coords.emplace_back(t_x, t_y);
        t_y++;
    }
    t_x = x, t_y = y - 1;
    while (t_y >= 0 && (this->field_to_show_[t_x][t_y] == 'o' || this->field_to_show_[t_x][t_y] == '*')) {
        coords.emplace_back(t_x, t_y);
        t_y--;
    }
    for (auto coord: coords) {
        if (other.shot_field_[coord.first][coord.second] != '*') {
            return "Hit!";
        }
    }
    return "Kill!";
}

std::string Field::get_shot(int x, int y, Field& other) {
    if (this->field_to_show_[x][y] == 'o') {
        this->field_to_show_[x][y] = '*';
        other.shot_field_[x][y] = '*';
        return get_verdict(x, y, other);
    }
    if(other.shot_field_[x][y] != '*')
        other.shot_field_[x][y] = '-';
    return "Miss!";
}


