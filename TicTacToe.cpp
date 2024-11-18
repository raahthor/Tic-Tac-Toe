#include <bits/stdc++.h>
using namespace std;

void clearScreen()
{
    system("cls");
}
void displayBoard(char bd[3][3])
{
    clearScreen();
    cout << endl
         << "    Tic-Tac-Toe" << endl
         << endl;
    cout << "     " << bd[0][0] << " | " << bd[0][1] << " | " << bd[0][2] << endl;
    cout << "    ---+---+---" << endl;
    cout << "     " << bd[1][0] << " | " << bd[1][1] << " | " << bd[1][2] << endl;
    cout << "    ---+---+---" << endl;
    cout << "     " << bd[2][0] << " | " << bd[2][1] << " | " << bd[2][2] << endl
         << endl;
}
void player(char &cplyr)
{
    while (true)
    {
        cout << "Player 1, Choose 'X' or 'O' " << endl;
        cin >> cplyr;
        if (cplyr == 'X' || cplyr == 'x')
        {
            cplyr = 'X';
            cout << endl
                 << "Player 1 = X" << endl
                 << "Player 2 = O" << endl;
            cout << endl
                 << "Press Enter to start the game" << endl;
            cin.ignore();
            cin.get();
            break;
        }
        else if (cplyr == 'O' || cplyr == 'o')
        {
            cplyr = 'O';
            cout << endl
                 << "Player 1 = O" << endl
                 << "Player 2 = X" << endl;
            cout << endl
                 << "Press Enter to start the game" << endl;
            cin.ignore();
            cin.get();
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
            cout << endl
                 << "Press Enter to choose again" << endl;
            cin.ignore();
            cin.get();
        }
    }
}
char currentplayer(char &cplyr)
{
    return (cplyr == 'X') ? 'O' : 'X';
}
bool winOrDraw(char &cplyr, int cntmoves, char bd[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        // for rows and columns
        if ((bd[i][0] == cplyr && bd[i][1] == cplyr && bd[i][2] == cplyr) ||
            (bd[0][i] == cplyr && bd[1][i] == cplyr && bd[2][i] == cplyr))
        {
            cout << endl
                 << "Player [" << cplyr << "] won ! " << endl;
            return true;
        }
    }
    // for diagonals
    if ((bd[0][0] == cplyr && bd[1][1] == cplyr && bd[2][2] == cplyr) ||
        (bd[0][2] == cplyr && bd[1][1] == cplyr && bd[2][0] == cplyr))
    {
        cout << endl
             << "Player [" << cplyr << "] won!" << endl;
        return true;
    }
    // draw condition
    if (cntmoves >= 9)
    {
        cout << endl
             << "Game draws, Nobody won ! " << endl;
        return true;
    }
    return false;
}
void move(char &cplyr, char bd[3][3])
{
    set<int> validcheck;
    bool winner = false;
    int cntmoves = 0;
    while (!winner)
    {
        displayBoard(bd);
        int mv;
        cout << endl
             << "Player [" << cplyr << "] " << "choose 1-9 : ";
        cin >> mv;
        if (validcheck.find(mv) != validcheck.end())
        {
            cout << endl
                 << "Value already taken, Press Enter to try again" << endl;
            cin.ignore();
            cin.get();
            continue;
        }
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer value.\n";
            cin.ignore();

            continue;
        }
        switch (mv)
        {
        case 1:
            bd[0][0] = cplyr;
            cntmoves++;
            validcheck.insert(mv);
            break;
        case 2:
            bd[0][1] = cplyr;
            cntmoves++;
            validcheck.insert(mv);
            break;
        case 3:
            bd[0][2] = cplyr;
            cntmoves++;
            validcheck.insert(mv);
            break;
        case 4:
            bd[1][0] = cplyr;
            cntmoves++;
            validcheck.insert(mv);
            break;
        case 5:
            bd[1][1] = cplyr;
            cntmoves++;
            validcheck.insert(mv);
            break;
        case 6:
            bd[1][2] = cplyr;
            cntmoves++;
            validcheck.insert(mv);
            break;
        case 7:
            bd[2][0] = cplyr;
            cntmoves++;
            validcheck.insert(mv);
            break;
        case 8:
            bd[2][1] = cplyr;
            cntmoves++;
            validcheck.insert(mv);
            break;
        case 9:
            bd[2][2] = cplyr;
            cntmoves++;
            validcheck.insert(mv);
            break;
        default:
            cout << endl
                 << "Invalid Move, Press Enter to try again " << endl;
            cin.ignore();
            cin.get();
            continue;
        }
        winner = winOrDraw(cplyr, cntmoves, bd);
        cplyr = currentplayer(cplyr);
    }
}
int main()
{
    bool play = true;
    while (play)
    {
        char bd[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        char cplyr;
        player(cplyr);
        move(cplyr, bd);
        cout << endl
             << "Press Y to play again otherwise N : ";
        char ch;
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
            play = true;
        else
            play = false;
    }
    return 0;
}