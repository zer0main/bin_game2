#include <time.h>
#include <stdlib.h>
#include <iostream>

#include "game_desk.hpp"

void game_for_win() {
    int k, h;
    std::cout << "What number you want to finish the game? ";
    std::cin >> k;
    std::cout << "Choose the size of game desk (not very big, "
            "depends on the size of your screen): ";
    std::cin >> h;
    GameDesk desk(h);
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
    std::cin >> k;
    std::cout << "Choose the size of game desk (not very big, "
            "depends on the size of your screen): ";
    std::cin >> h;
    GameDesk desk(h);
    desk.output();
    int t = time(NULL);
    int t1 = 0;
    while (!desk.check_fail() && (t1-t) <= k * 60) {
        desk.play();
        int t1 = time(NULL);
    }
    desk.finish();      
}

void help() {
    std::cout << "We haven't any help yet\n";
}
