#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

class Question {
protected:
    string text;

public:
    Question(const string& questionText) : text(questionText) {}
    virtual void askQuestion() const = 0;
    virtual bool checkAnswer(const string& userAnswer) const = 0;
    virtual string getCorrectAnswer() const = 0;
    virtual ~Question() = default;
};
