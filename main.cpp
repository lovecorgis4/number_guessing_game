#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;

// Function to clear console screen
void clearScreen() {
#ifdef _WIN32
    system("cls");   // Windows
#else
    system("clear"); // Linux / Mac
#endif
}

// Countdown function
void countdown (int seconds) {
    for (int i = seconds; i > 0; i--) {
        cout << i << "...\n";

        this_thread::sleep_for(chrono::seconds(1));
    //wait for 1 sec
    }
    cout << "Go!\n\n";
}

int main() {
    // Load best score
    int bestScore = 9999;
    ifstream inFile("score.txt");
    if (inFile >> bestScore) {
        // score loaded successfully
    }
    inFile.close();

    char playAgain = 'y';

    while (playAgain == 'y') {
        clearScreen(); // clear screen at the start of each round

        srand(time(0));

        int maxNumber;
        int choice;

        // Difficulty selection with validation
        do {
            cout << "Choose difficulty:\n";
            cout << "1. Easy (1-50)\n";
            cout << "2. Medium (1-100)\n";
            cout << "3. Hard (1-200)\n";
            cout << "Enter choice (1-3): ";
            cin >> choice;
        } while (choice < 1 || choice > 3);
       
        if (choice == 1) maxNumber = 50;
        else if (choice == 2) maxNumber = 100;
        else maxNumber = 200;

 //after setting maxNumber based on difficulty
        cout << "\nGet ready! The agme starts in:\n";
        countdown(3); //shows 3, 2, 1, Go!

        int secretNumber = rand() % maxNumber + 1;
        int guess;
        int attempts = 0;

        cout << "\nI have selected a number between 1 and " << maxNumber << ". Can you guess it?\n";

        // Guessing loop with validation
        do {
            cout << "Enter your guess: ";
            cin >> guess;

            if (guess < 1 || guess > maxNumber) {
                cout << "Please enter a number between 1 and " << maxNumber << ".\n";
                continue; // skip counting invalid guesses
            }

            attempts++;

            if (guess < secretNumber) {
                cout << "Too low!\n";
            } else if (guess > secretNumber) {
                cout << "Too high!\n";
            } else {
                cout << "Correct! You guessed the number!\n";
            }

        } while (guess != secretNumber);

        cout << "It took you " << attempts << " attempts.\n";

        if (attempts < bestScore) {
            bestScore = attempts;
            cout << " New best score!\n";

            ofstream outFile("score.txt");
            outFile << bestScore;
            outFile.close();
        }

        cout << "Best score: " << bestScore << "\n";

        // Ask to play again
        cout << "Play again? (y/n): ";
        cin >> playAgain;
        playAgain = tolower(playAgain); // handle uppercase 'Y'
    }

    cout << "Thanks for playing!\n";
    return 0;
}