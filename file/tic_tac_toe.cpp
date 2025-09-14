#include <iostream>
#include <array>
#include <string>

using namespace std;

using Board = array<char, 9>;

void printBoard(const Board &board)
{
    cout << "\n";
    for (int i = 0; i < 9; i += 3)
    {
        cout << " " << (b[i] == ' ' ? to_string(i + 1) : string(1, b[i]))
             << " | " << (b[i + 1] == ' ' ? to_string(i + 2) : string(1, b[i + 1]))
             << " | " << (b[i + 2] == ' ' ? to_string(i + 3) : string(1, b[i + 2])) << "\n";
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
        char a = b[w[0]], c = b[w[1]], d = b[w[2]];
        if (a != ' ' && a == c && a == d)
            return a;
    }

    bool anyEmpty = false;
    for (char cell : b)
        if (cell == ' ')
        {
            anyEmpty = true;
            break;
        }
    if (!anyEmpty)
        return 'D';

    return ' ';
}

int getPlayerMove(const Board &board, char player)
{
    while (true)
    {
        cout << "Player " << player << ", enter cell number (1-9): ";
        string s;
        if (!getline(cin, s))
            return -1;
        if (s.empty())
            continue;

        try
        {
            int pos = stoi(s);
            if (pos < 1 || pos > 9)
            {
                cout << "Invalid number. Please enter a number from 1 to 9.\n";
                continue;
            }
            if (b[pos - 1] != ' ')
            {
                cout << "The cell is occupied. Choose another.\n";
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
            if (idx == -1)
            {
                cout << "\nInput complete. Game stopped.\n";
                return 0;
            }
            board[idx] = current;
            printBoard(board);
            result = checkResult(board);
            if (result == ' ')
            {
                current = (current == 'X') ? 'O' : 'X';
            }
        }

        if (result == 'D')
        {
            cout << "Tie!\n";
        }
        else
        {
            cout << "Player  won " << result << "!\n";
        }

        cout << "Play again? (y/n): ";
        string again;
        if (!getline(cin, again))
            break;
        if (again.empty() || (again[0] != 'y' && again[0] != 'Y'))
            break;
    }

    cout << "Thanks for playing! Goodbye.\n";
    return 0;
}