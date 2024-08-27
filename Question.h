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

    Question(string question,string Answer){
        questionText = question;
        correctAnswer = Answer;
    }

    void askQuestion() {
        cout << questionText << endl;
    }

    bool checkAnswer(string userAnswer) {
        return userAnswer == correctAnswer;
    }
};


