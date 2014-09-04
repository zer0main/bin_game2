/** ..., ...
  * Copyright (C) 2014, ....
  * ....
  */

#ifndef GAME_DESK_HPP_
#define GAME_DESK_HPP_

#include <vector>

struct Point {
    int col;
    int row;

    bool check_index(col, row);

    bool check_range(col, row);
};

struct Points {
    Point p1;
    Point p2;

    void input();
    bool check_step();

};

class GameDesk {
public:
    bool check_fail();

    GameDesk(int); 
    
    void replace(const Points& points);
    
    void output();

    long long int score();

private:
    typedef long long unsigned int Int;
    typedef std::vector<Int> Ints;
    Ints desk_;
};        


void game_for_win();

void game_for_score();

void game_with_time();

void help();

#endif

