#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Player {

private:
    string name;
    int score;  

public:
    static int globalHighScore;
    static int totalPlayers;

    Player() {
        name = "Unknown";
        score = 0;
        totalPlayers++;
    }

    Player(string n) {
        setName(n);
        setScore(0);
        totalPlayers++;
    }

    ~Player() {
        cout << "Player " << name << " is being deleted." << endl;
    }

    string getName()  {
        return name;
    }

    void setName(string n) {
        name = n;
    }

    int getScore()  {
        return score;
    }

    void setScore(int s) {
        score = s;
    }

    void addPoints(int points) {
        score += points;
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

    static int getTotalPlayers() {
        return totalPlayers;
    }

    static int getGlobalHighScore() {
        return globalHighScore;
    }
    
};

int Player::globalHighScore = 0;
int Player::totalPlayers = 0;