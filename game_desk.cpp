#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <limits>

#include "game_desk.hpp"

void GameDesk::replace(Points& a) {
    desk_[a.p2.col * rownumber_ + a.p2.row] *= 2;
    while (a.p1.col < rownumber_-1) {
        desk_[a.p1.col * rownumber_ + a.p1.row] = desk_[++a.p1.col * rownumber_ + a.p1.row];
    }
    
    if (rand() > (RAND_MAX / 2)) {
        desk_[a.p1.col * rownumber_ + a.p1.row] = 1;
    }
    else {
        desk_[a.p1.col * rownumber_ + a.p1.row] = 2;
    }
}

void GameDesk::output() {
    for (int i = rownumber_-1; i >= 0; i--) {
        for (int x = 0; x < rownumber_; x++) {
            char prev_fill = std::cout.fill(' ');
            int prev_width = std::cout.width(5);
            std::cout << desk_[i * rownumber_ + x];
            std::cout.width(prev_width);
            std::cout.fill(prev_fill);
        }
        std::cout << std::endl;
    }
}

long long int GameDesk::score() {
    int rowScore = 0;
    int allScore = 0;
    for (int i = 0; i < rownumber_; i++) {
        for (int x = 0; x < rownumber_; x++) {
            rowScore += desk_[i * rownumber_ + x];
        }
        allScore += rowScore;
        rowScore = 0;
    }
    return allScore;
}

bool GameDesk::check_fail() {
    Points *points = new Points;
    for (int i = 0; i < rownumber_; i++) {
        for (int x = 0; x < rownumber_; x++) {
            for (int y = 0; y < rownumber_; y++) {
                for (int t = 0; t < rownumber_; t++) {
                    points->p1.set_index(i, x);
                    points->p2.set_index(y, t);
                    if (points->check_step(*this)) {
                        return 0;
                    }
                }
            }
        }
    }
    delete points;
    return 1;
}

GameDesk::GameDesk(int a) {
    rownumber_ = a;
    desk_.resize(a * a);
    for (int i = 0; i < rownumber_; i++) {
        for (int x = 0; x < rownumber_; x++) {
            if (rand() <= (RAND_MAX / 2)) {
                desk_[i * a + x] = 1;
            }
            else {
                desk_[i * a + x] = 2;
            }
        }
    }
}
   
int GameDesk::get_rownumber() {
    return rownumber_;
}

Ints GameDesk::get_desk() {
    return desk_;
}

bool Points::check_step(GameDesk& a) {
    int rownumber = a.get_rownumber();
    Ints desk_ = a.get_desk();
        if (check_index(rownumber)) {
            if (desk_[p1.col * rownumber + p1.row] == desk_[p2.col * rownumber + p2.row]) {
                return 1;
        }
            return 0;
        }
    return 0;
}

bool Points::check_index(int max) {
    if (check_range(max)) {
        if ((p1.col == p2.col) && ((p1.row == p2.row + 1) || (p1.row == p2.row - 1))) {
            return 1;
        }
        else if ((p1.row == p2.row) && ((p1.col == p2.col + 1) || (p1.col == p2.col - 1))) {
            return 1;
        }
        return 0;
    }
    return 0;
}

bool Points::check_range(int max) {
    if ((p1.row >= 0) && (p1.col >= 0) && (p2.row >= 0) && (p2.col >= 0)) {
        if ((p1.row < max) && (p1.col < max) && (p2.row < max) && (p2.col < max)) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void Points::input() {
    int i1, i2, i3, i4;
    std::cout << "Enter index of number1: ";
    while (!(std::cin >> i1 >> i2)) {
        std::cout << "Error: wrong index of number. Try again: " << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    }
    p1.set_index(i1, i2);
    std::cout << "\nAnd of number2: ";
    while (!(std::cin >> i3 >> i4)) {
        std::cout << "Error: wrong index of number. Try again: " << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    }
    p2.set_index(i3, i4);
}
 
void Point::set_index(int c, int r) {
    col = c;
    row = r;
}

void GameDesk::finish() {
    if (check_fail()) {
        std::cout << "You are looser... Your score is " << score() << std::endl;
    }
    else {
        std::cout << "You are winner! Your score is " << score() << std::endl;
    }
}

bool GameDesk::check_win(int max) {
    if (max >= score()) {
        return 0;
    }
    return 1;
}

void GameDesk::play() {
    Points points;
    points.input();
    if (points.check_step(*this)) {
        replace(points);
        output();
    }
    else {
        std::cout << "Error: wrong index of numbers." << std::endl;
    }
}
