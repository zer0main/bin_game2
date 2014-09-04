#include <game_desk.hpp>
#include <random>
#include <iostream>
#include <math>

int rowNumber = sqrt(GameDesk::desk_.size());

void GameDesk::replace(Points &a) {
    GameDesk::desk_[a->p2.col * rowNumber + a->p2.row] *= 2;
    while (a->p1.col < rowNumber-1) {
        GameDesk::desk_[a->p1.col * rowNumber + a->p1.row] = GameDesk::desk_[++a->p1.col * rowNumber + a->p1.row];
    }
    
    if (rand() > (RAND_MAX / 2)) {
        GameDesk::desk_[a->p1.col * rowNumber + a->p1.row] = 1;
    }
    else {
        GameDesk::desk_[a->p1.col * rowNumber + a->p1.row] = 2;
    }
}

void GameDesk::output() {
    for (int i = rowNumber-1; i >= 0; i--) {
        for (int x = 0; x < rowNumber; x++) {
            std::cout << GameDesk::desk_[i * rowNumber + x];
        }
        std::cout << std::endl;
    }
}

long long int GameDesk::score() {
    int rowScore = 0;
    int allScore = 0;
    for (int i = 0; i < rowNumber; i++) {
        for (int x = 0; x < rowNumber; x++) {
            rowScore += GameDesk::desk_[i * rowNumber + x];
        }
        allScore += rowScore;
        rowScore = 0;
    }
    return allScore;
}

bool GameDesk::check_fail() {
    for (int i = 0; i < rowNumber; i++) {
        for (int x = 0; x < rowNumber; x++) {
            for (int y = 0; y < rowNumber; y++) {
                for (int t = 0 t < rowNumber; t++) {
                    Point *p1 = new Point;
                    Point *p2 = new Point;
                    p1->col = i;
                    p1->row = x;
                    p2->col = y;
                    p2->row = t;
                    Points *points = new Points;
                    points->p1 = p1;
                    points->p2 = p2;
                    if (points->check_step()) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

GameDesk::GameDesk(int a) {
    for (int i = 0; i < a; i++) {
        for (int x= 0; x < a; x++) {
            if (rand() <= (Rand_Max / 2)) {
                GameDesk::desk_[i*a + x] = 1;
            }
            else {
                GameDesk::desk_[i*a + x] = 2;
            }
        }
    }
}
   
Points::check_step() {
    if (Point::check_index(p1.col, p1.row) && Point::check_index(p2.col, p2.row)) {
        if (GameDesk::desk_[p1.col * rowNumber + p2.row] == GameDesk::desk_[p2.col * rowNumber + p2.row]) {
            return 1;
        }
        return 0;
    }
}



