#include <iostream>

using namespace std;

char numbers[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char digit[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

//display tic tac toe
void display()
{
    cout << endl;
    cout << "  " << numbers[0] << "   |   " << numbers[1] << "   |   " << numbers[2] << endl;
    cout << "----------------------\n";
    cout << "  " << numbers[3] << "   |   " << numbers[4] << "   |   " << numbers[5] << endl;
    cout << "----------------------\n";
    cout << "  " << numbers[6] << "   |   " << numbers[7] << "   |   " << numbers[8] << endl;
    cout << "----------------------\n";
    cout << endl;
}

class Players
{
public:
    //input value turns to X or O
    void player(char &num, int value)
    {
        for (int i = 0; i < 9; i++)
        {
            if (num == numbers[i] && value == 1)
            {
                numbers[i] = 'X';
            }
            else if (num == numbers[i] && value == 2)
            {
                numbers[i] = 'O';
            }
        }
        display();
    }

    void check(int value)
    {
        if (numbers[value] == 'X')
        {
            cout << "==> Player 1 wins" << endl;
            exit(0);
        }
        else if (numbers[value] == 'O')
        {
            cout << "==> Player 2 wins" << endl;
            exit(0);
        }
    }

    // checks who won the game
    void win()
    {
        int x = 0;
        for (int i = 0; i < 9; i++)
        {
            //checks horizontal
            if (i == 0 || i == 3 || i == 6)
            {
                if (numbers[i] == numbers[i += 1] && numbers[i] == numbers[i += 1])
                {
                    check(i);
                }
            }
            if (i == 8)
            {
                break;
            }
            //checks vertical
            else if (i == 0 || i == 1 || i == 2)
            {
                if (numbers[i] == numbers[i += 3] && numbers[i] == numbers[i += 3])
                {
                    check(i);
                }
                else
                {
                    x++;
                    switch (x)
                    {
                    case 1:
                        i = 0;
                        break;
                    case 2:
                        i = 1;
                        break;
                    case 3:
                        break;
                    }
                }
            }
        }

        //checks diagonal right and left
        if (numbers[0] == numbers[4] && numbers[0] == numbers[8])
        {
            check(0);
        }
        else if (numbers[2] == numbers[4] && numbers[2] == numbers[6])
        {
            check(2);
        }
    }
};

int main()
{
    char number;
    Players player1;
    Players player2;

    cout << "\tTic Tac Toe" << endl;
    cout << "Player 1 (X)  -  Player 2 (O)" << endl;
    display();

    for (int n = 0; n < 5; n++)
    {
        for (int i = 1; i < 3; i++)
        {
            cout << "Player " << i << ", enter a number: ";
            cin >> number;
            for (int q = 0; q < 9; q++)
            {
                if (number != digit[q] && q == 8)
                {
                    cout << "Invalid value" << endl;
                    exit(0);
                }
                if (number == digit[q])
                {
                    break;
                }
            }
            if (i == 1)
            {
                player1.player(number, i);
                player1.win();
            }
            if (i == 1 && n == 4)
            {
                cout << "==> It's a tie." << endl;
                break;
            }
            else if (i == 2)
            {
                player2.player(number, i);
                player2.win();
            }
        }
    }

    return 0;
}