#include "Question.h"

class FillInTheBlank : public Question {
private:
    string correctAnswer;

public:
    FillInTheBlank(const string& text, const string& answer) 
        : Question(text), correctAnswer(answer) {}

    bool checkAnswer(const string& userAnswer) const override {
        return userAnswer == correctAnswer;
    }
};
