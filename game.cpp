#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <limits>

#include "game_desk.hpp"

void game_for_win() {
    int k, h;
    k = 0;
    std::cout << "Choose the size of game desk (not very big, "
            "depends on the size of your screen): ";
    if (std::cin >> h) {
    }
    else {
        std::cout << "Error. It is not a number!" << std::endl;
        return;
    }
    GameDesk desk(h);
    std::cout << "What number you want to finish the game? ";
    if (std::cin >> k) {
    }
    else {
        std::cout << "Error. It is not a number!" << std::endl;
        return;
    }
    desk.output();
    while (!desk.check_fail() && !desk.check_win(k)) {
        desk.play();
    }
    desk.finish();
}

void game_for_score() {
    std::cout << "Choose the size of game desk please (not very big, "
             "depends on the size of your screen): ";
    int k;
    std::cin >> k;
    GameDesk desk(k);
    desk.output();
    while (!desk.check_fail()) {
        desk.play();
    }
    desk.finish();
}

void game_with_time() {
    int k, h;
    std::cout << "How many time you want to play (min)? ";
    if (std::cin >> k) {
    }
    else {
        std::cout << "Error. It is not a number, dummy!" << std::endl;
        return;
    }
    std::cout << "Choose the size of game desk (not very big, "
            "depends on the size of your screen): ";
    if (std::cin >> h) {
    }
    else {
        std::cout << "Error. It is not a number, dummy!" << std::endl;
        return;
    }
    GameDesk desk(h);
    desk.output();
    int t = time(NULL);
    int t1 = 0;
    while (!desk.check_fail() && (t1-t) <= k * 60) {
        desk.play();
        t1 = time(NULL);
    }
    desk.finish();      
}

void help() {
    std::cout << "We haven't any help yet\n";
}
