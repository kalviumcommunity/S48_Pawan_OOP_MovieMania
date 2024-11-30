#include "Question.h"

class FillInTheBlank : public Question {
private:
    string correctAnswer;

public:
    FillInTheBlank(const string& text, const string& answer) 
        : Question(text), correctAnswer(answer) {}

    void askQuestion() const override {
        cout << "Fill in the blank: " << text << endl;
    }

    bool checkAnswer(const string& userAnswer) const override {
        return userAnswer == correctAnswer;
    }

    string getCorrectAnswer() const override {
        return correctAnswer;
    }
};
