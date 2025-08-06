#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    // Seed random number generator using current time
    srand(time(0));

    // Generate a random number between 1 and 100
    int numberToGuess = rand() % 100 + 1;
    int guess;

    cout << "Guess the number (between 1 and 100):" << endl;

    // Loop until the user guesses correctly
    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else if (guess > numberToGuess) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number!" << endl;
        }

    } while (guess != numberToGuess);

    return 0;
}