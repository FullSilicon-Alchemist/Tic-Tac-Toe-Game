#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// printing the pattern
int printing_pattern(string pattern[3][3])
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\t";
        for (int j = 0; j < 3; j++)
        {
            cout << pattern[i][j];
            // to avoid the last vertical line
            if (j != 2)
            {
                cout << "\t||\t";
            }
        }
        // to avoid the last horizontal line
        if (i != 2)
        {
            cout << endl
                 << string(40, '-') << endl;
        }
    }
    cout << "\n";
    return 0;
}

// checking the coordinates validity

bool check(int x, int y, string pattern[3][3])
{
    if (x < 0 || x > 2 || y < 0 || y > 2)
    {
        return false;
    }
    else if (pattern[x][y] == "X" || pattern[x][y] == "O")
    {
        return false;
    }
    else
    {
        return true;
    }
}

// checking win or lose
string win_lose(string pattern[3][3])
{
    // Row-wise conditions
    for (int i = 0; i <= 2; i++)
    {
        if ((pattern[i][0] == pattern[i][1]) && (pattern[i][1] == pattern[i][2]))
        {
            return pattern[i][0];
        }
    }
    // Column-wise conditions
    for (int j = 0; j <= 2; j++)
    {
        if ((pattern[0][j] == pattern[1][j]) && (pattern[1][j] == pattern[2][j]))
        {
            return pattern[0][j];
        }
    }

    // Diagonal-wise conditions
    if ((pattern[0][0] == pattern[1][1]) && (pattern[1][1] == pattern[2][2]))
    {
        return pattern[0][0];
    }
    else if ((pattern[0][2] == pattern[1][1]) && (pattern[1][1] == pattern[2][0]))
    {
        return pattern[0][2];
    }
    else
    {
        return "NA";
    }
}

bool draw_game(string pattern[3][3])
{
    int counter = 0;
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (pattern[i][j] == "X" || pattern[i][j] == "O")
            {
                counter++;
            }
        }
    }
    return counter == 9;
}

// main execution
int main()
{
    string player1, player2;
    string pattern[3][3] = {
        {"0,0", "0,1", "0,2"},
        {"1,0", "1,1", "1,2"},
        {"2,0", "2,1", "2,2"}};

    cout << "Enter first player name = ";
    getline(cin, player1);
    cout << "Your symbol is X\n";
    cout << "Enter second player name = ";
    getline(cin, player2);
    cout << "Your symbol is O" << endl;

    printing_pattern(pattern);

    int current_player = 1;
    int x, y;
    // game begins
    while (true)
    {
        cout << "\nEnter the coordinates player " << current_player << " = ";
        cin >> x >> y;
        if (check(x, y, pattern))
        {
            if (current_player == 1)
            {
                pattern[x][y] = "X";
                current_player = 2;
            }
            else
            {
                pattern[x][y] = "O";
                current_player = 1;
            }
        }
        else
        {
            cout << "Invalid coordinators. Try again.\n";
            continue;
        }
        printing_pattern(pattern);
        if (win_lose(pattern) == "X")
        {
            cout << "\nThe winner is " << player1 << endl;
            break;
        }
        else if (win_lose(pattern) == "O")
        {
            cout << "\nThe winner is " << player2 << endl;
            break;
        }
        else
        {
            ;
        }

        if (draw_game(pattern))
        {
            cout << "\nThe game is draw" << endl;
            break;
        }
    }
    system("pause");
    return 0;
}