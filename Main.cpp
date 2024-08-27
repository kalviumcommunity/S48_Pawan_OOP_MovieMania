#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include "Question.h"
#include "Player.h"
#include "Watchlist.h"
using namespace std;

int main() {
    int choice;
    string Name;
    cout<<"Enter your name:"<<endl;
    cin>>Name;

    cout << "Welcome to Moviemania! "<< Name << endl;
    cout << "1. Explore Movie Trivia" << endl;
    cout << "2. Play Quiz Game" << endl;
    cout << "3. Get Movie Recommendation" << endl;
    cout << "4. Manage Watchlist" << endl;
    cout << "Please enter your choice (1, 2, 3 or 4): ";
    cin >> choice;

        if (choice == 2) {
        Player player(Name);
        vector<Question> quizQuestions;  

        quizQuestions.push_back(Question("Who directed 'Inception'?", "Christopher Nolan"));
        quizQuestions.push_back(Question("Which movie won the Oscar for Best Picture in 2020?", "Parasite"));
        quizQuestions.push_back(Question("Who played Iron Man in the Marvel Cinematic Universe?", "Robert Downey Jr."));

        for (Question q : quizQuestions) {
            q.askQuestion();
            string userAnswer;
            cout << "Your answer: ";
            cin.ignore(); 
            getline(cin, userAnswer);

            if (q.checkAnswer(userAnswer)) {
                cout << "Correct!" << endl;
                player.addPoints(10);  
            } else {
                cout << "Incorrect. The correct answer was: " << q.correctAnswer << endl;
            }
        }

        cout << "Quiz Over! Your final score is: " << player.getScore() << endl;

    }
    return 0;
}
