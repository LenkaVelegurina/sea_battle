#include "player.h"
#include <iostream>
#include <utility>

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

