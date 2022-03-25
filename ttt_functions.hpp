#include <vector>
using namespace std;

void greet();
void draw();
void display_board();
void place_piece();
void update_board();
void switch_turn();
bool win_conditions();
int convert_letter(char letter);
bool taken_spot(int row, int col);
void end_game();