#include <iostream>
#include <vector>
#include <map>
#include "ttt_functions.hpp"

using namespace std;
// var
string player1;            // player 1 name
string player2;            // player 2 name
string player;             // current player
int row;                   // rows of board
int col;                   // col of board
char letter;               // pos of board with letter naming
char piece;                // piece to be used by either players
char c = 'A';              // char of A for the for loop to loop letters from A to I
bool winner = false;       // winner flag
bool taken = false;        // taken pos flag
char board[3][3];          // char array to make tictactoe board
map<string, char> mapHash; // hashmap to contain each of the player's pieces
// fnct
void greet()
{
    cout << "\nWelcome to Tic-Tac-Toe!\n";
    cout << "Please Input Player1: \n";
    cin >> player1; // input player 1
    cout << "\n";
    cout << "Please Input Player2: \n";
    cin >> player2; // input player 2
    cout << "\n";
    player = player1; // current player is player 1 automatically
    cout << player << ", select Piece you want to put down: X or O\n";
    cin >> piece;                     // input piece player 1 wants
    mapHash.insert({player1, piece}); // hashmap save the player's choice for later use
    if (piece == 'X')                 // if player 1 has X
    {
        cout << player2 << ", you are using the O piece.\n";
        mapHash.insert({player2, 'O'}); // player 2 recieves the piece O
    }
    else if (piece == 'O') // if player 1 has O
    {
        cout << player2 << ", you are using the X piece.\n";
        mapHash.insert({player2, 'X'}); // player 2 recieves the piece X
    }
    cout << "\n";
}
void draw()
{
    for (int i = 0; i < 3; i++) // for loop iterating through board array
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = c; // first pos gets A
            c += 1;          // every next pos gets the next letter of the alphabet
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
    update_board(); // call to update_board method
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
    place_piece();           // call to place_piece
    board[row][col] = piece; // updates the input made by user for the row, col, and piece they want
}
void place_piece()
{
    cout << player << ", which space do you want to put a piece: A-I\n";
    cin >> letter;                     // input for letter pos
    convert_letter(letter);            // call to convert_letter method
    bool taken = taken_spot(row, col); // var using taken_spot method
    if (taken)                         // if taken is true
    {
        cout << "This spot is already taken. Select new position.\n";
        place_piece(); // use recursion to by calling place_piece again
    }
    else // spot is free
    {
        switch_turn(); // call to switch_turns method
    }
}
int convert_letter(char letter)
{
    switch (letter) // switch statement accepting a letter pos as input and converting letters into coord. of rows/cols
    {
    case 'A': // (0,0)
        row = 0;
        col = 0;
        break;
    case 'B': // (0,1)
        row = 0;
        col = 1;
        break;
    case 'C': // (0,2)
        row = 0;
        col = 2;
        break;
    case 'D': // (1,0)
        row = 1;
        col = 0;
        break;
    case 'E': // (1,1)
        row = 1;
        col = 1;
        break;
    case 'F': // (1,2)
        row = 1;
        col = 2;
        break;
    case 'G': // (2,0)
        row = 2;
        col = 0;
        break;
    case 'H': // (2,1)
        row = 2;
        col = 1;
        break;
    case 'I': // (2,2)
        row = 2;
        col = 2;
        break;
    default:
        break;
    }
    return row, col; // returns the value for the row and the col
}
void switch_turn()
{
    if (player == player1) // checks if the current player is player 1
    {
        piece = mapHash.at(player1); // retrieves the char value stored with player 1
        player = player2;            // makes player 2 the next current player
    }
    else // checks if the current player is player 2
    {
        piece = mapHash.at(player2); // retrieves the char value stored with player 2
        player = player1;            // makes player 1 the next current player
    }
}
bool win_conditions()
{
    // ALL WIN CONDITIONS WITHIN THE GAME OF TIC TAC TOE:
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
        winner = true;    // sets winner flag to true
        player = player1; // sets the player who won
        return winner;    // returns the value for winner to end game
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
        winner = true;    // sets winner flag to true
        player = player2; // sets the player who won
        return winner;    // returns the value for winner to end game
    }
    else // if no win condition is met
    {
        return winner; // win flag remains set to false
    }
}
bool taken_spot(int row, int col)
{
    if (board[row][col] == 'X' || board[row][col] == 'O') // checks if spot requested is closed with piece
    {
        return true;
    }
    else // spot open
    {
        return false;
    }
}
void end_game()
{
    cout << player << " has won the game!\n"; // current player has won the game
}