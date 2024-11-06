#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

class Question {
protected:
    string questionText;

public:
    Question(string text) : questionText(text) {}

    virtual void askQuestion() const {
        cout << questionText << endl;
    }

    virtual bool checkAnswer(string userAnswer) const = 0;
};


