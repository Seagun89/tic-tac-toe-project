#include <vector>
using namespace std;

void greet();                      // function for introduction
void draw();                       // frame shot of empty board
void display_board();              // frames of board after inputs have been made
void place_piece();                // asks player for input on which pos they want to place piece
void update_board();               // recieves the play input for pos from place piece and calls to the board
void switch_turn();                // selects which player goes next
bool win_conditions();             // all the win conditions for tic tac toe
int convert_letter(char letter);   // converts the letter pos inputed by play to coordinates
bool taken_spot(int row, int col); // checks if pos has a piece already
void end_game();                   // ending the game
