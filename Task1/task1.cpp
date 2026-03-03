#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int randomNumber, guess;

    // Seed the random number generator
    srand(time(0));

    // Generate random number between 1 and 100
    randomNumber = rand() % 100 + 1;

    cout << "Guess the number between 1 and 100" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        }
        else if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        }
        else {
            cout << "🎉 Congratulations! You guessed the correct number." << endl;
        }
    } while (guess != randomNumber);

    return 0;
}


    }
    return 0;
}
