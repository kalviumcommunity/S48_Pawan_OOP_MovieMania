#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Question {
protected:
    string questionText;

public:
    Question(const string& text) : questionText(text) {}

    virtual void askQuestion() const {
        cout << questionText << endl;
    }

    virtual bool checkAnswer(const string& userAnswer) const = 0; // pure virtual function
};
