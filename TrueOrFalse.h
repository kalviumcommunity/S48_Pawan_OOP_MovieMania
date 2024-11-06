#include "Question.h"

class TrueOrFalse : public Question {
private:
    bool correctAnswer;

public:
    TrueOrFalse(const string& text, bool answer) 
        : Question(text), correctAnswer(answer) {}

    void askQuestion() const override {
        cout << questionText << " (true/false)" << endl;
    }

    bool checkAnswer(const string& userAnswer) const override {
        string answer = (correctAnswer ? "true" : "false");
        return userAnswer == answer;
    }
};
