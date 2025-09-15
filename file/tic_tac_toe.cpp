#include <iostream>
#include <array>
#include <string> // i include bibliotecs

using namespace std;
using Board = array<char, 9>; // i use using

void printBoard(const Board &board)
{
    cout << "\n";
    for (int i = 0; i < 9; i += 3)
    {
        cout << " " << (board[i] == ' ' ? to_string(i + 1) : string(1, board[i]))
             << " | " << (board[i + 1] == ' ' ? to_string(i + 2) : string(1, board[i + 1]))
             << " | " << (board[i + 2] == ' ' ? to_string(i + 3) : string(1, board[i + 2]))
             << "\n";

        if (i < 6)
            cout << "---+---+---\n";
    }
    cout << "\n";
}

char checkResult(const Board &board)
{
    const int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

    for (auto &w : wins)
    {
        char a = board[w[0]];
        char b = board[w[1]];
        char c = board[w[2]];
        if (a != ' ' && a == b && a == c)
            return a;
    }

    for (char cell : board)
    {
        if (cell == ' ')
            return ' ';
    }

    return 'D';
}

int getPlayerMove(Board &board, char player)
{
    while (true)
    {
        cout << "Player " << player << ", enter cell number (1-9): ";
        string input;
        getline(cin, input);

        if (input.empty())
            continue;

        try
        {
            int pos = stoi(input);
            if (pos < 1 || pos > 9)
            {
                cout << "Invalid number. Enter a number from 1 to 9.\n";
                continue;
            }
            if (board[pos - 1] != ' ')
            {
                cout << "That cell is already taken. Choose another one.\n";
                continue;
            }
            return pos - 1;
        }
        catch (...)
        {
            cout << "Invalid input. Try again.\n";
        }
    }
}

int main()
{
    cout << "=== Tic Tac Toe (3x3) ===\n";

    while (true)
    {
        Board board;
        board.fill(' ');

        char current = 'X';
        char result = ' ';

        printBoard(board);

        while (result == ' ')
        {
            int idx = getPlayerMove(board, current);
            board[idx] = current;
            printBoard(board);

            result = checkResult(board);

            if (result == ' ')
                current = (current == 'X') ? 'O' : 'X';
        }

        if (result == 'D')
            cout << "It's a draw!\n";
        else
            cout << "Player " << result << " wins!\n";

        cout << "Play again? (y/n): ";
        string again;
        getline(cin, again);
        if (again.empty() || (again[0] != 'y' && again[0] != 'Y'))
            break;
    }

    cout << "Thanks for playing! Goodbye.\n";
    return 0;
}
