#include "Question.h"

class MCQ : public Question {
private:
    vector<string> options;
    string correctAnswer;

public:
    MCQ(const string& text, const vector<string>& options, const string& correctAnswer)
        : Question(text), options(options), correctAnswer(correctAnswer) {}

    void askQuestion() const override {
        cout << text << endl;
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << endl;
        }
    }

    bool checkAnswer(const string& userAnswer) const override {
        int answerIndex = stoi(userAnswer) - 1;
        return (answerIndex >= 0 && answerIndex < options.size() && 
                options[answerIndex] == correctAnswer);
    }

    string getCorrectAnswer() const override {
        return correctAnswer;
    }
};
