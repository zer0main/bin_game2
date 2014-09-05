#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "game_desk.hpp"

void play(GameDesk&);

void finish(GameDesk&, bool);

bool check_win(GameDesk&, int);

void game_for_win() {
    int k, h;
    std::cout << "What number you want to finish the game? ";
    std::cin >> k;
    std::cout << "Choose the size of game desk (not very big, "
            "depends on the size of your screen): ";
    std::cin >> h;
    GameDesk desk(h);
    desk.output();
    while (!desk.check_fail() && !check_win(desk, k)) {
        play(desk);
    }
    finish(desk, desk.check_fail());
}

void game_for_score() {
    std::cout << "Choose the size of game desk please (not very big, "
             "depends on the size of your screen): ";
    int k;
    std::cin >> k;
    GameDesk desk(k);
    desk.output();
    while (!desk.check_fail()) {
        play(desk);
    }
    finish(desk, desk.check_fail());
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
    while (!desk.check_fail() && (t1-t) * 60 <= k) {
        play(desk);
        int t1 = time(NULL);
    }
    finish(desk, desk.check_fail());      
}

bool check_win(GameDesk& e, int a) {
    if (a >=  e.score()) {
        return 0;
    }
    return 1;
}

void play(GameDesk& a) {
    Points points;
    points.input();
    if (points.check_step(a)) {
        a.replace(points);
        a.output();
    }
    else {
        std::cout << "Error: wrong index of numbers." << std::endl;
    }
}

void finish(GameDesk& a, bool h) {
    if (h == true) {
        std::cout << "You are looser... Your score is " << a.score() << std::endl;
    }
    else {
        std::cout << "You are winner! Your score is " << a.score() << std::endl;
    }
}

void help() {
    std::cout << "We haven't any help yet\n";
}
