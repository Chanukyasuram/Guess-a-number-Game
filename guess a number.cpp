#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

// A global leaderboard map to keep track of player's scores
map<string, int> leaderboard;

// Function to play the game
void playGame() {
    string name;
    cout << "Enter your Name: ";
    cin >> name;

    srand(time(0)); // Initialize random seed to ensure different random number each time
    int ranNum = rand() % 100 + 1; // Generate a random number between 1 and 100

    // Display game welcome message
    cout << "┌───────────────────────────────────────────┐" << endl;
    cout << "│                                           │" << endl;
    cout << "│          Let's Play Guess a Number...     │" << endl;
    cout << "│                                           │" << endl;
    cout << "└───────────────────────────────────────────┘" << endl;

    bool win = false; // Variable to track if the player has won
    const int trials = 6; // Maximum number of attempts allowed
    int guess; // Variable to store the player's guess
    int attempts = 0; // Counter for the number of attempts

    // Game loop
    while (!win && attempts != trials) {
        cout << "Guess a Number (1 to 100), Let's see your Luck: ";
        cin >> guess;
        attempts++; // Increment the attempt counter

        if (guess == ranNum) {
            // If the player guesses the number correctly
            cout << "Congratulations! You guessed the number in " << attempts << " tries." << endl;
            win = true;

            // Update the leaderboard
            if (leaderboard.find(name) == leaderboard.end()) {
                leaderboard[name] = 1; // If player is new, add to leaderboard
            } else {
                leaderboard[name]++; // If player already exists, increment score
            }
        } else if (guess < ranNum) {
            // If the guess is lower than the random number
            int diff = ranNum - guess;
            if (diff <= 10) {
                cout << "Too low but very close!" << endl;
            } else if (diff <= 20) {
                cout << "Low, but close. Guess again." << endl;
            } else {
                cout << "Too low and too far. Guess again." << endl;
            }
        } else {
            // If the guess is higher than the random number
            int diff = guess - ranNum;
            if (diff <= 10) {
                cout << "Too high but very close!" << endl;
            } else if (diff <= 20) {
                cout << "High, but close. Guess again." << endl;
            } else {
                cout << "Too high and too far. Guess again." << endl;
            }
        }

        // Provide additional hints after 3 failed attempts
        if (attempts == 3 && !win) {
            if (ranNum % 2 == 0) {
                cout << "Hint: The number is even." << endl;
            } else {
                cout << "Hint: The number is odd." << endl;
            }
        }

        // Provide another hint after 5 failed attempts
        if (attempts == 5 && !win) {
            if (ranNum <= 50) {
                cout << "Hint: The number is less than or equal to 50." << endl;
            } else {
                cout << "Hint: The number is greater than 50." << endl;
            }
        }
    }

    // If player did not guess the number in given attempts
    if (!win) {
        cout << "You failed the game. The correct number was " << ranNum << "." << endl;
    }
}

// Function to display the leaderboard
void displayLeaderBoard() {
    cout << "\nHere is the LeaderBoard:\n";
    cout << "_____________________\n";
    cout << "Name\tScore\n";
    cout << "_____________________\n";
    for (const auto& entry : leaderboard) {
        cout << entry.first << "\t" << entry.second << endl;
    }
    cout << "_____________________\n";
}

// Function to display the main menu and handle user choices
void displayMenu() {
    int choice;
    do {
        cout << "\nOptions:\n"
             << "1. Play\n"
             << "2. View LeaderBoard\n"
             << "3. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                playGame(); // Start the game
                break;
            case 2:
                displayLeaderBoard(); // Show the leaderboard
                break;
            case 3:
                cout << "Thanks for playing. Goodbye!\n"; // Exit the program
                break;
            default:
                cout << "Please enter a valid choice.\n"; // Handle invalid choices
                break;
        }
    } while (choice != 3);
}

// Main function
int main() {
    displayMenu(); // Display the main menu
    return 0;
}
