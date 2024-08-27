class Player {
public:
    string name;
    int score;

    Player(string n) {
        this->name = n;
        this->score = 0;
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
    }
};
