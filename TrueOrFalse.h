#include "Question.h"

class TrueOrFalse : public Question {
private:
    bool correctAnswer;

public:
    TrueOrFalse(const string& text, bool answer) 
        : Question(text), correctAnswer(answer) {}

    void askQuestion() const override {
        cout << text << " (True/False)" << endl;
    }

    bool checkAnswer(const string& userAnswer) const override {
        string normalizedAnswer = userAnswer;
        transform(normalizedAnswer.begin(), normalizedAnswer.end(), normalizedAnswer.begin(), ::tolower);
        return (normalizedAnswer == "true" && correctAnswer) || 
               (normalizedAnswer == "false" && !correctAnswer);
    }

    string getCorrectAnswer() const override {
        return correctAnswer ? "True" : "False";
    }
};
