#include <iostream>
#include <vector>
#include <map>
#include "ttt_functions.hpp"

using namespace std;
// var
string player1;
string player2;
string player;
int row;
int col;
char letter;
char piece;
char c = 'A';
bool winner = false;
bool taken = false;
char board[3][3];
map<string, char> mapHash;
// fnct
void greet()
{
    cout << "\nWelcome to Tic-Tac-Toe!\n";
    cout << "Please Input Player1: \n";
    cin >> player1;
    cout << "\n";
    cout << "Please Input Player2: \n";
    cin >> player2;
    cout << "\n";
    player = player1;
    cout << player << ", select Piece you want to put down: X or O\n";
    cin >> piece;
    mapHash.insert({player1, piece});
    if (piece == 'X')
    {
        cout << player2 << ", you are using the O piece.\n";
        mapHash.insert({player2, 'O'});
    }
    else if (piece == 'O')
    {
        cout << player2 << ", you are using the X piece.\n";
        mapHash.insert({player2, 'X'});
    }
    cout << "\n";
}
void draw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = c;
            c += 1;
        }
    }
    ////////first-row////////////
    cout << "   |"
         << "   |"
         << "  "
         << "\n";
    //////////////////////////////
    cout << " " << board[0][0] << " | "
         << board[0][1] << " | "
         << board[0][2] << " "
         << "\n";
    //////////////////////////////
    cout << "___|"
         << "___|"
         << "___\n";
    ////////second-row////////////
    cout << "   |"
         << "   |"
         << "  "
         << "\n";
    //////////////////////////////
    cout << " " << board[1][0] << " | "
         << board[1][1] << " | "
         << board[1][2] << " "
         << "\n";
    ////////third-row////////////
    cout << "___|"
         << "___|"
         << "___\n";
    /////////////////////////////
    cout << "   |"
         << "   |"
         << "  "
         << "\n";
    //////////////////////////////
    cout << " " << board[2][0] << " | "
         << board[2][1] << " | "
         << board[2][2] << " "
         << "\n";
    //////////////////////////////
    cout << "   |"
         << "   |"
         << "   \n";
}
void display_board()
{
    update_board();
    ////////first-row////////////
    cout << "   |"
         << "   |"
         << "  "
         << "\n";
    //////////////////////////////
    cout << " " << board[0][0] << " | "
         << board[0][1] << " | "
         << board[0][2] << " "
         << "\n";
    //////////////////////////////
    cout << "___|"
         << "___|"
         << "___\n";
    ////////second-row////////////
    cout << "   |"
         << "   |"
         << "  "
         << "\n";
    //////////////////////////////
    cout << " " << board[1][0] << " | "
         << board[1][1] << " | "
         << board[1][2] << " "
         << "\n";
    ////////third-row////////////
    cout << "___|"
         << "___|"
         << "___\n";
    /////////////////////////////
    cout << "   |"
         << "   |"
         << "  "
         << "\n";
    //////////////////////////////
    cout << " " << board[2][0] << " | "
         << board[2][1] << " | "
         << board[2][2] << " "
         << "\n";
    //////////////////////////////
    cout << "   |"
         << "   |"
         << "   \n";
}
void update_board()
{
    place_piece();
    board[row][col] = piece;
}
void place_piece()
{
    cout << player << ", which space do you want to put a piece: A-I\n";
    cin >> letter;
    convert_letter(letter);
    bool taken = taken_spot(row, col);
    if (taken)
    {
        cout << "This spot is already taken. Select new position.\n";
        place_piece();
    }
    else
    {
        switch_turn();
    }
}
int convert_letter(char letter)
{
    switch (letter)
    {
    case 'A':
        row = 0;
        col = 0;
        break;
    case 'B':
        row = 0;
        col = 1;
        break;
    case 'C':
        row = 0;
        col = 2;
        break;
    case 'D':
        row = 1;
        col = 0;
        break;
    case 'E':
        row = 1;
        col = 1;
        break;
    case 'F':
        row = 1;
        col = 2;
        break;
    case 'G':
        row = 2;
        col = 0;
        break;
    case 'H':
        row = 2;
        col = 1;
        break;
    case 'I':
        row = 2;
        col = 2;
        break;
    default:
        break;
    }
    return row, col;
}
void switch_turn()
{
    if (player == player1 && winner != true)
    {
        piece = mapHash.at(player1);
        player = player2;
    }
    else
    {
        piece = mapHash.at(player2);
        player = player1;
    }
}
bool win_conditions()
{
    if ((board[0][0] == mapHash.at(player1) &&
         board[0][1] == mapHash.at(player1) &&
         board[0][2] == mapHash.at(player1)) ||
        (board[1][0] == mapHash.at(player1) &&
         board[1][1] == mapHash.at(player1) &&
         board[1][2] == mapHash.at(player1)) ||
        (board[2][0] == mapHash.at(player1) &&
         board[2][1] == mapHash.at(player1) &&
         board[2][2] == mapHash.at(player1)) ||
        (board[0][0] == mapHash.at(player1) &&
         board[1][0] == mapHash.at(player1) &&
         board[2][0] == mapHash.at(player1)) ||
        (board[0][1] == mapHash.at(player1) &&
         board[1][1] == mapHash.at(player1) &&
         board[2][1] == mapHash.at(player1)) ||
        (board[0][2] == mapHash.at(player1) &&
         board[1][2] == mapHash.at(player1) &&
         board[2][2] == mapHash.at(player1)) ||
        (board[0][0] == mapHash.at(player1) &&
         board[1][1] == mapHash.at(player1) &&
         board[2][2] == mapHash.at(player1)) ||
        (board[0][2] == mapHash.at(player1) &&
         board[1][1] == mapHash.at(player1) &&
         board[2][0] == mapHash.at(player1)))
    {
        winner = true;
        player = player1;
        return winner;
    }
    else if ((board[0][0] == mapHash.at(player2) &&
              board[0][1] == mapHash.at(player2) &&
              board[0][2] == mapHash.at(player2)) ||
             (board[1][0] == mapHash.at(player2) &&
              board[1][1] == mapHash.at(player2) &&
              board[1][2] == mapHash.at(player2)) ||
             (board[2][0] == mapHash.at(player2) &&
              board[2][1] == mapHash.at(player2) &&
              board[2][2] == mapHash.at(player2)) ||
             (board[0][0] == mapHash.at(player2) &&
              board[1][0] == mapHash.at(player2) &&
              board[2][0] == mapHash.at(player2)) ||
             (board[0][1] == mapHash.at(player2) &&
              board[1][1] == mapHash.at(player2) &&
              board[2][1] == mapHash.at(player2)) ||
             (board[0][2] == mapHash.at(player2) &&
              board[1][2] == mapHash.at(player2) &&
              board[2][2] == mapHash.at(player2)) ||
             (board[0][0] == mapHash.at(player2) &&
              board[1][1] == mapHash.at(player2) &&
              board[2][2] == mapHash.at(player2)) ||
             (board[0][2] == mapHash.at(player2) &&
              board[1][1] == mapHash.at(player2) &&
              board[2][0] == mapHash.at(player2)))
    {
        winner = true;
        player = player2;
        return winner;
    }
    else
    {
        return winner;
    }
}
bool taken_spot(int row, int col)
{
    if (board[row][col] == 'X' || board[row][col] == 'O')
    {
        return true;
    }
    else
    {
        return false;
    }
}
void end_game()
{
    cout << player << " has won the game!\n";
}