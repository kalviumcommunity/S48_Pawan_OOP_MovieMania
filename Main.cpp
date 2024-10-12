#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "Question.h"
#include "Player.h"
#include "Watchlist.h"
#include "Recommendations.h"
using namespace std;

void loadGameData(int& totalPlayers, int& globalHighScore) {
    ifstream file("game_data.txt");
    if (file.is_open()) {
        file >> totalPlayers;
        file >> globalHighScore;
        file.close();
    } else {
        totalPlayers = 0;
        globalHighScore = 0;
    }
}

void saveGameData(int totalPlayers, int globalHighScore) {
    ofstream file("game_data.txt");
    if (file.is_open()) {
        file << totalPlayers << endl;
        file << globalHighScore << endl;
        file.close();
    } else {
        cerr << "Error: Unable to save game data!" << endl;
    }
}

int main() {

    loadGameData(Player::totalPlayers, Player::globalHighScore);

    int choice;
    string name;
    cout << "Enter your name: ";
    cin >> name;

    cout << "Welcome to Moviemania, " << name << "!" << endl;

    Watchlist* userWatchlist = new Watchlist;
    Recommendations* movieRecommendations = new Recommendations;
    Player* player = nullptr;

    do {
        cout << "\n--- Main Menu ---" << endl;
        cout << "1. Explore Movie Trivia" << endl;
        cout << "2. Play Quiz Game" << endl;
        cout << "3. Get Movie Recommendation" << endl;
        cout << "4. Manage Watchlist" << endl;
        cout << "5. View High Score" << endl;
        cout << "6. View Total Players" << endl;
        cout << "7. Exit" << endl;
        cout << "Please enter your choice (1, 2, 3, 4, 5, 6 or 7): ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Here's a fun movie fact for you!" << endl;
                //  functionality for random trivia here, will be added soon.
                break;

            case 2: {
                if (player) {
                    delete player;  
                }
                player = new Player(name);
                vector<Question> quizQuestions;

                quizQuestions.push_back(Question("Who directed 'Inception'?", "Christopher Nolan"));
                quizQuestions.push_back(Question("Which movie won the Oscar for Best Picture in 2020?", "Parasite"));
                quizQuestions.push_back(Question("Who played Iron Man in the Marvel Cinematic Universe?", "Robert Downey Jr."));
                quizQuestions.push_back(Question("Complete this Movie title, starring Morgan freeman and Tim robbins:  Shawshank ___________","Redemption"));
                quizQuestions.push_back(Question("What is the name of the famous movie character who says 'Why so serious'?","Joker"));
                // more questions to be added. Questions will be randomized.

                for (Question q : quizQuestions) {
                    q.askQuestion();
                    string userAnswer;
                    cout << "Your answer: "<<endl;
                    getline(cin, userAnswer);
                    if (q.checkAnswer(userAnswer)) {
                        cout << "Correct!" << endl;
                        player->addPoints(10);
                    } else {
                        cout << "Incorrect. The correct answer was: " << q.correctAnswer << "youentered"<<userAnswer<<endl;
                    }
                }

                cout << "Quiz Over! Your final score is: " << player->getScore() << endl;
                player->giveFeedback(); 
                break;
            }

            case 3:
                movieRecommendations->showRecommendations();
                break;

            case 4: {
                int watchlistChoice;
                cout << "\n--- Watchlist Menu ---" << endl;
                cout << "1. Add Movie to Watchlist" << endl;
                cout << "2. View Watchlist" << endl;
                cout << "3. Remove Movie from Watchlist" << endl;
                cout << "Enter your choice: ";
                cin >> watchlistChoice;
                cin.ignore(); 

                if (watchlistChoice == 1) {
                    string movieToAdd;
                    cout << "Enter the name of the movie to add: ";
                    getline(cin, movieToAdd);
                    userWatchlist->addMovie(movieToAdd);
                } else if (watchlistChoice == 2) {
                    userWatchlist->viewWatchlist();
                } else if (watchlistChoice == 3) {
                    string movieToRemove;
                    cout << "Enter the name of the movie to remove: ";
                    getline(cin, movieToRemove);
                    userWatchlist->removeMovie(movieToRemove);
                } else {
                    cout << "Invalid choice!" << endl;
                }
                break;
            }
        
            case 5:
                cout << "Current high score across all games: " << Player::getGlobalHighScore() << endl;
                break;

            case 6:
                cout << "Total players who have played: " << Player::getTotalPlayers() << endl;
                break;

            case 7:
                cout << "Exiting Moviemania. Goodbye!" << endl;
                delete userWatchlist;
                delete movieRecommendations;
                if(player) {delete player;}
                break;

            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }

    } while (choice != 7);

    saveGameData(Player::totalPlayers, Player::globalHighScore);

    return 0;
}
