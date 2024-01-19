#include <termcolor/termcolor.hpp>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;
string board[6][7];

void fillBoard()
{
    for (int i = 0; i < 6; i++)
    {
        for (int g = 0; g < 7; g++)
        {
            board[i][g] = " - ";
        }
    }
}
void printBoard()
{
    for (int i = 0; i < 6; i++)
    {
        cout << "\n";
        for (int j = 0; j < 7; j++)
        {
            if (board[i][j] == " - ")
            {
                cout << board[i][j];
            }
            if (board[i][j] == " R ")
            {
                cout << termcolor::red << " O " << termcolor::bright_grey;
            }
            if (board[i][j] == " Y ")
            {
                cout << termcolor::yellow << " O " << termcolor::bright_grey;
            }
        }
        cout << endl;
    }
}
void plop(int col, string player)
{
    for (int i = 5; i >= 0; i--)
    {
        if (board[i][col] == " - ")
        {
            board[i][col] = player;
            break;
        }
    }
}
void turn(string player)
{
    int column;
    string holder;
    begin:
    cin >> holder;
    stringstream(holder) >> column;
    if (column < 1 or column > 7)
    {
        cout << "That is not a spot on the board moron!\nWhat column to play? ";
        goto begin;
    }
    if (board[0][column - 1] == " - ")
    {
        plop(column - 1, player);
    }
    else
    {
        cout << "That row is full nitwit!\nWhat column to play? ";
        goto begin;
    }
    system("cls");
    printBoard();
}
bool checkWin(string player)
{
    for (int i = 0; i < 6; i++)
    {
        for (int g = 0; g < 7; g++)
        {
            if (board[i][g] == player)
            {
                if (g > 2)
                {
                    if (board[i][g - 1] == player && board[i][g - 2] == player && board[i][g - 3] == player)
                    {
                        return true;
                    }
                }
                if (g < 4)
                {
                    if (board[i][g + 1] == player && board[i][g + 2] == player && board[i][g + 3] == player)
                    {
                        return true;
                    }
                }
                if (i > 2)
                {
                    if (board[i - 1][g] == player && board[i - 2][g] == player && board[i - 3][g] == player)
                    {
                        return true;
                    }
                }
                if (i < 4)
                {
                    if (board[i + 1][g] == player && board[i + 2][g] == player && board[i + 3][g] == player)
                    {
                        return true;
                    }
                }
                if (g > 2 && i < 3)
                {
                    if (board[i + 1][g - 1] == player && board[i + 2][g - 2] == player && board[i + 3][g - 3] == player)
                    {
                        return true;
                    }
                }
                if (g < 4 && i < 4)
                {
                    if (board[i + 1][g + 1] == player && board[i + 2][g + 2] == player && board[i + 3][g + 3] == player)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool checkTie()
{
    for (int g = 0; g < 7; g++)
    {
        if (board[0][g] == " - ")
        {
            return false;
        }
    }
    return true;
}
int main()
{
    start:
    cout << termcolor::bright_grey << "Welcome to Connect Four!";  
    fillBoard();
    printBoard();
    while (1 == 1)
    {
        cout << "Red: What column to play? ";
        turn(" R ");
        if (checkWin(" R "))
        {
            cout << "Red wins!";
            break;
        }
        if (checkTie())
        {
            cout << "It's a tie...";
            break;
        }
        cout << "Yellow: What column to play? ";
        turn(" Y ");
        if (checkWin(" Y "))
        {
            cout << "Yellow wins!";
            break;
        }
        if (checkTie())
        {
            cout << "It's a tie...";
            break;
        }
    }
    choose:
    cout << "\nPlay again? (y/n) ";
    string choice;
    cin >> choice;
    if (choice == "y")
    {
        system("cls");
        goto start;
    }
    if (choice == "n")
    {
        return 0;
    }
    else
    {
        cout << "I don't understand that!";
        goto choose;
    }
    return 0;
}