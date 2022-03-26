#include <iostream>
#include "ttt_functions.hpp"

using namespace std;
int main()
{
    bool winner = false;                      // winner flag
    int counter = 0;                          // counter for amount of spaces players use till full
    greet();                                  // introduction
    draw();                                   // board without any inputs
    while ((winner != true) || (counter < 9)) // Game loop (continue whether winner is not ture or counter is not 8)
    {
        display_board();      // displays the board after it gets updated by user input
        if (win_conditions()) // checking if win conditions are met
        {
            end_game(); // if so it ends the game
            break;
        }
        else if (counter == 8) // checking if all the spaces are filled
        {
            cout << "Both players are evenly matched! GAME OVER!\n"; // if so then that means there was no winner thus game ends in tie
            break;
        }
        else
        {
            counter++; // continue game by incrementing the counter of spots that have been played
        }
    }
}