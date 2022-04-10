#include "iostream"
#include "player.h"
#include <string>

signed main() {
    std::cout << "HEY BROTHER";
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
    std::cout << "Enter password of the first player:\n";
    std::cin >> first_password;
    while (!first_player.check_password(first_password)) {
        std::cin >> first_password;
    }
    first_player.set_ships();
    first_player.show_field();

    // 2
    std::cout << "Enter password of the second player:\n";
    std::cin >> second_password;
    while (!second_player.check_password(second_password)) {
        std::cin >> second_password;
    }
    second_player.set_ships();
    second_player.show_field();

    //TODO: shot_command
    char letter;
    int number;
    while (true) {
        std::cout << "Enter password of the first player:\n";
        std::cin >> first_password;
        while (!first_player.check_password(first_password)) {
            std::cin >> first_password;
        }
        //shot & check alive
        std::cin >> letter >> number;
        //TODO: check format
        //shot!!!
        bool verdict = second_player.get_shot(number - 1, letter - 'a');
        while (verdict){
            std::cin >> letter >> number;
            verdict = second_player.get_shot(number - 1, letter - 'a');
            if(!second_player.check_alive()){
                break;
            }
            second_player.show_field();
        }
        //check
        if(!second_player.check_alive()){
            break;
        }

        std::cout << "Enter password of the second player:\n";
        std::cin >> second_password;
        while (!second_player.check_password(second_password)) {
            std::cin >> second_password;
        }
        //shot & check alive
        std::cin >> letter >> number;
        //TODO: check format
        //shot!!!
        verdict = first_player.get_shot(number - 1, letter - 'a');
        while (verdict){
            std::cin >> letter >> number;
            verdict = first_player.get_shot(number - 1, letter - 'a');
            if(!first_player.check_alive()){
                break;
            }
        }
        //check
        if(!first_player.check_alive()){
            break;
        }
    }
    return 0;
}