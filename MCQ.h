#include "Question.h"

class MCQ : public Question {
private:
    vector<string> options;
    string correctAnswer;

public:
    MCQ(string& text, vector<string>& options, string& answer) 
        : Question(text), options(options), correctAnswer(answer) {}

    void askQuestion() const override {
        cout << questionText << endl;
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << endl;
        }
    }

    bool checkAnswer(string& userAnswer) const override {
        return userAnswer == correctAnswer;
    }
};
