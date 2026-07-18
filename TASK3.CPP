#include <iostream>
using namespace std;


void displayBoard(char board[3][3])
{
    cout << "\n";
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j] << " ";
            if(j < 2)
                cout << "|";
        }
        cout << endl;
        if(i < 2)
            cout << "---|---|---" << endl;
    }
    cout << endl;
}


bool checkWinner(char board[3][3], char player)
{

    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == player &&
           board[i][1] == player &&
           board[i][2] == player)
            return true;
    }

    
    for(int j = 0; j < 3; j++)
    {
        if(board[0][j] == player &&
           board[1][j] == player &&
           board[2][j] == player)
            return true;
    }

    
    if(board[0][0] == player &&
       board[1][1] == player &&
       board[2][2] == player)
        return true;

    if(board[0][2] == player &&
       board[1][1] == player &&
       board[2][0] == player)
        return true;

    return false;
}

int main()
{
    char board[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };

    char player = 'X';
    int choice;
    int row, col;
    int moves = 0;

    while(true)
    {
        displayBoard(board);

        cout << "Player " << player << ", enter position (1-9): ";
        cin >> choice;

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        
        if(choice < 1 || choice > 9 ||
           board[row][col] == 'X' ||
           board[row][col] == 'O')
        {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        board[row][col] = player;
        moves++;

        
        if(checkWinner(board, player))
        {
            displayBoard(board);
            cout << "🎉 Player " << player << " Wins!\n";
            break;
        }

        
        if(moves == 9)
        {
            displayBoard(board);
            cout << "Game Draw!\n";
            break;
        }

        // Change player
        if(player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}