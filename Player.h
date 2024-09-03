#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Player {
public:
    string name;
    int score;

    static int globalHighScore;
    static int totalPlayers;

    Player(string n) {
        this->name = n;
        this->score = 0;
        totalPlayers++;
    }

    void addPoints(int points) {
        score += points;
    }

    int getScore() {
        return score;
    }

    void giveFeedback() {
        if (score >= 30) {
            cout << "Excellent job, " << name << "! You're a movie buff!" << endl;
        } else if (score >= 10) {
            cout << "Good effort, " << name << "! Keep watching more movies!" << endl;
        } else {
            cout << "It looks like you need to brush up on your movie knowledge, " << name << "!" << endl;
        }

        if (score > globalHighScore) {
            globalHighScore = score;
            cout << "Congratulations! You set a new high score!" << endl;
        }
    }
};

int Player::globalHighScore = 0;
int Player::totalPlayers = 0;