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

void Player::show_field_with_shots() {
    this->field_.show_field_with_shots();
}

bool Player::check_alive() {
    return this->field_.check_alive();
}

std::string Player::get_shot(int x, int y, Player& other) {
    return this->field_.get_shot(x, y, other.field_);
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


void Player::make_move(Player& other) {
    char letter;
    short number;
    //shot!!!
    bool verdict = true;
    while (verdict && other.check_alive()) {
        std::cout << "Enter the coordinates of the point you want to hit:\n";
        Field::get_point_for_shot(letter, number);
        std::string respond = other.get_shot(number - 1, letter - 'a', *this);
        verdict = (respond != "Miss!");
        this->show_field_with_shots();
        std::cout << respond << '\n';
    }
}

