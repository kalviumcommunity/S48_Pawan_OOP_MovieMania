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

    Player(string playerName) {
        name = playerName;
        score = 0;
    }

    void addPoints(int points) {
        score += points;
    }

    int getScore() {
        return score;
    }
};

