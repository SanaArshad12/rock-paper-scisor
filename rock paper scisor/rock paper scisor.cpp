#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <string>   // For string handling

using namespace std;

// ANSI escape codes for text colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// Function to convert choice number to string
string getChoiceName(int choice) {
    switch (choice) {
    case 1: return "Rock";
    case 2: return "Paper";
    case 3: return "Scissors";
    case 4: return "Lizard";
    case 5: return "Spock";
    default: return "Invalid";
    }
}

// Function to determine the winner
int determineWinner(int userChoice, int computerChoice) {
    // Rules for Rock, Paper, Scissors, Lizard, Spock
    if (userChoice == computerChoice) {
        return 0; // Tie
    }
    switch (userChoice) {
    case 1: // Rock
        if (computerChoice == 3 || computerChoice == 4) return 1; // Rock crushes Scissors and Lizard
        break;
    case 2: // Paper
        if (computerChoice == 1 || computerChoice == 5) return 1; // Paper covers Rock and disproves Spock
        break;
    case 3: // Scissors
        if (computerChoice == 2 || computerChoice == 4) return 1; // Scissors cut Paper and decapitate Lizard
        break;
    case 4: // Lizard
        if (computerChoice == 2 || computerChoice == 5) return 1; // Lizard eats Paper and poisons Spock
        break;
    case 5: // Spock
        if (computerChoice == 1 || computerChoice == 3) return 1; // Spock vaporizes Rock and smashes Scissors
        break;
    }
    return -1; // Computer wins
}

int main() {
    int userChoice;
    int computerChoice;
    int userScore = 0;
    int computerScore = 0;
    int rounds = 0;
    int maxWins;
    char playAgain;

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    cout << GREEN << "Welcome to Rock, Paper, Scissors, Lizard, Spock!" << RESET << endl;
    cout << "How many wins to declare the overall winner? (e.g., 3): ";
    cin >> maxWins;

    do {
        rounds++;
        cout << CYAN << "\nRound " << rounds << RESET << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissors" << endl;
        cout << "4. Lizard" << endl;
        cout << "5. Spock" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> userChoice;

        // Validate user input
        if (userChoice < 1 || userChoice > 5) {
            cout << RED << "Invalid choice. Please choose a number between 1 and 5." << RESET << endl;
            continue;
        }

        // Generate computer's choice
        computerChoice = rand() % 5 + 1;

        // Display choices
        cout << BLUE << "You chose: " << getChoiceName(userChoice) << RESET << endl;
        cout << MAGENTA << "Computer chose: " << getChoiceName(computerChoice) << RESET << endl;

        // Determine the winner
        int result = determineWinner(userChoice, computerChoice);
        if (result == 0) {
            cout << YELLOW << "                                   It's a tie!" << RESET << endl;
        }
        else if (result == 1) {
            cout << GREEN << "                                    You win this round!" << RESET << endl;
            userScore++;
        }
        else {
            cout << RED << "                                      Computer wins this round!" << RESET << endl;
            computerScore++;
        }

        // Display scores
        cout << CYAN << "Score: You " << userScore << " - " << computerScore << " Computer" << RESET << endl;

        // Check if someone has won the series
        if (userScore >= maxWins || computerScore >= maxWins) {
            if (userScore > computerScore) {
                cout << "";
                cout << GREEN << "                  Congratulations! You won the series!" << RESET << endl;
            }
            else {
                cout << RED << "                    Computer won the series. Better luck next time!" << RESET << endl;
            }
            break;
        }

        // Ask if the user wants to play another round
        cout << "";
        cout << "Do you want to play another round? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << GREEN << "Thanks for playing! Final Score: You " << userScore << " - " << computerScore << " Computer" << RESET << endl;

    return 0;
}