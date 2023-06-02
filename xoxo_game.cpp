#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

char board[3][3]; // игровое поле
bool turn = true; // переменная для определения очередности хода

void InitBoard() // инициализация поля
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void DrawBoard() // отрисовка поля
{
    cout << "  1 2 3" << endl;
    cout << " -------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << "|";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << "|";
        }
        cout << endl;
        cout << " -------" << endl;
    }
}

bool CheckWin(char player) // проверка на победу
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player)
    {
        return true;
    }
    return false;
}

bool CheckTie() // проверка на ничью
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void PlayerTurn() // ход игрока
{
    cout << "Your turn (X)" << endl;
    int row, col;
    do
    {
        cout << "Enter row (1-3): ";
        cin >> row;
        cout << "Enter column (1-3): ";
        cin >> col;
    } while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ');

    board[row - 1][col - 1] = 'X';
    turn = !turn;
}

void ComputerTurn() // ход компьютера
{
    cout << "Computer's turn (O)" << endl;

    srand(time(NULL)); // инициализация генератора случайных чисел

    int row, col;
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');

    board[row][col] = 'O';
    turn = !turn;
}

int main()
{
    InitBoard(); // инициализация поля

    while (true)
    {
        system("cls"); // очистка консоли
        DrawBoard(); // отрисовка поля

        if (CheckWin('X')) // проверка на победу игрока
        {
            cout << "You won!" << endl;
            break;
        }
        else if (CheckWin('O')) // проверка на победу компьютера
        {
            cout << "Computer won!" << endl;
            break;
        }
        else if (CheckTie()) // проверка на ничью
        {
            cout << "Tie!" << endl;
            break;
        }

        if (turn) // очередь игрока
        {
            PlayerTurn();
        }
        else // очередь компьютера
        {
            ComputerTurn();
        }
    }

    cin.clear();
    cin.ignore(32767, '\n');
    cin.get();
    return 0;
}
