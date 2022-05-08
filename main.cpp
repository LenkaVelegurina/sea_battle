#include <iostream>
#include <string>
#include "player.h"

signed main() {
    std::cout << "HEY BROTHER\n";
    // registration

    std::cout << "Create password of the first player:\n";
    std::string first_password;
    std::cin >> first_password;
    Player first_player(first_password, PlayerNumber::kFirstPlayer);

    std::cout << "Create password of the second player:\n";
    std::string second_password;
    std::cin >> second_password;
    Player second_player(second_password, PlayerNumber::kSecondPlayer);

    //set ships
    // 1
    first_player.authorization();
    first_player.set_ships();

    // 2
    second_player.authorization();
    second_player.set_ships();

    //TODO: shot_command
    while (true) {
        first_player.authorization();
        //shot & check alive
        first_player.make_move(second_player);
        //check
        if (!second_player.check_alive()) {
            std::cout << "The first player wins the game!!!";
            break;
        }

        second_player.authorization();
        //shot & check alive
        second_player.make_move(first_player);
        //check
        if (!first_player.check_alive()) {
            std::cout << "The second player wins the game!!!";
            break;
        }
    }
    return 0;
}