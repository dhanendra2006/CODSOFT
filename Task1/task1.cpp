#include <iostream>
#include <random>
#include <limits>

class GuessTheNumberGame {
private:
    int targetNumber;
    int attempts;

    int generateRandomNumber(int min, int max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(min, max);
        return dist(gen);
    }

    int getValidatedInput() {
        int input;
        while (true) {
            std::cin >> input;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Enter a number: ";
            } else {
                return input;
            }
        }
    }

public:
    GuessTheNumberGame(int min = 1, int max = 100)
        : attempts(0) {
        targetNumber = generateRandomNumber(min, max);
        std::cout << "Guess the number between " << min << " and " << max << "\n";
    }

    void play() {
        int guess;
        do {
            std::cout << "Enter your guess: ";
            guess = getValidatedInput();
            attempts++;

            if (guess > targetNumber) {
                std::cout << "Too high!\n";
            } else if (guess < targetNumber) {
                std::cout << "Too low!\n";
            } else {
                std::cout << "🎉 Correct! You guessed it in "
                          << attempts << " attempts.\n";
            }
        } while (guess != targetNumber);
    }
};

int main() {
    GuessTheNumberGame game;
    game.play();
    return 0;
}
