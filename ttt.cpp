#include <iostream>
#include "ttt_functions.hpp"

using namespace std;
int main()
{
    bool winner = false;
    int counter = 0;
    greet();
    draw();
    while ((winner != true) || (counter < 9))
    {
        display_board();
        if (win_conditions())
        {
            end_game();
            break;
        }
        else if (counter == 8)
        {
            cout << "Both players are evenly matched! GAME OVER!\n";
            break;
        }
        else
        {
            counter++;
        }
    }
}