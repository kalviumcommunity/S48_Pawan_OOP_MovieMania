#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

class Player {
public:
    string name;
    int score;

    Player(string name) {
        this->name = name;
        this->score = 0;
    }

    void addPoints(int points) {
        score += points;
    }

    int getScore() {
        return score;
    }
};

