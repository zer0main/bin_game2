#include <time>
#include <random>
#include <iostream>
#include <game_desk.hpp>

void game_for_win() {
    int k, h;
    std::cout << "What number you want to finish the game? ";
    std::cin >> k;
    std::cout << "Choose the size of game desk (not very big, "
            "depends on the size of your screen): ";
    std::cin >> h;
    GameDesk *desk = new GameDesk(h);
    desk->output();
    while (!desk->check_fail() && !check_win(&desk, k)) {
        play(&desk);
    }
    finish(&desk, desk->check_fail());
    delete desk;
}

void game_for_score() {
    std::cout << "Choose the size of game desk please (not very big, "
             "depends on the size of your screen): ";
    int k;
    std::cin >> k;
    GameDesk *desk = new GameDesk(k);
    desk->output();
    while (!desk->check_fail()) {
        play(&desk);
    }
    finish(&desk, desk->check_fail());
    delete desk;
}

void game_with_time() {
    int k, h;
    std::cout << "How many time you want to play (min)? ";
    std::cin >> k;
    std::cout << "Choose the size of game desk (not very big, "
            "depends on the size of your screen): ";
    std::cin >> h;
    GameDesk *desk = new GameDesk(h);
    desk->output();
    int t = time(NULL);
    int t1 = 0;
    while (!desk->check_fail() && (t1-t) * 60 <= k) {
        play(&desk);
        int t1 = time(NULL);
    }
    finish(&desk, desk->check_fail());      
    delete desk;
}

bool check_win(const GameDesk& e, int a) {
    if (a >=  e.score()) {
        return 1;
    }
    return 0;
}

void play(GameDesk& a) {
    Points *points = new Points;
    points->input();
    if (points->check_step()) {
        a->replace(&points);
        a->output();
    }
    else {
        std::cout << "Error: wrong index of numbers.\n";
    }
    delete points;
}

void finish(const GameDesk& a, bool h) {
    if (h == true) {
        std::cout << "You are looser... Your score is " << a->score() << std::endl;
    }
    else {
        std::cout << "You are winner! Your score is " << a->score() >> std::endl;
    }
}
