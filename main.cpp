#include <stdlib.h>
#include <time.h>

#include "game_desk.hpp"

int main(int argc, char *argv[])
{
    srand(time(NULL));
    if (*++argv[1] == 'w') {
        game_for_win();
    }
    else if (*argv[1] == 's') {
        game_for_score();
    }
    else if (*argv[1] == 't') {
        game_with_time();
    }
    else {
        help();
    }
    return 0;
}
