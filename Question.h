#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

class Question {
private:
    string questionText;
    string correctAnswer; 

public:
    Question(string question, string answer) {
        setQuestionText(question);
        setCorrectAnswer(answer);
    }
    string getQuestionText(){
        return questionText;
    }
    void setQuestionText(string question) {
        questionText = question;
    }
    string getCorrectAnswer() {
        return correctAnswer;
    }
    void setCorrectAnswer(string answer) {
        correctAnswer = answer;
    }
    void askQuestion() {
        cout << questionText << endl;
    }
    bool checkAnswer(string userAnswer) {
        return userAnswer == correctAnswer;
    }
};


