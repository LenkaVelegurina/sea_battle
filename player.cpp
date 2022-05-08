#include "player.h"
#include "ship.h"
#include <iostream>
#include <utility>
#include <string>

Player::Player(std::string pass, PlayerNumber number) : password_(std::move(pass)), player_number_(number) {}

bool Player::check_password(const std::string& pass) {
    return pass == this->password_;
}

void Player::set_ships() {
    this->field_.set_ships();
}

void Player::show_field() {
    this->field_.show_field();
}

bool Player::check_alive() {
    return this->field_.check_alive();
}

bool Player::get_shot(int x, int y) {
    return this->field_.get_shot(x, y);
}

void Player::authorization() {
    std::string password;
    std::string current_player;
    if (player_number_ == PlayerNumber::kFirstPlayer) {
        current_player = "first";
    } else if (player_number_ == PlayerNumber::kSecondPlayer) {
        current_player = "second";
    }
    std::cout << "Enter password of the " << current_player << " player:\n";
    std::cin >> password;
    while (!this->check_password(password)) {
        std::cout << "Wrong password, try another one:\n";
        std::cin >> password;
    }
}


void Player::make_move(Player other) {
    char letter;
    short number;
    //shot!!!
    bool verdict = true;
    while (verdict && other.check_alive()) {
        std::cout << "Enter the coordinates of the point you want to hit:\n";
        Field::get_point_for_shot(letter, number);
        verdict = other.get_shot(number - 1, letter - 'a');
        other.show_field();
    }
}

