#include <iostream>
#include <cstdlib>   
#include <ctime>     

using namespace std;

int main()
{

    srand(time(0));

    
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    cout << "=====================================\n";
    cout << "     NUMBER GUESSING GAME\n";
    cout << "=====================================\n";
    cout << "I have chosen a number between 1 and 100.\n";
    cout << "Try to guess it!\n\n";

    // Loop until the correct guess
    do
    {
        cout << "Enter your guess: ";
        cin >> guess;

        attempts++;

        if (guess > secretNumber)
        {
            cout << "Too High! Try again.\n\n";
        }
        else if (guess < secretNumber)
        {
            cout << "Too Low! Try again.\n\n";
        }
        else
        {
            cout << "\nCongratulations! You guessed the number.\n";
            cout << "The number was: " << secretNumber << endl;
            cout << "Total Attempts: " << attempts << endl;
        }

    } while (guess != secretNumber);

    return 0;
}