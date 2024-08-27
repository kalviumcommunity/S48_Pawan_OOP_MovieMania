#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

class Question {
public:
    string questionText;
    string correctAnswer;

    Question(string questionText,string correctAnswer){
        this->questionText = questionText;
        this->correctAnswer = correctAnswer;
    }

    void askQuestion() {
        cout << questionText << endl;
    }

    bool checkAnswer(string userAnswer) {
        return userAnswer == correctAnswer;
    }
};


