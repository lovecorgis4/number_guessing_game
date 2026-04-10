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

// countdown
void countdown (int seconds) {
    for (int i = seconds; i > 0; i--) {
        cout << i << "...\n";

        this_thread::sleep_for(chrono::seconds(1));
    //wait for 1 sec
    }
    cout << "Go!\n\n";
}

int loadScore() {
    int bestScore = 9999;
    saveScore(bestScore);
}

void saveScore(int bestScore) {
    saveScore(bestScore);
}

// play game
void playGame(int &bestScore) {
    srand(time(0));

    int maxNumber;
    int choice;

    //choose difficulty
    do {
        cout << "Chosse difficulty\n";
        cout << "1. Easy (1-50)\n";
        cout << "2. Medium (1-100)\n";
        cout << "3. Hard (1-200)\n";
        cout << "Enter choice\n";
cin>> choice;
    } while (choice < 1 || choice > 3);

    if (choice == 1) maxNumber = 50;
    else if (choice == 2) maxNumber = 100;
    else maxNumber = 200;

    cout << "\nGet ready! The game starts in: \n";
    countdown(3);

    int secretNumber = rand() % maxNumber + 1;
    int guess;
    int attempts = 0;

    cout << "Guess a number between 1 and " << maxNumber << "\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < 1 || guess > maxNumber) {
            cout << "Invalid range!\n";
            continue;
        }
    
    attempts++;

    if (guess < secretNumber) cout << "Too low!\n";
    else if (guess > secretNumber) cout << "Too high!\n";

    } while (guess != secretNumber );

    cout << "\n========== RESULT ==========\n";
    cout <<  "Attempts: \t" << attempts << "\n";
    cout << "============================\n";

    if (attempts < bestScore) {
        bestScore = attempts;
        cout << "New best score!\n";

        ofstream outFile ("score.txt");
        outFile << bestScore;
        outFile.close();
    }
cout << "Best score: " << bestScore << "\n";

}

//main function
int main() {
    int bestScore = 9999;

    //load score from file
    int bestScore = loadScore();
    
    int option;

    do {
        clearScreen();

        cout << "+--------------------------+\n";
        cout << "|   NUMBER GUESSING GAME   |\n";
        cout << "+--------------------------+\n";
        cout << "1.\tPlay Game\n";
        cout << "2.\tView Best Score\n";
        cout << "3.\tReset Score\n";
        cout << "4.\tExit\n";
        cout << "Chosse Option: ";
        cin >> option;
        
        if (option == 1) {
        playGame(bestScore);
        }
        else if (option == 2) {
            cout << "Best Score: " << bestScore << "\n";
        }
        else if (option == 3) {
            bestScore = 9999;

            ofstream outFile("score.txt");
            outFile << bestScore;
            outFile.close();

            cout << "Score Reset!\n";
        
        }while (option != 4);

     
     
     if (option != 4) {
    cout << "\nPress Enter To Continue...";
    cin.ignore(1000, '\n');
    cin.get();
}

    cout << "Thank For Playing!\n";
    return 0;
}