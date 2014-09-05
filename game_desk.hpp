/** ..., ...
  * Copyright (C) 2014, ....
  * ....
  */

#ifndef GAME_DESK_HPP_
#define GAME_DESK_HPP_

#include <vector>

class GameDesk;

typedef long long unsigned int Int;
typedef std::vector <Int> Ints;

struct Point {
    int col;
    int row;

    void set_index(int, int);
};

struct Points {
    Point p1;
    Point p2;

    void input();
    
    bool check_range(int);

    bool check_index(int);
    
    bool check_step(GameDesk&);

};

class GameDesk {
public:
    int get_rownumber();

    Ints get_desk();
    
    bool check_fail();

    GameDesk(int); 
    
    void replace(Points&);
    
    void output();

    long long int score();

private:
    Ints desk_;
    int rownumber_;
};        


void game_for_win();

void game_for_score();

void game_with_time();

void help();

#endif

