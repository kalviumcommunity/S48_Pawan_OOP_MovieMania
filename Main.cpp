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
#include "MCQ.h"
#include "FillInTheBlank.h"
#include "TrueOrFalse.h"
#include "GameDataManager.h"
using namespace std;

int main() {
    GameDataManager gameDataManager("game_data.txt");

    gameDataManager.loadGameData(Player::totalPlayers, Player::globalHighScore);

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
                break;

            case 2: {
                if (player) {
                    delete player;  
                }
                player = new Player(name);

                vector<Question*> quizQuestions;

                quizQuestions.push_back(new MCQ("Who directed 'Inception'?", {"Steven Spielberg", "Christopher Nolan", "Quentin Tarantino"}, "Christopher Nolan"));
                quizQuestions.push_back(new FillInTheBlank("Complete this movie title: 'The Shawshank _________'", "Redemption"));
                quizQuestions.push_back(new TrueOrFalse("Is 'The Godfather' a movie directed by Francis Ford Coppola?", true));

                for (Question* q : quizQuestions) {
                    q->askQuestion();
                    string userAnswer;
                    cout << "Your answer: ";
                    getline(cin, userAnswer);
                    if (q->checkAnswer(userAnswer)) {
                        cout << "Correct!" << endl;
                        player->addPoints(10);
                    } else {
                        cout << "Incorrect. The correct answer was: " << q->getCorrectAnswer() << endl;
                    }
                }

                cout << "Quiz Over! Your final score is: " << player->getScore() << endl;
                player->giveFeedback();
                break;
            }

            case 3: {
                int recType;
                cout << "\nChoose recommendation type:" << endl;
                cout << "1. Genre-Based Recommendations" << endl;
                cout << "2. Trending Recommendations" << endl;
                cout << "Enter your choice: ";
                cin >> recType;
                cin.ignore();

                if (recType == 1) {
                    movieRecommendations->setStrategy(new GenreBasedRecommendations());
                } else if (recType == 2) {
                    movieRecommendations->setStrategy(new TrendingRecommendations());
                } else {
                    cout << "Invalid choice!" << endl;
                }

                movieRecommendations->showRecommendations();
                break;
            }

           case 4: {
                int watchlistChoice;
                cout << "\n--- Watchlist Menu ---" << endl;
                cout << "1. Add Single Movie to Watchlist" << endl;
                cout << "2. Add Multiple Movies to Watchlist" << endl;
                cout << "3. View Watchlist" << endl;
                cout << "4. Remove Movie from Watchlist" << endl;
                cout << "Enter your choice: ";
                cin >> watchlistChoice;
                cin.ignore();

                if (watchlistChoice == 1) {
                    string movieToAdd;
                    cout << "Enter the name of the movie to add: ";
                    getline(cin, movieToAdd);
                    userWatchlist->addMovie(movieToAdd);

                } else if (watchlistChoice == 2) {
                    vector<string> moviesToAdd;
                    string movie;
                    cout << "Enter movie names (type 'done' to finish): ";
                    while (true) {
                        getline(cin, movie);
                        if (movie == "done") break;
                        moviesToAdd.push_back(movie);
                    }
                    userWatchlist->addMovie(moviesToAdd);

                } else if (watchlistChoice == 3) {
                    userWatchlist->viewWatchlist();

                } else if (watchlistChoice == 4) {
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
                if (player) { delete player; }
                break;

            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }

    } while (choice != 7);

    gameDataManager.saveGameData(Player::totalPlayers, Player::globalHighScore);

    return 0;
}
